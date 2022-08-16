#include "timeline.h"

timelineObj::timelineObj() {

}

timelineObj::timelineObj(sf::FloatRect _view) {
    view.setViewport(_view); //sf::FloatRect(1-SIDEPANEL_WIDTH,0,SIDEPANEL_WIDTH,1));
}

void timelineObj::draw(sf::RenderWindow& window) {
    window.setView(view);
    view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH*SIDEPANEL_WIDTH, SCREEN_HEIGHT));

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
        expressionList[i].setPosition(sf::Vector2f(0,view.getSize().y/expressionList.size()*i));
    }
}

sf::FloatRect timelineObj::getView() {
    return view.getViewport();
}

void timelineObj::setView(const sf::FloatRect& _view) {
    view.reset(_view);
    update();
}