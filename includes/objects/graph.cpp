#include "graph.h"

const bool debug = false;

graphObj::graphObj() {

}

graphObj::graphObj(std::vector<std::string> _data, sf::FloatRect _view, const sf::Font& _font) {

    view.reset(sf::FloatRect(0,0,SCREEN_WIDTH*_view.width, SCREEN_HEIGHT*_view.height));
    view.setViewport(_view);

    max = sf::Text("0", _font, 18);

    min = sf::Text("0", _font, 18);
    min.setOrigin(0.f, min.getGlobalBounds().height);
    min.setPosition(0,view.getSize().y-10);

    background.setFillColor(graphColor);
    background.setSize(view.getSize());

    setData(_data);
}

void graphObj::draw(sf::RenderWindow& window) {
    window.setView(view); //draw to graph view

    window.draw(background);

    window.draw(vertecies);

    window.draw(min);
    window.draw(max);
}

void graphObj::update() { //calculate where vertecies go

    vertecies.clear();
    vertecies = sf::VertexArray(sf::TriangleStrip, static_cast<std::size_t>(xRange*2));

    float value1, value2;

    xRange = xMax-xMin; // might be set elsewhere at some point


    for (int i=17; i<18; i++) { // skipping x axis of graph

    value1 = stof(data[xMin+1]);

    //get local min and max y values to scale graph properly
    getRange(data, xMin, xMax, yMin, yMax, yRange);

    if (debug) std::cout << "data.size() " << data.size() << " xMin: " << xMin << " xMax: " << xMax << " xRange " << xRange << " yMin " << yMin << " yMax " << yMax << " yRange " << yRange << std::endl;
    
    std::string minString(std::to_string(yMin)), maxString(std::to_string(yMax));

    

    //set range labels
    min.setString(minString.substr(0, minString.length()-4)); 
    max.setString(maxString.substr(0, maxString.length()-4));


        for (int j=1; j<xRange&&j<data.size(); j++) {

            int x, y;

            //calculate position of each vertex
            x = j*view.getSize().x/xRange; 
            y = fabs((((std::stof(data[j+xMin]))-yMin)/yRange*view.getSize().y)-view.getSize().y);

            if (debug) std::cout<<"line [" << j << "] height = " << ((std::stof(data[j+xMin]))-yMin)/yRange*view.getSize().y << std::endl; 

            // push high and low vertex

            if(j*2==vertecies.getVertexCount()) {
                vertecies.resize(vertecies.getVertexCount()+2);
            }

            vertecies[j*2] = sf::Vertex(sf::Vector2f(x,y+(LINE_WIDTH/2))); // high
            vertecies[j*2+1] = sf::Vertex(sf::Vector2f(x,y-(LINE_WIDTH/2))); // low

        }
        if (debug) std::cout << "\nvertex count: " << vertecies.getVertexCount();
    }
}

void graphObj::setData(const std::vector<std::string>& _data) {
    data = _data;

    update();
}


void graphObj::setView(const sf::FloatRect& _view) {
    view.reset(_view);
    min.setPosition(0,view.getSize().y-10);
    background.setSize(view.getSize());
}

sf::FloatRect graphObj::getView() {
    return view.getViewport();
}

void graphObj::setZoom(const int& start, const int& finish) {
    int low, high;
    if (start<finish) {
        low = start;
        high = finish;
    }

    float width = view.getSize().x;

    xMin = xRange*(low/width);
    xMax = xRange*(high/width);

    xRange = xMax-xMin; 

    std::cout << "xMin: " << xMin << " xMax: " << xMax << " xRange " << xRange << std::endl;

    update();
}

void graphObj::resetZoom() {
    xMin = 0;
    xMax = DEFAULT_RANGE;
    xRange = DEFAULT_RANGE;
    update();
}