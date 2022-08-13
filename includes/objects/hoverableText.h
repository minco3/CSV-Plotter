#ifndef HOVERABLE_TEXT_H
#define HOVERABLE_TEXT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

#include "../constants/windowConstants.h"

const int alphaChange = 4; // amount highlight will darken by each frame; 


class hoverableText { //simple class used for pairing a text object with a background generated around the text which can darken when hovered
    public:
    /*
    \brief simple constructor
    \param text Text to put inside hoverableText
    */
    hoverableText(sf::Text text);

    void move(const float& x, const float& y) {_text.move(x,y); _highlight.move(x,y);};

    /*
    \brief function used to draw the hoverableText object and calculate correct alpha for highlight
    \param window RenderWindow to draw to
    */
    void draw(sf::RenderWindow& window);

    bool hovering; // true if mouse is on the text

    sf::Text _text;
    sf::RectangleShape _highlight;
};

#endif //HOVERABLE_TEXT_H