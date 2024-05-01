#ifndef HITBOX_H
#define HITBOX_H

#include "Object.h"

class Hitbox : public Object{
public:
    Hitbox(Object* owner);
    QRectF objtopRect;
    QRectF objbottomRect;
    QRectF objleftRect;
    QRectF objrightRect;
    void update();
private:
    Object* owner;
    bool is_active;

};

#endif // HITBOX_H
