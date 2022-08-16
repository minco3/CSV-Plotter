#include "sidePanel.h"

sidePanelObj::sidePanelObj() {

}

sidePanelObj::sidePanelObj(sf::FloatRect _view) {

    view.reset(sf::FloatRect(0,0,SCREEN_WIDTH*SIDEPANEL_WIDTH, SCREEN_HEIGHT));
    view.setViewport(sf::FloatRect(0,0,SCREEN_WIDTH*SIDEPANEL_WIDTH, SCREEN_HEIGHT));
}

void sidePanelObj::draw(sf::RenderWindow& window) {
    window.setView(view);
    //view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH*SIDEPANEL_WIDTH, SCREEN_HEIGHT));

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
        expressionList[i].setPosition(sf::Vector2f(0,view.getSize().y/(expressionList.size()+1)*i));
    }
}

sf::FloatRect sidePanelObj::getView() {
    return view.getViewport();
}

void sidePanelObj::setView(const sf::FloatRect& _view) {
    view.reset(_view);
    update();
}