#ifndef BLOCK_H
#define BLOCK_H

#include "Object.h"
#include "Config.h"

class Hitbox;

class Block : public Object{
public:
    Block(Blocks block_type, Items spawn_type = Items::None);
    void BlockEvent();
private:
    Blocks block_type;
    Items spawnType;
};


#endif // BLOCK_H
