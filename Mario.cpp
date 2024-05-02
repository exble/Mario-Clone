#include <QKeyEvent>
#include <QDebug>

#include "Mario.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Game.h"


extern Game* game;

Mario::Mario()
    {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPixmap(QPixmap(":/images/image/Mario_small/s_mario_stand_L.png"));
    key = Key::NONE;
    faceTo = Facing::Left;
    state = State::Stop;
    isKeyPressed.assign(30,0);
    walking_annimation_L = {":/images/image/Mario_small/s_mario_run1_L.png",
                            ":/images/image/Mario_small/s_mario_run2_L.png"};
    walking_annimation_R = {":/images/image/Mario_small/s_mario_run1_R.png",
                            ":/images/image/Mario_small/s_mario_run2_R.png"};
    walking_state = 0;
    animation_counter = 0;
    setCollision(true);
    mhitbox = new Hitbox(this, false);
}

void Mario::keyPressEvent(QKeyEvent* event){

    if(event->key() == Qt::Key_W){
        isKeyPressed[(int)Key::W] = true;
    }
    if (event->key() == Qt::Key_A){
        isKeyPressed[(int)Key::A] = true;
    }
    if (event->key() == Qt::Key_S){
        isKeyPressed[(int)Key::S] = true;
    }
    if (event->key() == Qt::Key_D){
        isKeyPressed[(int)Key::D] = true;
    }
}

void Mario::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        isKeyPressed[(int)Key::W] = false;
    }
    if (event->key() == Qt::Key_A){
        isKeyPressed[(int)Key::A] = false;
    }
    if (event->key() == Qt::Key_S){
        isKeyPressed[(int)Key::S] = false;
    }
    if (event->key() == Qt::Key_D){
        isKeyPressed[(int)Key::D] = false;
    }
}

void Mario::CollideAtEvent(Direction dir, Object* collider)
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
            setVx(0);
            setPos(collider->x()+50, y());
        }
    }
    if(dir == Direction::Down){
        //qDebug() << time(NULL) << "Collide Down";
        if(vy() < 0){
            setVy(0);
            state = State::Stop;
            is_onground = true;
            setPos(x(), collider->y() - 50);
        }
    }
    if(dir == Direction::Right){
        //qDebug() << time(NULL) << "Collide Right";
        if(vx() > 0){
            setVx(0);
            setPos(collider->x()-50, y());
        }
    }
}

void Mario::update(){
    friction();


    collideHandler();
    // update xx and vy accoding to key input
    controlHandler();

    // with vx determine facing and state
    stateUpdate();

    // update image according to facing and state
    update_image();

    // move according to Mario's vx and vy
    move();
    qDebug() << "vx: " << vx() << "vy: " << vy();
    qDebug() << "x: " << x() << "y: " << y();

}

void Mario::stateUpdate(){
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

void Mario::controlHandler(){
    //move according to keyboard input
    if(isKeyPressed[(int)Key::W] /*&& !(state == State::Jumping || state == State::Falling)*/){
        setVy(vy() + 0.2);
        state = State::Jumping;
    }
    if(isKeyPressed[(int)Key::A]){
        setVx(fmax(vx() - SEC_TO_TICK(WALKING_ACCELERATION_PER_SEC), -MAX_SPEED));
    }
    if(isKeyPressed[(int)Key::S]){

    }
    if(isKeyPressed[(int)Key::D]){
        setVx(fmin(vx() + SEC_TO_TICK(WALKING_ACCELERATION_PER_SEC), MAX_SPEED));
    }
}

void Mario::collideHandler()
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
                setVx(0);
                setPos(info.collider->x()+50, y());
            }
        }
        if(info.collide_from == Direction::Right){
            if(vx() > 0){
                setVx(0);
                setPos(info.collider->x()-50, y());
            }
        }
    }
    else{
        gravity();
    }
}

void Mario::update_image(){
    //change image according to state and facing
    if(state == State::Stop){
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(":/images/image/Mario_small/s_mario_stand_L.png"));
        }
        else{
            setPixmap(QPixmap(":/images/image/Mario_small/s_mario_stand_R.png"));
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
    else if (state == State::Jumping){
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(":/images/image/Mario_small/s_mario_jump1_L.png"));
        }
        else {
            setPixmap(QPixmap(":/images/image/Mario_small/s_mario_jump1_R.png"));
        }
    }
    else if (state == State::Falling){

    }
}

void Mario::gravity()
{
    setVy(fmax(vy() - SEC_TO_TICK(GRAVITATIONAL_ACCELERATION_PER_SEC), -10));
}

void Mario::friction()
{
    if(abs(vx()) < EPSILON){
        setVx(0);
    }
    else if(vx() > 0){
        setVx(vx()-SEC_TO_TICK(FRICTION_ACCELERATION_PER_SEC));
    }
    else if(vx() < 0){
        setVx(vx()+SEC_TO_TICK(FRICTION_ACCELERATION_PER_SEC));
    }
    setVx(0.999*vx());
}

void Mario::setState(State newState)
{
    state = newState;
}
