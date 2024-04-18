#ifndef MARIO_H
#define MARIO_H

#include "Entity.h"
#include <QKeyEvent>

class Mario : public Entity{
public:
    Mario();
    void update();
    void keyPressEvent(QKeyEvent* event);
private:
    void controlHandler();
    void stateUpdate();
    void update_image();
    void gravity();
    void friction();

    enum class State{Jumping, Falling, Stop, Running};
    enum class Key{W, A, S, D, NONE};
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    bool key_holding;
    QTimer* key_holding_timer;
    int walking_state;
    int animation_counter;

    Key key;
    Facing faceTo;
    State state;
    bool key_pressed;
};
#endif // MARIO_H
