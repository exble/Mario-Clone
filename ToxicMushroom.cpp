#include <QKeyEvent>
#include <QDebug>

#include "ToxicMushroom.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"

ToxicMushroom::ToxicMushroom()
{
    setPixmap(QPixmap(":/images/image/toxic mushroom1.png"));
    walking_annimation = {":/images/image/toxic mushroom1.png",
                            ":/images/image/toxic mushroom2.png"};
    walking_state = 0;
    animation_counter = 0;
    mhitbox = new Hitbox(this);
    is_enemy = true;
    setVx(1);
}

void ToxicMushroom::update(){



    collide_handler();

    // update image according to facing and state
    update_image();

    // move according to Mario's vx and vy
    move();
    //qDebug() << "vx: " << vx() << "vy: " << vy();
    //qDebug() << "x: " << x() << "y: " << y();
    if(IsoutOfBound()){
       this->remove();
    }
}


void ToxicMushroom::update_image(){

    if(walking_state == walking_annimation.size()){
        walking_state = 0;
    }

    setPixmap(QPixmap(walking_annimation[walking_state]));

    if(animation_counter == TICK_PER_ANIMATION){
        walking_state++;
        animation_counter = 0;
    }
    animation_counter++;
}

void ToxicMushroom::collide_handler()
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
