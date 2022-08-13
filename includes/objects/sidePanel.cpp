#include "sidePanel.h"

sidePanelObj::sidePanelObj() {
    view.reset(sf::FloatRect(0, 0, SCREEN_WIDTH*(1-GRAPH_WIDTH_RATIO), SCREEN_HEIGHT));
    view.setViewport(sf::FloatRect(GRAPH_WIDTH_RATIO,0,1-GRAPH_WIDTH_RATIO,1));
}

void sidePanelObj::draw(sf::RenderWindow& window) {
    window.setView(view);
    window.clear(sidePanelColor);
    for (int i=0; i<expressionList.size(); i++) {
        expressionList[i].draw(window);
    }
}

void sidePanelObj::addEntry(const sf::Text& entry) {
    expressionList.emplace_back(entry);
}

void sidePanelObj::resize(const sf::Vector2f& size) {
    view.reset(sf::FloatRect(0,0,size.x*view.getViewport().width, size.y));
}