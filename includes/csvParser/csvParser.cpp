#include "csvParser.h"

std::vector<std::vector<std::string>> csvParse(std::string filePath) {
    
    //check if path specified is a csv file
    if(filePath.substr(filePath.length()-3,3)!="csv") {
        throw("The path specified doesnt lead to a csv file or doesnt have the .csv file extension.");
    }

    std::ifstream csvStream(filePath);

    //checksif file exists
    if (!csvStream.is_open()) {
        throw("Error opening file.");
    }

    std::vector<std::vector<std::string>> result;

    //parse file

    //store titles of columns
    std::vector<std::string> values;
    std::string line;

    //for the first line, add new vectors so lines are stored vertically
    std::getline(csvStream, line, '\n');
    values = lineParse(line, ',');
    for (int i=0; i<values.size(); i++){
        result.emplace_back();
        result[i].push_back(values[i]);
    }
    
    //get each line, parse it, and add it to result vector
    while (std::getline(csvStream, line, '\n')) {
        values = lineParse(line, ',');
        for (int i=0; i<values.size(); i++){
            result[i].push_back(values[i]);
        }
    }

    return result;
}

std::vector<std::string> lineParse(std::string line, char delim) {

    std::vector<std::string> result; 
    std::string word;

    for(int i=0; i<line.size(); i++) {

        if(line[i]!=delim) {
            //if normal character, add to word
            word+=line[i];
        } else {
            //else push word to result and clear string
            result.push_back(word);
            word.clear();
        }
    }

    return result;
}
