#include "Object.h"
#include "Game.h"
#include "Hitbox.h"

extern Game* game;

Object::Object(){
    mhitbox = nullptr;
    delete_flag = 0;
    is_collide = 0;
    connect(game->getTick(), SIGNAL(timeout()), this, SLOT(update_handler()));
    game->ObjectList.push_back(this);
}

void Object::remove(){
    delete_flag = 1;
}

void Object::setCollision(bool sel)
{
    is_collide = sel;
}

void Object::CollideAtEvent(Direction dir, Object* collider)
{
    if(dir == Direction::Up){

    }
    if(collider == 0){

    }
}

//this function will run for every tick
void Object::update()
{

}



void Object::update_handler(){
    update();
    if(delete_flag){
        delete this;
    }
}

