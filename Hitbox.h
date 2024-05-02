#ifndef HITBOX_H
#define HITBOX_H

#include <QRectF>
#include "Object.h"


class Hitbox : public Object{
public:
    Hitbox(Object* owner, bool is_static);
    QRectF objtopRect;
    QRectF objbottomRect;
    QRectF objleftRect;
    QRectF objrightRect;
    QRectF movingBox;
    Object* owner;
    bool is_static;
    QRectF boundingBox;
    void update();
private:
    bool is_active;

};

#endif // HITBOX_H
