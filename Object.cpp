#include "Object.h"
#include "Game.h"
#include "Hitbox.h"
#include <typeinfo>
#include <string>
#include <QDebug>

extern Game* game;

Object::Object(){
    mhitbox = nullptr;
    delete_flag = false;
    is_collide = 0;
    connect(game->getTick(), SIGNAL(timeout()), this, SLOT(update_handler()));
    game->ObjectList.push_back(this);
}

Object::~Object()
{
    disconnect(game->getTick(),SIGNAL(timeout()), this, SLOT(update_handler()));
    for(int i = 0; i < game->ObjectList.size(); i++){
        if(game->ObjectList[i] == this){
            game->ObjectList.removeAt(i);
            break;
        }
    }
    if(mhitbox){
        mhitbox->remove();
    }
    game->getScene()->removeItem(this);
#if DEBUG_REMOVE
    qDebug() << name.c_str() << "is removed";
#endif
}

void Object::remove(){
    name = typeid(*this).name();
    delete_flag = true;
}

void Object::setCollision(bool sel)
{
    is_collide = sel;
}

//this function will run for every tick
void Object::update()
{

}



void Object::update_handler(){
    if(!delete_flag)
        update();
    else{
        delete this;
    }
}

bool Object::IsoutOfBound()
{
    if(x() < - BLOCK_SIZE || x() > GAME_WIDTH || y() < 0 || y() > GAME_HEIGHT + BLOCK_SIZE){
        return true;
    }
    return false;
}


