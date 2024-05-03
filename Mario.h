#ifndef MARIO_H
#define MARIO_H


#include <QKeyEvent>
#include <chrono>
#include "Entity.h"



class Hitbox;

class Mario : public Entity{
public:
    Mario();
    void update();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void Reset(qreal x, qreal y);
    State getState() const;

private:
    void controlHandler();
    void collideHandler();
    void stateUpdate();
    void updateImage();
    void gravity();
    void friction();
    void boundryCheck();
    void shootBullet();
    void setDead();
    enum class Key{W, A, S, D, NONE};
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    QList<QGraphicsItem*> Collisions;
    std::vector<bool> isKeyPressed;
    bool key_holding;
    QTimer* JumpTimer;
    std::chrono::high_resolution_clock jumpTime;
    int animation_state;
    int animation_counter;
    Key key;
    Facing faceTo;
    State state;
    bool is_onground;
};
#endif // MARIO_H
