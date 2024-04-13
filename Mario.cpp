#include <QKeyEvent>
#include <QDebug>
#include "Mario.h"

Mario::Mario(): Object(){
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPixmap(QPixmap(":/images/image/Mario_big/mario_L_stand.png"));
    key = Key::NONE;
    faceTo = Facing::Left;
    state = State::Still;
    key_pressed = 0;
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

    move();
    //if(x()<0 || x()>getGame()->)
}

void Mario::move(){
    //move according to keyboard input
    if(key_pressed){
        //qDebug() << "key_pressed" << endl;
        switch (key){
        case Key::W :

            setPos(x(), y()-10);
            break;
        case Key::A :
            faceTo = Facing::Left;
            update_image();
            setPos(x()-10, y());
            break;
        case Key::S :
            setPos(x(), y()+10);
            break;
        case Key::D :
            faceTo = Facing::Right;
            update_image();
            setPos(x()+10, y());
            break;
        default:
            break;
        }
    }
    key_pressed = 0;
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

    }
    else if (state == State::Jumping){

    }
}
