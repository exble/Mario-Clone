#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item: public Entity{
public:
    Item(Items item_type);
    Items item_type;
private:
    void update();
    QList<QGraphicsItem*> collider;
    void collideHandler();
    QTimer* coinTimer;
    bool is_moving;
};

#endif // ITEM_H
