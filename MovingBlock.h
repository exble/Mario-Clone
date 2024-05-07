#ifndef MOVINGBLOCK_H
#define MOVINGBLOCK_H

#include "Entity.h"

class MovingBlock : public Entity{
public:
    MovingBlock(Blocks block_type);
    Blocks block_type;
private:
    void update();

};

#endif // MOVINGBLOCK_H
