#include "Mario.h"
#include <QKeyEvent>
#include <QDebug>

Mario::Mario(Game* game)
:Object(game){
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    key = Key::NONE;
    key_pressed = 0;
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
}

void Mario::move(){
    if(key_pressed){
        //qDebug() << "key_pressed" << endl;
        if(key == Key::A){
            setPos(x()-10, y());
        }
        else if (key == Key::D){
            setPos(x()+10, y());
        }
    }
    key_pressed = 0;
}
