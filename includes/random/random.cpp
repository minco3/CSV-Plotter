#include "random.h"

int random(int x, int y) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(x,y);
    return dist(mt);
}

int fastrand(int x) { 
        return rand()%x;
} 