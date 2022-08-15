#ifndef WINDOW_CONSTANTS_H
#define WINDOW_CONSTANTS_H

#include <SFML/Graphics/Color.hpp>
#include <String>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

const float VERTICAL_BAR_WIDTH = 2;

const std::string fontPath = "resources/NotoSans-Medium.ttf";

const int CONST_SCALE = 30;

const float SIDEPANEL_WIDTH = 0.2f;

const int GRAPH_LINE_COUNT = 32; // ONE AXIS

const float LINE_WIDTH = 2.f;

const sf::Color graphColor(75,75,75);
const sf::Color graphLineColor(45,45,45);
const sf::Color sidePanelColor(100,100,100);

const int DEFAULT_RANGE = 40;

const int GRAPH_COUNT = 10;

#endif // WINDOW_CONSTANTS_H