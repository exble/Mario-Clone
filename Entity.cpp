#include "Entity.h"
#include "Game.h"

extern Game* game;

Entity::Entity()
{
    _vx = 0;
    _vy = 0;
    game->EntityList.push_back(this);
}

void Entity::move()
{
    setPos(x() + _vx,y() - _vy);
}

float Entity::vx() const
{
    return _vx;
}

float Entity::vy() const
{
    return _vy;
}

void Entity::setVx(float newVx)
{
    _vx = newVx;
}

void Entity::setVy(float newVy)
{
    _vy = newVy;
}

void Entity::setSpeed(float Vx, float Vy)
{
    setVx(Vx);
    setVy(Vy);
}
