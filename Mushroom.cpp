#include "Mushroom.h"
#include "Block.h"
#include "Hitbox.h"
#include "Mario.h"

Mushroom::Mushroom()
{
    setPixmap(QPixmap(":/images/image/item/super mushroom.png"));
    if(rand()%2){
        setVx(1);
    }
    else{
        setVx(-1);
    }
    mhitbox = new Hitbox(this);
}

void Mushroom::update()
{
    auto collider = collidingItems();
    Mario* player;
    foreach(QGraphicsItem* item, collider){
        player = dynamic_cast<Mario*>(item);
        if(player){
            player->beBig();
            this->remove();
       }
    }
    collide_handler();
    move();
}

void Mushroom::collide_handler()
{
    collide_info info = getCollide();
    Object* collider;
    if(info[Direction::Up].is_collide){
        collider = info[Direction::Up].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vy() > 0){
                setVy(0);
                setPos(x(), collider->y()+collider->boundingRect().height());
            }
        }
    }
    if(info[Direction::Down].is_collide){
        collider = info[Direction::Down].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vy() < 0){
                setVy(0);
                setPos(x(), info[Direction::Down].collider->y() - 50);
            }
        }
    }
    else{
        gravity();
    }
    if(info[Direction::Left].is_collide){
        collider = info[Direction::Left].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vx() < 0){
                setVx(-vx());
                setPos(info[Direction::Left].collider->x()+collider->boundingRect().width(), y());
            }
        }

    }
    if(info[Direction::Right].is_collide){
        collider = info[Direction::Right].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vx() > 0){
                setVx(-vx());
                setPos(info[Direction::Right].collider->x()-50, y());
            }
        }
    }
}
