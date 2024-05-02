#include <QKeyEvent>
#include <QDebug>

#include "ToxicMushroom.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"


extern ToxicMushroom* toxicMushroom;

ToxicMushroom::ToxicMushroom()
    {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPixmap(QPixmap(":/images/image/toxic mushroom1.png"));
    faceTo = Facing::Left;
    state = State::Stop;
    walking_annimation_L = {":/images/image/toxic mushroom1.png",
                            ":/images/image/toxic mushroom2.png"};
    walking_annimation_R = {":/images/image/toxic mushroom1.png",
                            ":/images/image/toxic mushroom2.png"};
    walking_state = 0;
    animation_counter = 0;
    setCollision(true);
    mhitbox = new Hitbox(this, false);
    setVx(1);
}


void ToxicMushroom::CollideAtEvent(Direction dir, Object* collider)
{
    if(dir == Direction::Up){
        //qDebug() << time(NULL) << "Collide up";
        if(vy() > 0){
            setVy(0);
            setPos(x(), collider->y()+collider->boundingRect().height());
        }
    }
    if(dir == Direction::Left){
        //qDebug() << time(NULL) << "Collide Left";
        if(vx() < 0){
            setVx(-vx());
            setPos(collider->x()+50, y());
        }
    }
    if(dir == Direction::Down){
        //qDebug() << time(NULL) << "Collide Down";
        if(vy() < 0){
            setVy(0);
            state = State::Stop;
            is_onground = true;
            setPos(x(), collider->y() - 55);
        }
    }
    if(dir == Direction::Right){
        //qDebug() << time(NULL) << "Collide Right";
        if(vx() > 0){
            setVx(-vx());
            setPos(collider->x()-50, y());
        }
    }
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
    if(info.is_collide){
        if(info.collide_from == Direction::Up){
            if(vy() > 0){
                setVy(0);
                setPos(x(), info.collider->y()+info.collider->boundingRect().height());
            }
        }
        if(info.collide_from == Direction::Down){
            if(vy() < 0){
                setVy(0);
                state = State::Stop;
                setPos(x(), info.collider->y() - 50);
            }
        }
        else{
            gravity();
        }
        if(info.collide_from == Direction::Left){
            if(vx() < 0){
                setVx(-vx());
                setPos(info.collider->x()+50, y());
            }
        }
        if(info.collide_from == Direction::Right){
            if(vx() > 0){
                setVx(-vx());
                setPos(info.collider->x()-50, y());
            }
        }
    }
    else{
        gravity();
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
