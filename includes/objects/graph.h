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
        \brief Constructor using data parsed before initialization of graph and the sf::View object.
    */
    graphObj(std::vector<std::string> _data, sf::View _view);

    public:
    /*
        \brief Constructor using data parsed before initialization of graph and a sf::floatRect which will be constructed into a view.
    */
    graphObj(std::vector<std::string> _data, sf::FloatRect _view, const sf::Font& _font);


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
        \param _data Vector containing strings with data loaded from the svg
    */
    void setData(const std::vector<std::string>& _data);

    public:
    /*
        \brief Used for resetting the 2D "camera" resolution of the view of the graph.
        \param _view sf::View to load the graph to
    */
    void setView(const sf::FloatRect& _view);

    public:
    /*
        \brief gets the 2D "camera" view of the graph.
        \return sf::floatRect with viewport proportions
    */
    sf::FloatRect getView();

    public:
    /*
        \brief sets horizontal zoom of graph
        \param start where selection started
        \param finish where selection finished
    */
    void setZoom(const int& start, const int& finish);

    private:
    sf::Text min, max;
    std::vector<std::string> data;
    sf::View view;
    sf::VertexArray vertecies; // can use static array for improved speed
    int vertexCount = DEFAULT_RANGE*2; // 2 vertecies per point 
    int xMin = 0;
    int xMax = xMin + DEFAULT_RANGE;
    int xRange = xMax - xMin;
    float yMin, yMax, yRange;
    sf::RectangleShape background;
};

#endif //GRAPH_H