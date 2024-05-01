#include "Hitbox.h"
#include "Config.h"
#include<QDebug>

Hitbox::Hitbox(Object *owner)
    :owner(owner)
{
    if (owner)
        {
            QRectF objTopRect(owner->x(), owner->y(), owner->boundingRect().width(), 1);
            QRectF objBottomRect(owner->x(), owner->y() + owner->boundingRect().height() - 1, owner->boundingRect().width(), 1);
            QRectF objLeftRect(owner->x(), owner->y(), 1, owner->boundingRect().height());
            QRectF objRightRect(owner->x() + owner->boundingRect().width() - 1, owner->y(), 1, owner->boundingRect().height());
        }
        else
        {

            objtopRect = QRectF();
            objbottomRect = QRectF();
            objleftRect = QRectF();
            objrightRect = QRectF();
        }
}

void Hitbox::update()
{

 }
