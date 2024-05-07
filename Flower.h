#ifndef FLOWER_H
#define FLOWER_H

#include "Entity.h"

class Hitbox;

class Flower : public Entity{
public:
    Flower();
    void update();
private:
    void update_image();
    void collide_handler();
    void adjustFlowerPosition();
    QList<QString> walking_annimation;
    int walking_state;
    int animation_counter;

};

#endif // FLOWER_H
