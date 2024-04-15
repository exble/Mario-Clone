#include <QKeyEvent>
#include <QDebug>
#include "Mario.h"

Mario::Mario():
    max_speed(MAX_SPEED){
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPixmap(QPixmap(":/images/image/Mario_big/mario_L_stand.png"));
    key = Key::NONE;
    faceTo = Facing::Left;
    state = State::Walking;
    key_pressed = false;
    //init timer = 20ms
    key_holding_timer = new QTimer();
    key_holding_timer->setSingleShot(true);
    key_holding = false;

    walking_annimation_L = {":/images/image/Mario_big/mario_L_run0.png",
                            ":/images/image/Mario_big/mario_L_run1.png",
                            ":/images/image/Mario_big/mario_L_run2.png"};
    walking_annimation_R = {":/images/image/Mario_big/mario_R_run0.png",
                            ":/images/image/Mario_big/mario_R_run1.png",
                            ":/images/image/Mario_big/mario_R_run2.png"};
    walking_state = 0;
    animation_counter = 0;
    setCollision(true);
}

void Mario::keyPressEvent(QKeyEvent* event){
    //qDebug() << "key_register" << endl;
    key_pressed = 1;
    if(event->key() == Qt::Key_W){
        key = Key::W;
    }
    else if (event->key() == Qt::Key_A){
        key = Key::A;
    }
    else if (event->key() == Qt::Key_S){
        key = Key::S;
    }
    else if (event->key() == Qt::Key_D){
        key = Key::D;
    }
    else {
        key = Key::NONE;
    }
}


void Mario::update(){
    if(key_pressed){
        qDebug() << "Key Pressed";
        //key board input register every 100ms
        key_holding_timer->start(100);
        key_holding = true;
    }
    if(key_holding_timer->isActive() == false){
        key_holding = false;
    }



    //change Mario State

    //move Marion
    move();


    // update the moving information

}

void Mario::move(){
    //move according to keyboard input
    if(key_holding){
        qDebug() << "key_holding";
        switch (key){
        case Key::W :
            setPos(x(), y()-5);
            break;
        case Key::A :
            faceTo = Facing::Left;
            state = State::Walking;
            update_image();
            setPos(x()-5, y());

            break;
        case Key::S :
            setPos(x(), y()+5);
            break;
        case Key::D :
            faceTo = Facing::Right;
            state = State::Walking;
            update_image();
            setPos(x()+5, y());

            break;
        default:
            break;
        }
    }
    else{
        state = State::Still;
        update_image();
    }
    key_pressed = false;
}

void Mario::update_image(){
    //change image according to state and facing
    if(state == State::Still){
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(":/images/image/Mario_big/mario_L_stand.png"));
        }
        else{
            setPixmap(QPixmap(":/images/image/Mario_big/mario_R_stand.png"));
        }
    }
    else if (state == State::Walking){
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

    }
}
