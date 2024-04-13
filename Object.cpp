#include "Object.h"
#include "Game.h"

extern Game* game;

Object::Object(){
    delete_flag = 0;
    connect(game->getTick(), SIGNAL(timeout()), this, SLOT(update_handler()));
}

void Object::remove(){
    delete_flag = 1;
}

void Object::update()
{

}

void Object::update_handler(){
    update();
    if(delete_flag){
        delete this;
    }
}

