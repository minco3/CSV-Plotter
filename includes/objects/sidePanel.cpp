#include "sidePanel.h"

sidePanelObj::sidePanelObj() {

}

sidePanelObj::sidePanelObj(sf::FloatRect _view) {
    view.setViewport(_view); //sf::FloatRect(1-SIDEPANEL_WIDTH,0,SIDEPANEL_WIDTH,1));
}

void sidePanelObj::draw(sf::RenderWindow& window) {
    window.setView(view);
    view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH*SIDEPANEL_WIDTH, SCREEN_HEIGHT));

    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].draw(window);
    }
}

void sidePanelObj::addEntry(const sf::Text& entry) {
    expressionList.emplace_back(entry);
    update();
}

void sidePanelObj::resize(const sf::Vector2f& size) {
    view.reset(sf::FloatRect(0,0,size.x*view.getViewport().width, size.y));
}

void sidePanelObj::update() {
    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].setPosition(sf::Vector2f(0,view.getSize().y/expressionList.size()*i));
    }
}

sf::FloatRect sidePanelObj::getView() {
    return view.getViewport();
}

void sidePanelObj::setView(sf::FloatRect _view) {
    view.reset(_view);
    update();
}