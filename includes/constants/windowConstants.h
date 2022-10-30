#ifndef WINDOW_CONSTANTS_H
#define WINDOW_CONSTANTS_H

#include <SFML/Graphics/Color.hpp>
#include <String>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 1000;

const float VERTICAL_BAR_WIDTH = 2;

const std::string FONT_PATH = "resources/NotoSans-Medium.ttf";
const std::string CSV_PATH = "resources/sat_realtime_telemetry_small.csv";

const int CONST_SCALE = 30;

const float SIDEPANEL_WIDTH = 0.2f;
const float GRAPH_WIDTH = 0.795f;

const int GRAPH_LINE_COUNT = 32; // ONE AXIS

const float LINE_WIDTH = 2.f;

const float DIVIDER_WIDTH = 0.005f;

const sf::Color graphColor(75,75,75);
const sf::Color graphLineColor(45,45,45);
const sf::Color sidePanelColor(100,100,100);
const sf::Color SELCTION_COLOR(30,30,30,50);

const int DEFAULT_RANGE = 400;

const int TIMESTAMP_COUNT = 10;

const int GRAPH_COUNT = 20;

const float GRAPH_HEIGHT = 1.f/(GRAPH_COUNT+1); // +1 is for timeline

#endif // WINDOW_CONSTANTS_H