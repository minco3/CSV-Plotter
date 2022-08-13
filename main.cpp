#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "includes/csvParser/csvParser.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;


int main() {

    std::vector<std::vector<std::string>> data = csvParse(std::string("resources/sat_realtime_telemetry.csv"));

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                        "Proportion Game"
                        );

    while(window.isOpen()) {
        
    }
}
