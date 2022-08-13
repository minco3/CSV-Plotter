#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "sidePanel.h"
#include "../csvParser/csvParser.h"

class graphObj { // graph application which displays csv data

    public:
    /*
        \brief Default contstructor. Used at initialization of the window.
    */
    graphObj();

    private:
    /* 
        \brief Draws graph object to RenderWindow

        \param window sf::RenderWindow to draw to
    
    */ 
    void draw(sf::RenderWindow& window);

    private:
    /*
        \brief loads CSV from file and loads data

        \param path path to load CSV from
    */
    void loadCSV(const std::string& path);

    private:
    /*
        \brief updates the lines on the graph from data
    */
    void update();

    public:
    /*
        \brief opens the window and starts the main loop
    */
    void run();


    private:
    sf::RenderWindow window;
    sf::View graph;
    sf::FloatRect location;
    sidePanelObj sidePanel;
    sf::Font font;
    std::vector<std::vector<std::string>> data;
    int low = 0;
    int high = DEFAULT_HIGH_VALUE;
};

#endif //GRAPH_H