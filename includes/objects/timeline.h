#ifndef TIMELINE_H
#define TIMELINE_H

#include <cassert>
#include <sstream>
#include <Vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "hoverableText.h"
#include "../constants/windowConstants.h"
#include "../random/random.h"

class timelineObj {


    public:
    timelineObj();
    timelineObj(sf::FloatRect _view);

    void draw(sf::RenderWindow& window);
    void addEntry(const sf::Text& entry);
    void resize(const sf::Vector2f& size);

    void clear() {expressionList.clear();} // clears the expression list

    void update(); //update position of text

    sf::FloatRect getView(); // return viewport of view
    void setView(const sf::FloatRect& _view); //resets view

    std::vector<hoverableText> expressionList;
    sf::View view;
};

#endif // TIMELINE_h