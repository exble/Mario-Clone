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

Entity::~Entity()
{
    for(int i = 0; i < game->EntityList.size(); i++){
        if(game->EntityList[i] == this){
            game->EntityList.removeAt(i);
            break;
        }
    }
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

    foreach(Hitbox* static_hb, game->HitboxList)
    {
        if(mhitbox->objtopRect.intersects(static_hb->objbottomRect)){
            info[Direction::Up].is_collide = true;
            info[Direction::Up].collider = static_hb->owner;
        }
        if(mhitbox->objleftRect.intersects(static_hb->objrightRect)){
            info[Direction::Left].is_collide = true;
            info[Direction::Left].collider = static_hb->owner;
        }
        if(mhitbox->objrightRect.intersects(static_hb->objleftRect)){
            info[Direction::Right].is_collide = true;
            info[Direction::Right].collider = static_hb->owner;
        }
        if(mhitbox->objbottomRect.intersects(static_hb->objtopRect)){
            info[Direction::Down].is_collide = true;
            info[Direction::Down].collider = static_hb->owner;
        }
    }
    return info;
}
