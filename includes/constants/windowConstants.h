#ifndef WINDOW_CONSTANTS_H
#define WINDOW_CONSTANTS_H

#include <SFML/Graphics/Color.hpp>
#include <String>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;
const int GRID_WIDTH = 100;
const int GRID_HEIGHT = 100;
const int CELL_SIZE = 5;

const float VERTICAL_BAR_WIDTH = 2;

const float res = 2000.f;

const std::string fontPath = "resources/NotoSans-Medium.ttf";

const int CONST_SCALE = 30;

const float GRAPH_WIDTH_RATIO = 0.75f;

const int GRAPH_LINE_COUNT = 32; // ONE AXIS

const sf::Color graphColor(75,75,75);
const sf::Color graphLineColor(45,45,45);
const sf::Color sidePanelColor(100,100,100);

const int DEFAULT_HIGH_VALUE = 40;

#endif // WINDOW_CONSTANTS_H