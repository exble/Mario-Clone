#ifndef TOXICMUSHROOM_H
#define TOXICMUSHROOM_H


#include "Entity.h"

class Hitbox;

class ToxicMushroom : public Entity{
public:
    ToxicMushroom();
    void update();
    void setState(State newState);
    Facing faceTo;
private:
    void stateUpdate();
    void update_image();
    void collide_handler();
    void gravity();
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    int walking_state;
    int animation_counter;
    State state;
};
#endif // TOXICMUSHROOM_H
