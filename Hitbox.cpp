#include "Hitbox.h"
#include "Config.h"
#include "Game.h"
#include <QDebug>


extern Game* game;

Hitbox::Hitbox(Object *owner)
    :owner(owner)
{
    if(owner){
        game->HitboxList.push_back(this);
    }
#if DEBUG_HITBOX
    topRect = new QGraphicsRectItem(objtopRect);
    leftRect = new QGraphicsRectItem(objleftRect);
    rightRect = new QGraphicsRectItem(objrightRect);
    bottomRect = new QGraphicsRectItem(objbottomRect);
    game->getScene()->addItem(topRect);
    game->getScene()->addItem(leftRect);
    game->getScene()->addItem(rightRect);
    game->getScene()->addItem(bottomRect);
#endif
}

Hitbox::~Hitbox(){
    for(int i = 0; i < game->HitboxList.size(); i++){
        if(game->HitboxList[i] == this){
            game->HitboxList.removeAt(i);
            break;
        }
    }
}

bool Hitbox::getVisible()
{
    return visible;
}

void Hitbox::setVisible(bool sel)
{
    visible = sel;
}

void Hitbox::update()
{
    if(owner){
        boundingBox = owner->boundingRect();
        objtopRect.setRect(owner->x() + 4, owner->y(), boundingBox.width() - 8, 4);
        objbottomRect.setRect(owner->x() + 4, owner->y() + boundingBox.height()-2, owner->boundingRect().width() - 8, 4);
        objleftRect.setRect(owner->x(), owner->y() + 2, 4, boundingBox.height()-4);
        objrightRect.setRect(owner->x() + boundingBox.width() - 5, owner->y() + 2, 4, owner->boundingRect().height()-4);
        movingBox.setRect(owner->x(), owner->y(), boundingBox.width(), boundingBox.height());
    }
    else{
        this->remove();
    }
#if DEBUG_HITBOX
    topRect->setPos(mapFromScene(owner->x()+5, owner->y()));
    leftRect->setPos(mapFromScene(owner->x()+5, owner->y() + boundingBox.height()-2));
    rightRect->setPos(mapFromScene(owner->x(), owner->y() + 2));
    bottomRect->setPos(mapFromScene(owner->x() + boundingBox.width() - 5, owner->y() + 2));
#endif
}

