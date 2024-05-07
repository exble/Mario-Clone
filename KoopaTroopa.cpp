#include <QDebug>
#include "KoopaTroopa.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"
#include "ToxicMushroom.h"
#include "Flower.h"
KoopaTroopa::KoopaTroopa()
{
    setPixmap(QPixmap(":/images/image/Rtortoise1.png"));
    walking_annimation = {":/images/image/Rtortoise1.png",
                          ":/images/image/Rtortoise2.png",
                          ":/images/image/Ltortoise1.png",
                          ":/images/image/Ltortoise2.png",
                          ":/images/image/shell1.png",
                          ":/images/image/shell2.png",
                          ":/images/image/shell3.png",
                          ":/images/image/shell4.png"};
    status_change=0;
    walking_state = 0;
    animation_counter = 0;
    mhitbox = new Hitbox(this);
    is_enemy = true;
    setVx(1);
}

void KoopaTroopa::update(){

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


void KoopaTroopa::update_image(){


    if(walking_state == 2 && !status_change && vx()>0){
        walking_state = 0;
    }
    else if(walking_state == 4 && !status_change && vx()<0){
        walking_state = 2;
    }
    if(walking_state == 7 && status_change){
        walking_state = 4;
    }
    if(vx()==0){
       walking_state = 4;
    }
    setPixmap(QPixmap(walking_annimation[walking_state]));

    if(!status_change){
        if(animation_counter == TICK_PER_ANIMATION){
           walking_state++;
           animation_counter = 0;
        }
    }
    else{
        if(animation_counter == TICK_PER_ANIMATION/2){
           walking_state++;
           animation_counter = 0;
        }
    }
    animation_counter++;
}

void KoopaTroopa::collide_handler()
{
    collide_info info = getCollide();
    Object* collider;
    if(info[Direction::Up].is_collide){
        collider = info[Direction::Up].collider;
        if(typeid(*collider) == typeid(Mario) && !status_change && dynamic_cast<Mario*>(collider)->vy()<0){
            status_change = true;
            walking_state = 4;
            setPos(x(),y()+25);
            setVx(0);
            dynamic_cast<Mario*>(collider)->setVy(2);
        }
        else if(typeid(*collider) == typeid(Mario) && status_change){
            walking_state = 4;
            if(vx()== 4 || vx()== -4 ){
                setVx(-vx());
            }
            else{
                setVx(4);
            }
            dynamic_cast<Mario*>(collider)->setVy(2);
        }
    }
    if(info[Direction::Down].is_collide){
        collider = info[Direction::Down].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vy() < 0){
                setVy(0);
                if(!status_change){
                    setPos(x(), info[Direction::Down].collider->y() - 75);
                }
                else{
                    setPos(x(), info[Direction::Down].collider->y() - 50);
                }
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
                setPos(info[Direction::Left].collider->x()+50, y());
                if(!status_change){
                    walking_state = 0;
                }
                else{
                    walking_state = 4;
                }
            }
        }
        if(typeid(*collider) == typeid(Mario)){
            if(vx() == 0){
                setVx(4);
                setPos(x()+3,y());
            }
        }
        if(typeid(*collider) == typeid(ToxicMushroom) ||
                typeid(*collider) == typeid(Flower)){
            if(vx() == 4 || vx() == -4 ){
                collider->remove();
            }
        }
    }
    if(info[Direction::Right].is_collide){
        collider = info[Direction::Right].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vx() > 0){
                setVx(-vx());
                setPos(info[Direction::Right].collider->x()-50, y());
                if(!status_change){
                    walking_state = 2;
                }
                else{
                    walking_state = 4;
                }
            }
        }
        if(typeid(*collider) == typeid(Mario)){
            if(vx() == 0){
                setVx(-4);
                setPos(x()-3,y());
            }
        }
        if(typeid(*collider) == typeid(ToxicMushroom) ||
                typeid(*collider) == typeid(Flower)){
            if(vx() == 4 || vx() == -4 ){
                collider->remove();
            }
        }
    }
}
