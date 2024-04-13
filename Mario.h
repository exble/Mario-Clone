#ifndef MARIO_H
#define MARIO_H

#include "Object.h"
#include "Constants.h"
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
    Key key;
    Facing faceTo;
    State state;
    bool key_pressed;
};
#endif // MARIO_H
