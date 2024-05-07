#include <QDebug>
#include "Flower.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"

Flower::Flower()
{
    setPixmap(QPixmap(":/images/image/flower1.5.png"));
    walking_annimation = {":/images/image/flower1.5.png",
                          ":/images/image/flower1.6.png",
                          ":/images/image/flower1.4.png",
                          ":/images/image/flower1.3.png",
                          ":/images/image/flower1.2.png",
                          ":/images/image/flower1.1.png",
                          ":/images/image/flower1.4.png",
                          ":/images/image/flower1.3.png" };
    walking_state = 0;
    animation_counter = 0;
    mhitbox = new Hitbox(this);
    is_enemy = true;
}

void Flower::update(){

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


void Flower::update_image(){

    if(walking_state == walking_annimation.size()){
        walking_state = 0;
        setPos(x(),y() + 30);
    }

    setPixmap(QPixmap(walking_annimation[walking_state]));

    if(animation_counter == TICK_PER_ANIMATION * 3){
        walking_state++;
        if (walking_state / 2 == 1 && walking_state % 2 == 0){
            setPos(x(),y() - 30);
        }
        else if (walking_state / 2 == 2 && walking_state % 2 == 0){
            setPos(x(),y() - 30);
        }
        else if (walking_state / 2 == 3 && walking_state % 2 == 0){
            setPos(x(),y() + 30);
        }
        animation_counter = 0;
    }
    animation_counter++;

}

void Flower::collide_handler()
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
    if(info[Direction::Left].is_collide){
        collider = info[Direction::Left].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vx() < 0){
                setVx(-vx());
                setPos(info[Direction::Left].collider->x()+50, y());
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
