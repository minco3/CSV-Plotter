#ifndef APP_H
#define APP_H

#include <math.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../objects/sidePanel.h"
#include "../objects/graph.h"
#include "../objects/timeline.h"

class app {

    public:
    /*
        \brief Default contstructor. Used at initialization of the graph.
    */
    app();

    public:
    /*
        \brief opens the window and starts the main loop
    */
    void run();

    public:
    /*
        \brief loads CSV from file and loads data

        \param path path to load CSV from
    */
    void loadCSV(const std::string& path);

    private:
    sf::View globalView;
    sf::RenderWindow window;
    std::vector<graphObj> graphs;
    std::vector<std::vector<std::string>> data;
    sidePanelObj sidePanel;
    timelineObj timeline;
    sf::Font font;
    sf::RectangleShape verticalBar;
    sf::RectangleShape selectionArea;
    float selectionStart;
    bool selecting;

};

#endif //APP_H