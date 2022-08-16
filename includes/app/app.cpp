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



    for (int i=0; i<graphs.size(); i++) {
        graphs[i].update();
    }
}


void app::run() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;

    //create window object using default parameters
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                        "CSV Grapher",
                        sf::Style::Default,
                        settings // antialiasing
                        );

    loadCSV("resources/sat_realtime_telemetry.csv");


    for (int i=0; i<GRAPH_COUNT&&i<data.size()-1; i++) {

        //add graphs
        graphs.emplace_back(data[i+1], sf::FloatRect(0,1.f/(GRAPH_COUNT+1)*i,1-SIDEPANEL_WIDTH,(1.f-DIVIDER_WIDTH*(GRAPH_COUNT+1))/(GRAPH_COUNT+1)), font);

        //add names of columns to side panel
        sidePanel.addEntry(sf::Text(data[i+1][0], font, 18));
    }

    sidePanel.view.setViewport(sf::FloatRect(1.f-SIDEPANEL_WIDTH,0.f,1.f,1.f));

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
                case sf::Event::Resized:
                    // update the view to the new size of the window
                    window.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
                    for(int i=0; i<graphs.size(); i++) {
                        graphs[i].setView(sf::FloatRect(graphs[i].getView().left,
                                                        graphs[i].getView().top,
                                                        graphs[i].getView().width*event.size.width,
                                                        graphs[i].getView().height*event.size.height));
                        graphs[i].update();
                    }

                    sidePanel.setView(sf::FloatRect(   sidePanel.getView().left,
                                                       sidePanel.getView().top,
                                                       sidePanel.getView().width*event.size.width,
                                                       sidePanel.getView().height*event.size.height));
                break;
            }
        }

        //clear the frame
        window.setView(window.getDefaultView());
        window.clear(graphColor);

        for (int i=0; i<graphs.size(); i++) {
            //draw lines on graphs
            graphs[i].draw(window);
        }

        sidePanel.draw(window);

        //display frame
        window.display();
    }
}