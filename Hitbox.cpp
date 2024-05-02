#include "Hitbox.h"
#include "Config.h"
#include "Game.h"
#include <QDebug>


extern Game* game;

Hitbox::Hitbox(Object *owner, bool is_static)
    :owner(owner),
    is_static(is_static)
{
    if(is_static){
        game->StaticHitboxList.push_back(this);
    }
#ifdef DEBUG_HITBOX
    topRect = new QGraphicsRectItem(objtopRect);
    leftRect = new QGraphicsRectItem(objleftRect);
    rightRect = new QGraphicsRectItem(objrightRect);
    bottomRect = new QGraphicsRectItem(objbottomRect);
    //topRect->setPen(QPen(Qt::green));
    //leftRect->setPen(QPen(Qt::green));
    //rightRect->setPen(QPen(Qt::green));
    //bottomRect->setPen(QPen(Qt::green));
    game->getScene()->addItem(topRect);
    game->getScene()->addItem(leftRect);
    game->getScene()->addItem(rightRect);
    game->getScene()->addItem(bottomRect);
#endif
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
    //setPos(owner->x(), owner->y());
    boundingBox = owner->boundingRect();
    objtopRect.setRect(owner->x()+5, owner->y(), boundingBox.width()-10, 4);
    objbottomRect.setRect(owner->x()+5, owner->y() + boundingBox.height()-2, owner->boundingRect().width()-10, 4);
    objleftRect.setRect(owner->x(), owner->y() + 2, 4, boundingBox.height()-4);
    objrightRect.setRect(owner->x() + boundingBox.width() - 5, owner->y() + 2, 4, owner->boundingRect().height()-4);
    movingBox.setRect(owner->x(), owner->y(), boundingBox.width(), boundingBox.height());
#ifdef DEBUG_HITBOX
    //topRect->setPos(mapFromScene(owner->x()+5, owner->y()));
    //leftRect->setPos(mapFromScene(owner->x()+5, owner->y() + boundingBox.height()-2));
    //rightRect->setPos(mapFromScene(owner->x(), owner->y() + 2));
    //bottomRect->setPos(mapFromScene(owner->x() + boundingBox.width() - 5, owner->y() + 2));
#endif
}

