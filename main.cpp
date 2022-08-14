#include <iostream>

#include "includes/app/app.h"

#include "includes/objects/graph.h"

int main() {

    // std::vector<std::vector<std::string>> a = csvParse("resources/sat_realtime_telemetry.csv");
    // for (int i=0; i<a.size(); i++) {
    //     for (int j=0; j<a[i].size(); j++) {
    //         std::cout<<a[i][j]<<", ";
    //     }
    //     std::cout<<'\n';
    // }

    //create graph object
    app application;
    
    //starts main loop
    application.run();

    return EXIT_SUCCESS;
}
