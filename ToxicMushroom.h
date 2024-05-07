#ifndef TOXICMUSHROOM_H
#define TOXICMUSHROOM_H


#include "Entity.h"

class Hitbox;

class ToxicMushroom : public Entity{
public:
    ToxicMushroom();
    void update();
private:
    void update_image();
    void collide_handler();
    QList<QString> walking_annimation;
    int walking_state;
    int animation_counter;

};
#endif // TOXICMUSHROOM_H
