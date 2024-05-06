#include <QKeyEvent>
#include <QDebug>

#include "Flag.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"
#include "Config.h"

Flag::Flag(FlagPart flagpart, Flag* f)
    :flag(f)
{
    switch (flagpart){
    case FlagPart::Flag:
        setPixmap(QPixmap(":/images/image/item/flag.png"));
        break;
    case FlagPart::Pole:
         setPixmap(QPixmap(":/images/image/item/flag-pole.png"));
        break;
    }
    mhitbox = new Hitbox(this);
}

void Flag::update(){

    collide_handler();

    // with vx determine facing and state
    stateUpdate();

    // move according to Mario's vx and vy
    move();
    //qDebug() << "vx: " << vx() << "vy: " << vy();
    //qDebug() << "x: " << x() << "y: " << y();
    if(IsoutOfBound()){
       this->remove();
    }
}

void Flag::stateUpdate(){
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

void Flag::collide_handler()
{
    collide_info info = getCollide();
    Object* collider;
    if(info[Direction::Left].is_collide){
        collider = info[Direction::Left].collider;
        if(typeid(*collider) == typeid(Mario)){
            setVy(-2);
            setPos(info[Direction::Left].collider->x()+50, y());
        }
    }
    if(info[Direction::Down].is_collide){
        collider = info[Direction::Down].collider;
        if(typeid(*collider) == typeid(Block)){
            setVy(0);
            state = State::Stop;
            setPos(x(), info[Direction::Down].collider->y() - 50);

        }
    }
}

void Flag::setState(State newState)
{
    state = newState;
}
