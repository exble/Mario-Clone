#include "Entity.h"


Entity::Entity()
{
    _vx = 0;
    _vy = 0;
}

void Entity::move()
{
    setPos(x() + _vx,y() - _vy);
}

int Entity::vx() const
{
    return _vx;
}

int Entity::vy() const
{
    return _vy;
}

void Entity::setVx(int newVx)
{
    bool sign;
    if(newVx >= 0){
        sign = 0;
    }
    else{
        sign = 1;
    }
    if (abs(newVx) > MAX_SPEED){
        newVx = sign ? -MAX_SPEED: MAX_SPEED;
    }
    _vx = newVx;
}

void Entity::setVy(int newVy)
{
    bool sign;
    if(newVy >= 0){
        sign = 0;
    }
    else{
        sign = 1;
    }
    if (abs(newVy) > MAX_SPEED){
        newVy = sign ? -MAX_SPEED: MAX_SPEED;
    }
    _vy = newVy;
}

void Entity::setSpeed(int Vx, int Vy)
{
    setVx(Vx);
    setVy(Vy);
}
