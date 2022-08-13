#include "hoverableText.h"

hoverableText::hoverableText(sf::Text text) {
    _text = text;
    
    _highlight.setPosition(sf::Vector2f(text.getGlobalBounds().left-5, text.getGlobalBounds().top-5));
    _highlight.setSize(sf::Vector2f(text.getGlobalBounds().width+15, text.getGlobalBounds().height+10));
    _highlight.setFillColor(sf::Color(0,0,0,0));
    hovering=false;
    std::cout << static_cast<std::string>(text.getString()) << " " << text.getPosition().x << ", " << text.getPosition().y << std::endl;
}

void hoverableText::draw(sf::RenderWindow& window) {
    if (hovering) {
        _highlight.setPosition(sf::Vector2f(_text.getGlobalBounds().left-5, _text.getGlobalBounds().top-5));
        _highlight.setSize(sf::Vector2f(_text.getGlobalBounds().width+15, _text.getGlobalBounds().height+10));

        sf::Color highlightColor = sf::Color(50,50,50,_highlight.getFillColor().a<100 ? _highlight.getFillColor().a+alphaChange : _highlight.getFillColor().a); // turnary used to darken highlight

        _highlight.setFillColor(highlightColor);
        window.draw(_highlight);
    } else {
        _highlight.setFillColor(sf::Color(50,50,50,0));
    }
    window.draw(_text);
}