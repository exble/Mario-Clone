#ifndef MARIO_H
#define MARIO_H

#include "Object.h"
#include <QKeyEvent>

class Mario : public Object{
public:
    Mario();
    void update();
    void keyPressEvent(QKeyEvent* event);
private:
    void move();
    enum class Facing{Left, Right};
    enum class Key{W, A, S, D, NONE};
    Key key;
    bool key_pressed;
};
#endif // MARIO_H
