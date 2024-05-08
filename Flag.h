#ifndef Flag_H
#define Flag_H


#include "Entity.h"
#include <QSoundEffect>

class Hitbox;

class Flag : public Entity{
public:
    Flag(FlagPart, Flag* f = nullptr);
    void update();
    void setState(State newState);
    Facing faceTo;
private:
    QSoundEffect endSound;
    void stateUpdate();
    void collide_handler();
    int animation_counter;
    QTimer* EndTimer;
    bool is_trigger;
    bool is_end;
    State state;
    Flag* flag;
};

#endif // Flag_H
