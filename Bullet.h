#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity{
public:
    Bullet();
    Bullet(int _vx);
private:
    void update();
};

#endif // BULLET_H
