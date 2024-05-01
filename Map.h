#ifndef MAP_H
#define MAP_H

#include "Config.h"
#include "Game.h"
#include <vector>
using namespace std;

/*
    Todo:
    map cord system from block cord to scene cord
    (0,0) at up left corner
    x+ right
    y+ down
    1 tile is 50 pixel
    mario is about 50 pixel wide
    consider map size about 300 block6

*/

class Map{
public:
    int width, height;

    vector<vector<Blocks>> block_map;
    vector<vector<Entity>> entity_map;
};

#endif // MAP_H
