#ifndef MARIO_H
#define MARIO_H

#include "Object.h"
#include "Config.h"
#include <QKeyEvent>

class Mario : public Object{
public:
    Mario();
    void update();
    void keyPressEvent(QKeyEvent* event);
private:
    void move();

    void update_image();

    enum class State{Jumping, Still, Walking};
    enum class Key{W, A, S, D, NONE};
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    bool key_holding;
    QTimer* key_holding_timer;
    int walking_state;
    int animation_counter;
    float velocity;
    const float max_speed;
    Key key;
    Facing faceTo;
    State state;
    bool key_pressed;
};
#endif // MARIO_H
