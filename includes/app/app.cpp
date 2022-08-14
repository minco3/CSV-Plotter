#include "app.h"

app::app() {
    //load shared font
    if(!font.loadFromFile(fontPath)) {
        throw ("font not found");
    }
}

void app::loadCSV(const std::string& path) {
    //load and parse data
    //TODO: add way to select file from app
    //TODO: make loading csv happen async
    //TODO: make loading csv update graph
    data = csvParse(path);

    //import csv data into graph 

    //add names of columns to side panel
    sidePanel.clear();
    for (int i=1; i<data[0].size(); i++) {
        sidePanel.addEntry(sf::Text(data[0][i], font));
    }

    for (int i=0; i<graphs.size(); i++) {
        graphs[i].update();
    }
}


void app::run() {

    //create window object using default parameters
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                        "CSV Grapher"
                        );

    loadCSV("resources/sat_realtime_telemetry.csv");

    graphs.emplace_back(data[1]);

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
                case sf::Event::MouseButtonPressed:
                    std::cout << event.mouseButton.x << " " << event.mouseButton.y << '\n'; 
                    //update();
                break;
            }
        }

        //clear the frame
        window.clear(graphColor);

        for (int i=0; i<graphs.size(); i++) {
            //draw lines on graphs
            graphs[i].draw(window);
        }

        //display frame
        window.display();
    }
}