#include <QKeyEvent>
#include <QDebug>

#include "Flag.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"
#include "Config.h"
#include "Config.h"
#include <QTimer>

extern Game* game;

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
    is_trigger = false;
    EndTimer = new QTimer();
    EndTimer->setSingleShot(true);
    is_end = false;

    endSound.setSource(QUrl("qrc:/audio/audio/smb_stage_clear.wav"));
    endSound.setVolume(0.75);
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
    if (y()==98)
    {
        setVy(0);
        setPos(x(),97);

    }
    if(is_trigger){
        if(is_end && !EndTimer->isActive()){
            game->endGame();
        }
        else if(!is_end && !EndTimer->isActive()){
            is_end = true;
            EndTimer->start(3000);
        }
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
    if(info[Direction::Left].is_collide ){
        collider = info[Direction::Left].collider;
        if(typeid(*collider) == typeid(Mario) && !is_trigger){
            flag->setVy(2);
            is_trigger = true;
            game->backgroundMusic.stop();
            endSound.play();
        }
    }
}

void Flag::setState(State newState)
{
    state = newState;
}

