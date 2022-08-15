#include "hoverableText.h"

hoverableText::hoverableText(sf::Text _text) {
    text = _text;
    
    highlight.setPosition(sf::Vector2f(text.getGlobalBounds().left-5, text.getGlobalBounds().top-5));
    highlight.setSize(sf::Vector2f(text.getGlobalBounds().width+15, text.getGlobalBounds().height+10));
    highlight.setFillColor(sf::Color(0,0,0,0));
    hovering=false;
    std::cout << static_cast<std::string>(text.getString()) << " " << text.getPosition().x << ", " << text.getPosition().y << std::endl;
}

void hoverableText::draw(sf::RenderWindow& window) {
    if (hovering) {
        highlight.setPosition(sf::Vector2f(text.getGlobalBounds().left-5, text.getGlobalBounds().top-5));
        highlight.setSize(sf::Vector2f(text.getGlobalBounds().width+15, text.getGlobalBounds().height+10));

        sf::Color highlightColor = sf::Color(50,50,50,highlight.getFillColor().a<100 ? highlight.getFillColor().a+alphaChange : highlight.getFillColor().a); // turnary used to darken highlight

        highlight.setFillColor(highlightColor);
        window.draw(highlight);
    } else {
        highlight.setFillColor(sf::Color(50,50,50,0));
    }
    window.draw(text);
}