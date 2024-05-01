#ifndef BLOCK_H
#define BLOCK_H

#include "Object.h"
#include "Config.h"
#include "Hitbox.h"


class Block : public Object{
public:
    Block(Blocks block_type);
    QRectF Block::hitbox( char );
};


#endif // BLOCK_H
