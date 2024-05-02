#ifndef BLOCK_H
#define BLOCK_H

#include "Object.h"
#include "Config.h"

class Hitbox;

class Block : public Object{
public:
    Block(Blocks block_type);
    QRectF hitbox( char );
private:

};


#endif // BLOCK_H
