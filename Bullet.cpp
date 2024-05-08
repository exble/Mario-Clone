#include "Bullet.h"
#include "Block.h"
#include "Hitbox.h"
#include "MovingBlock.h"

Bullet::Bullet(Facing dir)
{
    setPixmap(QPixmap(":/images/image/bullet.png"));

    if(dir == Facing::Left){
        setVx(-BULLET_SPEED);
    }
    else if(dir == Facing::Right){
        setVx(BULLET_SPEED);
    }
    mhitbox = new Hitbox(this);
}

void Bullet::update()
{
    collisions = collidingItems();
    foreach(QGraphicsItem* i, collisions){
        Entity* item = dynamic_cast<Entity*>(i);
        if(item && item->is_enemy){
            item->remove();
            this->remove();
        }
        Block* bl = dynamic_cast<Block*>(i);
        if(bl){
            this->remove();
        }
        MovingBlock* mv = dynamic_cast<MovingBlock*>(i);
        if(mv){
            this->remove();
        }
    }
    if(IsoutOfBound()){
        this->remove();
    }
    move();
}
