#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Entity.h"

class Mushroom : public Entity{
public:
    Mushroom();
private:
    void update();
    void collide_handler();
};

#endif // MUSHROOM_H
