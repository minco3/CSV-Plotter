#include "graph.h"

graphObj::graphObj() {
    //load shared font
    if(!font.loadFromFile(fontPath)) {
        throw ("font not found");
    }
}

void graphObj::draw(sf::RenderWindow& window) {

}

void graphObj::loadCSV(const std::string& path) {
    //load and parse data
    //TODO: add way to select file from app
    //TODO: make loading csv happen async
    //TODO: make loading csv update graph
    data = csvParse(path);

    //import csv data into graph
    sidePanel.clear();
    for (int i=1; i<data[0].size(); i++) {
        sidePanel.addEntry(sf::Text(data[0][i], font));
    }

    update();
}

void graphObj::update() {
    //calculate where lines go
}

void graphObj::run() {

    //create window object using default parameters
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                        "CSV Grapher"
                        );

    //main loop
    while(window.isOpen()) {

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                break;
            }
        }

        //clear the frame
        window.clear();

        //display frame
        window.display();
    }
}