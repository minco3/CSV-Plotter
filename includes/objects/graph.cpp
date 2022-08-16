#include "graph.h"

const bool debug = false;

graphObj::graphObj() {

}

graphObj::graphObj(std::vector<std::string> _data, sf::View _view) {
    view = _view;
    setData(_data);
}

graphObj::graphObj(std::vector<std::string> _data, sf::FloatRect _view, const sf::Font& _font) {
    view.reset(sf::FloatRect(0,0,SCREEN_WIDTH*_view.width, SCREEN_HEIGHT*_view.height));
    view.setViewport(_view);
    setData(_data);

    min = sf::Text("0", _font, 18);

    max = sf::Text("0", _font, 18);
    max.setOrigin(0.f, max.getGlobalBounds().height);
    max.setPosition(0,view.getSize().y-10);

    background.setFillColor(graphColor);
    background.setSize(view.getSize());
}

void graphObj::draw(sf::RenderWindow& window) {
    window.setView(view); //draw to graph view

    window.draw(background);

    for (int i=0; i<lines.size(); i++) {
        window.draw(lines[i]);
    }

    window.draw(min);
    window.draw(max);
}

void graphObj::update() { //calculate where lines go

    float value1, value2;

    xRange = xMax-xMin; // might be set elsewhere at some point


    for (int i=17; i<18; i++) { // skipping x axis of graph

    value1 = stof(data[xMin+1]);

    //get local min and max y values to scale graph properly
    getRange(data, xMin, xMax, yMin, yMax, yRange);

    if (debug) std::cout << "data.size() " << data.size() << " xMin: " << xMin << " xMax: " << xMax << " xRange " << xRange << " yMin " << yMin << " yMax " << yMax << " yRange " << yRange;


    //set range labels
    min.setString(std::to_string(yMin)); 
    max.setString(std::to_string(yMax));

        for (int j=0; j<xRange&&j<data.size()-1; j++) {

            value2 = stof(data[j+xMin+2]);

            if(j==lines.size()) lines.emplace_back();

            //calculate rotation position and length of each segment
            lines[j].setPosition(j*view.getSize().x/xRange, fabs(((value1-yMin)/yRange*view.getSize().y)-view.getSize().y));
            if (debug) std::cout<<"\nline [" << j << "] height = " << (value1-yMin)/yRange*view.getSize().y; 

            int xWidthPixels = view.getSize().x/xRange;
            float yHeightPixels = (value2-value1)*(view.getSize().y/yRange);

            if (debug) std::cout << " x: " << j*view.getSize().x/xRange << " y: " << yHeightPixels;

            //set length
            float length = sqrt(pow(xWidthPixels,2)+powf(yHeightPixels,2));

            lines[j].setSize(sf::Vector2f(length,LINE_WIDTH));
            if (debug) std::cout<<" length = " << length;

            //set rotation
            float rotation = -atanf(yHeightPixels/xWidthPixels)*180.f/M_PI;

            lines[j].setRotation(rotation);
            if (debug) std::cout << " Rotation " << rotation;

            
            value1 = value2;
        }
        if (debug) std::cout << "\nline count: " << lines.size();
    }
}

void graphObj::setData(const std::vector<std::string> _data) {
    data = _data;
    update();
}


void graphObj::setView(const sf::FloatRect _view) {
    view.reset(_view);
    max.setPosition(0,view.getSize().y-10);
    background.setSize(view.getSize());
}

sf::FloatRect graphObj::getView() {
    return view.getViewport();
}