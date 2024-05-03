#include <QKeyEvent>
#include <QDebug>

#include "ToxicMushroom.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"

ToxicMushroom::ToxicMushroom()
{
    setPixmap(QPixmap(":/images/image/toxic mushroom1.png"));
    faceTo = Facing::Left;
    state = State::Stop;
    walking_annimation_L = {":/images/image/toxic mushroom1.png",
                            ":/images/image/toxic mushroom2.png"};
    walking_annimation_R = {":/images/image/toxic mushroom1.png",
                            ":/images/image/toxic mushroom2.png"};
    walking_state = 0;
    animation_counter = 0;
    mhitbox = new Hitbox(this);
    is_enemy = true;
    setVx(1);
}

void ToxicMushroom::update(){



    collide_handler();

    // with vx determine facing and state
    stateUpdate();

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

void ToxicMushroom::stateUpdate(){
    if(vy() > 0){
        state = State::Jumping;
    }
    else if(vy() < 0){
        state = State::Falling;
    }
    else if(vx() == 0 && vy() == 0){
        state = State::Stop;
    }
    else{
        state = State::Running;
    }
    if(vx() > 0){
        faceTo = Facing::Right;
    }
    else if(vx() < 0){
        faceTo = Facing::Left;
    }
}

void ToxicMushroom::update_image(){
    //change image according to state and facing
    if(state == State::Stop){
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(":/images/image/toxic mushroom1.png"));
        }
        else{
            setPixmap(QPixmap(":/images/image/toxic mushroom2.png"));
        }
    }
    else if (state == State::Running){
        if(walking_state == walking_annimation_L.size()){
            walking_state = 0;
        }
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(walking_annimation_L[walking_state]));
        }
        else if(faceTo == Facing::Right){
            setPixmap(QPixmap(walking_annimation_R[walking_state]));
        }
        if(animation_counter == TICK_PER_ANIMATION){
            walking_state++;
            animation_counter = 0;
        }
        animation_counter++;
    }
    else if (state == State::Falling){

    }
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
                state = State::Stop;
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

void ToxicMushroom::gravity()
{
    setVy(fmax(vy() - SEC_TO_TICK(GRAVITATIONAL_ACCELERATION_PER_SEC), -10));
}


void ToxicMushroom::setState(State newState)
{
    state = newState;
}
