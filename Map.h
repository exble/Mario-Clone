#ifndef MAP_H
#define MAP_H

#include "Config.h"

class Map{
private:
    Map() = default;
    void __setUpMap();
    static Map& getMap();
public:

    static void setUpMap();
};

#endif // MAP_H
