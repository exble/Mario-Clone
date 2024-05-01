#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"
#include <math.h>

class Entity : public Object{
public:
    Entity();
    // Right for positive vx, Up for positive vy
    void move();

    float vx() const;
    float vy() const;

    void setVx(float newVx);
    void setVy(float newVy);
    void setSpeed(float Vx, float Vy);
    enum class Facing{Left, Right};
private:
    float _vx, _vy;
};

#endif // ENTITY_H
