#include "timeline.h"

timelineObj::timelineObj() {
    view.setViewport(sf::FloatRect(0, GRAPH_COUNT/(GRAPH_COUNT+1.f), GRAPH_WIDTH, 1/(GRAPH_COUNT+1.f)));
    background.setFillColor(graphColor);
    background.setSize(view.getSize());
}

timelineObj::timelineObj(sf::FloatRect _view) {
    view.setViewport(_view);
    view.reset(sf::FloatRect(_view.top,_view.left,SCREEN_WIDTH*_view.width,SCREEN_HEIGHT*_view.height));
    background.setSize(view.getSize());
    background.setFillColor(graphColor);
}

void timelineObj::draw(sf::RenderWindow& window) {
    window.setView(view);

    window.draw(background);

    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].draw(window);
    }
}

void timelineObj::addEntry(const sf::Text& entry) {
    expressionList.emplace_back(entry);
    update();
}

void timelineObj::resize(const sf::Vector2f& size) {
    view.reset(sf::FloatRect(0,0,size.x*view.getViewport().width, size.y));
}

void timelineObj::update() {
    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].setPosition(sf::Vector2f(view.getSize().x/expressionList.size()*i, view.getSize().y*.85f));
        expressionList[i].setRotation(-30);
    }
    background.setSize(view.getSize());
}

sf::FloatRect timelineObj::getView() {
    return view.getViewport();
}

void timelineObj::setView(const sf::FloatRect& _view) {
    view.reset(_view);
    update();
}