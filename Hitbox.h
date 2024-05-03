#ifndef HITBOX_H
#define HITBOX_H

#include <QRectF>
#include <QGraphicsRectItem>
#include "Object.h"


class Hitbox : public Object{
public:
    Hitbox(Object* owner, bool is_static);
    QRectF objtopRect;
    QRectF objbottomRect;
    QRectF objleftRect;
    QRectF objrightRect;
    QRectF movingBox;
    QGraphicsRectItem* topRect;
    QGraphicsRectItem* leftRect;
    QGraphicsRectItem* rightRect;
    QGraphicsRectItem* bottomRect;
    Object* owner;
    bool is_collision_on;
    bool getVisible();
    void setVisible(bool);
    QRectF boundingBox;
    void update();
private:
    bool is_active;
    bool visible;
};

#endif // HITBOX_H
