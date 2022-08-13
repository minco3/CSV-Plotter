#include "csvParser.h"

std::vector<std::vector<std::string>> csvParse(std::string filePath) {
    
    //checks if path specified is a csv file
    if(filePath.substr(filePath.length()-3,3)!="csv") {
        throw("The path specified doesnt lead to a csv file or doesnt have the .csv file extension.");
    }

    std::ifstream csvStream(filePath);

    //checks if file exists
    if (!csvStream.is_open()) {
        throw("Error opening file.");
    }

    std::vector<std::vector<std::string>> result;

    //parses file

    //stores the titles of the columns
    std::vector<std::string> titles;
    std::string line;
    
    //gets each line, parses it, and adds it to result vector 
    while (std::getline(csvStream, line, '\n')) {
        titles = lineParse(line, ',');
        result.push_back(titles);
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
