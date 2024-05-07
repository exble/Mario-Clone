#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H

#include "Entity.h"

class Hitbox;

class KoopaTroopa : public Entity{
public:
    KoopaTroopa();
    void update();
private:
    void update_image();
    void collide_handler();
    QList<QString> walking_annimation;
    int walking_state;
    int animation_counter;
    bool status_change;
};

#endif // KOOPATROOPA_H
