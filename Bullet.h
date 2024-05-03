#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity{
public:
    Bullet(Facing dir);
    QList<QGraphicsItem*> collisions;
private:
    void update();
};

#endif // BULLET_H
