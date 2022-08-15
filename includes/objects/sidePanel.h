#ifndef SIDE_PANEL_H
#define SIDE_PANEL_H

#include <cassert>
#include <sstream>
#include <Vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "hoverableText.h"
#include "../constants/windowConstants.h"
#include "../random/random.h"

class sidePanelObj {


    public:
    sidePanelObj();
    sidePanelObj(sf::FloatRect _view);

    void draw(sf::RenderWindow& window);
    void addEntry(const sf::Text& entry);
    void resize(const sf::Vector2f& size);

    void clear() {expressionList.clear();} // clears the expression list

    void update(); //update position of text

    sf::FloatRect getView(); // return viewport of view
    void setView(sf::FloatRect _view); //resets view

    std::vector<hoverableText> expressionList;
    sf::View view;
};

#endif //SIDE_PANEL_H