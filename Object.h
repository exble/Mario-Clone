#ifndef OBJECT_H
#define OBJECT_H

#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Config.h"

class Hitbox;

class Hitbox;

class Object : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Object();
    void remove();
    void setCollision(bool sel);
    virtual void CollideAtEvent(Direction dir, Object* collider);
    Hitbox* mhitbox;
    virtual void update();
private slots:
    void update_handler();
private:
    bool is_collide;
    bool delete_flag;
};

#endif // OBJECT_H
