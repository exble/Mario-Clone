#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"
#include <math.h>

class Entity : public Object{
public:
    Entity();
    // Right for positive vx, Up for positive vy
    void move();

    int vx() const;
    int vy() const;

    void setVx(int newVx);
    void setVy(int newVy);
    void setSpeed(int Vx, int Vy);
    enum class Facing{Left, Right};
private:
    int _vx, _vy;
};

#endif // ENTITY_H
