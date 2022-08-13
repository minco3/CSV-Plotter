#ifndef CSVPARSER_H
#define CSVPARSER_H

// 




#include <fstream>
#include <vector>

/*
    \brief Opens and parses a .csv file.

    The first vector (0) contains the names of the columns. 

    \param fileName location of csv file to read (usually relative).

    \return An std::vector of std::string std::vectors containing all values.
*/
std::vector<std::vector<std::string>> csvParse(std::string filePath);

/*
    \brief Parses a string using a delim character.

    \param line location of csv file to read (usually relative).
    \param delim character to split string with (not included in return strings).

    \return An std::vector of std::string containing all values.
*/
std::vector<std::string> lineParse(std::string line, char delim);

#endif //CSVPARSER