#include "graph.h"

graphObj::graphObj() {

    // //fill lines vector with default range of default width rectangles
    // for (int i=0; i<DEFAULT_RANGE; i++) {
    //     lines.emplace_back(sf::Vector2f(SCREEN_WIDTH/DEFAULT_RANGE,1));
    // }
}

graphObj::graphObj(std::vector<std::string> _data) {
    setData(_data);
}

void graphObj::draw(sf::RenderWindow& window) {
    window.setView(view);
    window.clear(graphColor);
    for (int i=0; i<lines.size(); i++) {
        window.draw(lines[i]);
    }
}

void graphObj::update() { //calculate where lines go

    float value1, value2;

    xRange = xMax-xMin; // might be set elsewhere at some point


    for (int i=17; i<18; i++) { // skipping x axis of graph

    value1 = stof(data[xMin+1]);

    //get local min and max y values to scale graph properly
    getRange(data, xMin, xMax, yMin, yMax, yRange);

    std::cout << yMin << " " << yMax << " " << yRange;

        for (int j=0; j<xRange&&j<data[0].size()-1; j++) {

            value2 = stof(data[j+xMin+2]);

            if(j==lines.size()) lines.emplace_back();

            //calculate rotation position and length of each segment
            lines[j].setPosition(j*view.getSize().x/xRange, fabs(((value1-yMin)/yRange*view.getSize().y)-view.getSize().y));
            std::cout<<"\nheight = " << (value1-yMin)/yRange*view.getSize().y; 

            int xWidthPixels = view.getSize().x/xRange;
            float yHeightPixels = (value2-value1)*(view.getSize().y/yRange);

            std::cout << " x" << xWidthPixels << " y" << yHeightPixels;

            float length = sqrt(pow(xWidthPixels,2)+powf(yHeightPixels,2));

            lines[j].setSize(sf::Vector2f(length,1));
            std::cout<<" length = " << length;

            float rotation = -atanf(yHeightPixels/xWidthPixels)*180.f/M_PI;

            lines[j].setRotation(rotation);
            std::cout << " Rotation " << rotation;

            
            value1 = value2;
        }
    }
}

void graphObj::setData(const std::vector<std::string> _data) {
    data = _data;
    update();
}