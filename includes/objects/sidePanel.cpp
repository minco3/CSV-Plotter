#include "sidePanel.h"

sidePanelObj::sidePanelObj() {
    view.setViewport(sf::FloatRect(1.f-SIDEPANEL_WIDTH,0,SIDEPANEL_WIDTH,1));
    background.setFillColor(graphColor);
    background.setSize(view.getSize());
}

sidePanelObj::sidePanelObj(sf::FloatRect _view) {
    view.setViewport(_view);
    view.reset(sf::FloatRect(_view.top,_view.left,SCREEN_WIDTH*_view.width,SCREEN_HEIGHT*_view.height));
    background.setFillColor(graphColor);
    background.setSize(view.getSize());
}

void sidePanelObj::draw(sf::RenderWindow& window) {
    window.setView(view);
    window.draw(background);

    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].draw(window);
    }
}

void sidePanelObj::addEntry(const sf::Text& entry) {
    expressionList.emplace_back(entry);
    update();
}

void sidePanelObj::update() {
    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].setPosition(sf::Vector2f(0,view.getSize().y/(expressionList.size()+1)*i));
    }
    background.setSize(view.getSize());
}

sf::FloatRect sidePanelObj::getView() {
    return view.getViewport();
}

void sidePanelObj::setView(const sf::FloatRect& _view) {
    view.reset(_view);
    update();
}