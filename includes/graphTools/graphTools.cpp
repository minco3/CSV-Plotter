#include "graphTools.h"

void getRange(const std::vector<std::string>& data, const int& xMin, const int& xMax, float& yMin, float& yMax, float& yRange) {
    
    //set first values
    yMin = stof(data[xMin+1]);
    yMax = stof(data[xMin+1]);

    for (int i=xMin+2; i<xMax-xMin&&i<data.size(); i++) {

        //check if each value is lower or higher than current min/max

        if (stof(data[i])<yMin) yMin = stof(data[i]);
        else if (stof(data[i])>yMax) yMax = stof(data[i]);
    }
    yRange = yMax-yMin;
}