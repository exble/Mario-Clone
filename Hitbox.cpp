#include "Hitbox.h"
#include "Config.h"
#include "Game.h"
#include <QDebug>
#include <QGraphicsRectItem>

extern Game* game;

Hitbox::Hitbox(Object *owner, bool is_static)
    :owner(owner),
    is_static(is_static)
{

    if(is_static){
        game->StaticHitboxList.push_back(this);
    }

}

void Hitbox::update()
{
    setPos(owner->x(), owner->y());
    boundingBox = owner->boundingRect();
    objtopRect.setRect(owner->x()+5, owner->y(), boundingBox.width()-10, 4);
    objbottomRect.setRect(owner->x()+5, owner->y() + boundingBox.height()-2, owner->boundingRect().width()-10, 4);
    objleftRect.setRect(owner->x(), owner->y() + 2, 3, boundingBox.height()-4);
    objrightRect.setRect(owner->x() + boundingBox.width() - 1, owner->y() + 2, 3, owner->boundingRect().height()-4);
    movingBox.setRect(owner->x(), owner->y(), boundingBox.width(), boundingBox.height());
}

