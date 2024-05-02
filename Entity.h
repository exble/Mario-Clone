#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"
#include <math.h>

struct collide_info
{
    bool is_collide = false;
    Object* collider = nullptr;
    Direction collide_from = Direction::Up;
};

class Entity : public Object{
public:
    Entity();
    // Right for positive vx, Up for positive vy
    void move();

    float vx() const;
    float vy() const;
    collide_info getCollide();
    void setVx(float newVx);
    void setVy(float newVy);
    void setSpeed(float Vx, float Vy);

private:
    float _vx, _vy;
};

#endif // ENTITY_H
