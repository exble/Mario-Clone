#include "Entity.h"
#include "Game.h"
#include "Hitbox.h"

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

collide_info Entity::getCollide()
{
    collide_info info;
    foreach(Hitbox* static_hb, game->StaticHitboxList)
    {
        if(mhitbox->objtopRect.intersects(static_hb->objbottomRect)){
            info.is_collide = true;
            info.collider = static_hb->owner;
            info.collide_from = Direction::Up;
            return info;
        }
        if(mhitbox->objleftRect.intersects(static_hb->objrightRect)){
            info.is_collide = true;
            info.collider = static_hb->owner;
            info.collide_from = Direction::Left;
            return info;
        }
        if(mhitbox->objrightRect.intersects(static_hb->objleftRect)){
            info.is_collide = true;
            info.collider = static_hb->owner;
            info.collide_from = Direction::Right;
            return info;
        }
        if(mhitbox->objbottomRect.intersects(static_hb->objtopRect)){
            info.is_collide = true;
            info.collider = static_hb->owner;
            info.collide_from = Direction::Down;
            return info;
        }
    }
    return info;
}
