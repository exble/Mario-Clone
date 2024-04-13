#include "Object.h"
#include "Game.h"

Object::Object(Game* game){
    delete_flag = 0;
    my_game = game;
    world_tick = my_game->getTick();
    connect(world_tick, SIGNAL(timeout()), this, SLOT(delete_handler()));
}

Game* Object::getGame(){
    return my_game;
}

void Object::remove(){
    delete_flag = 1;
}

void Object::update()
{

}

void Object::delete_handler(){
    update();
    if(delete_flag){
        delete this;
    }
}

