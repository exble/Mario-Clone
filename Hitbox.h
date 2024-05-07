#ifndef HITBOX_H
#define HITBOX_H

#include <QRectF>
#include <QGraphicsRectItem>
#include "Object.h"


class Hitbox : public Object{
public:
    Hitbox(Object* owner);
    ~Hitbox();
    QRectF objtopRect;
    QRectF objbottomRect;
    QRectF objleftRect;
    QRectF objrightRect;
    QRectF movingBox;
    Object* owner;
    QRectF boundingBox;
    void update();
private:

};

#endif // HITBOX_H
