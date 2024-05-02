#ifndef MARIO_H
#define MARIO_H


#include <QKeyEvent>
#include "Entity.h"



class Hitbox;

class Mario : public Entity{
public:
    Mario();
    void update();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void CollideAtEvent(Direction dir, Object* collider);
    QRectF hitbox(char);
    void setState(State newState);

private:
    void controlHandler();
    void collideHandler();
    void stateUpdate();
    void update_image();
    void gravity();
    void friction();

    int twotick;
    enum class Key{W, A, S, D, NONE};
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    std::vector<bool> isKeyPressed;
    bool key_holding;
    QTimer* key_holding_timer;
    int walking_state;
    int animation_counter;
    Key key;
    Facing faceTo;
    State state;
    bool is_onground;
};
#endif // MARIO_H
