#include "app.h"

app::app() {
    //load shared font
    if(!font.loadFromFile(fontPath)) {
        throw ("font not found");
    }

    verticalBar.setFillColor(sf::Color::Black);
    verticalBar.setSize(sf::Vector2f(LINE_WIDTH,SCREEN_HEIGHT-SCREEN_HEIGHT*(GRAPH_HEIGHT+DIVIDER_WIDTH)));
}

void app::loadCSV(const std::string& path) {
    //load and parse data
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

    //add side panel
    sidePanel = sidePanelObj(sf::FloatRect(1.f-SIDEPANEL_WIDTH, 0.f, SIDEPANEL_WIDTH, 1.f));

    //add timeline
    timeline = timelineObj(sf::FloatRect(0, GRAPH_COUNT*GRAPH_HEIGHT, GRAPH_WIDTH, GRAPH_HEIGHT));

    for (int i=0; i<GRAPH_COUNT&&i<data.size()-1; i++) {

        //add graphs
        graphs.emplace_back(data[i+1],
                            sf::FloatRect(0,
                                          GRAPH_HEIGHT*i,
                                          GRAPH_WIDTH,
                                          (1.f-DIVIDER_WIDTH*(GRAPH_COUNT+1))*GRAPH_HEIGHT),
                            font);

        //add names of columns to side panel
        sidePanel.addEntry(sf::Text(data[i+1][0], font, 18));

    }

    for (int i=0; i<TIMESTAMP_COUNT; i++) {
        timeline.addEntry(sf::Text(data[0][DEFAULT_RANGE/TIMESTAMP_COUNT*i+1], font, 15));
    }

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
                break;
                case sf::Event::MouseMoved:
                    if (event.mouseMove.x<window.getSize().x*GRAPH_WIDTH) {
                        verticalBar.setPosition(event.mouseMove.x, 0);
                    }
                break;
                case sf::Event::Resized:

                    std::cout << "resized" << std::endl;

                    // update the view to the new size of the window
                    for(int i=0; i<graphs.size(); i++) {
                        graphs[i].setView(sf::FloatRect(graphs[i].getView().left,
                                                        graphs[i].getView().top,
                                                        graphs[i].getView().width*event.size.width,
                                                        graphs[i].getView().height*event.size.height));
                        graphs[i].update();
                    }

                    sidePanel.setView(sf::FloatRect(sidePanel.getView().left,
                                                    sidePanel.getView().top,
                                                    sidePanel.getView().width*event.size.width,
                                                    sidePanel.getView().height*event.size.height));

                    timeline.setView(sf::FloatRect(timeline.getView().left,
                                                   timeline.getView().top,
                                                   timeline.getView().width*event.size.width,
                                                   timeline.getView().height*event.size.height));

                    verticalBar.setSize(sf::Vector2f(LINE_WIDTH+1,event.size.height-event.size.height*(GRAPH_HEIGHT+DIVIDER_WIDTH)));
                    
                    window.setView(sf::View(sf::FloatRect(0.f, 0.f, event.size.width, event.size.height)));
                break;
            }
        }

        //clear the frame
        window.setView(window.getDefaultView());
        window.clear(graphLineColor);

        //draw elements
        for (int i=0; i<graphs.size(); i++) {
            //draw lines on graphs
            graphs[i].draw(window);
        }

        //draw side panel
        sidePanel.draw(window);

        //draw timeline
        timeline.draw(window);

        //draw globals on top of panels
        window.setView(window.getDefaultView());

        //draw vertical bar
        window.draw(verticalBar);

        //display frame
        window.display();
    }
}