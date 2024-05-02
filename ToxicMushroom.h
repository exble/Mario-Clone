#ifndef TOXICMUSHROOM_H
#define TOXICMUSHROOM_H


#include "Entity.h"

class Hitbox;

class ToxicMushroom : public Entity{
public:
    ToxicMushroom();
    void update();
    void CollideAtEvent(Direction dir, Object* collider);
    QRectF hitbox(char);
    void setState(State newState);

private:
    void stateUpdate();
    void update_image();
    void gravity();
    int twotick;
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    int walking_state;
    int animation_counter;
    Facing faceTo;
    State state;
    bool is_onground;
};
#endif // TOXICMUSHROOM_H
