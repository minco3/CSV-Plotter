#ifndef GRAPH_H
#define GRAPH_H

#define _USE_MATH_DEFINES

#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "sidePanel.h"
#include "../csvParser/csvParser.h"

#include "../graphTools/graphTools.h"

class graphObj { // graph application which displays csv data

    public:
    /*
        \brief Default contstructor. Used at initialization of the graph.
    */
    graphObj();

    public:
    /*
        \brief Constructor using data parsed before initialization of graph.
    */
    graphObj(std::vector<std::string> _data);

    public:
    /* 
        \brief Draws graph object to RenderWindow

        \param window sf::RenderWindow to draw to

    */ 
    void draw(sf::RenderWindow& window);

    public:
    /*
        \brief updates the lines on the graph from data
    */
    void update();

    public:
    /*
        \brief Used for setting the data of the graph.
    */
    void setData(const std::vector<std::string> _data);

    private:
    std::vector<std::string> data;
    sf::View view;
    sf::Font font;
    std::vector<sf::RectangleShape> lines;
    int xMin = 0;
    int xMax = xMin + DEFAULT_RANGE;
    int xRange = xMax - xMin;
    float yMin, yMax, yRange;
};

#endif //GRAPH_H