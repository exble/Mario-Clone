#ifndef MARIO_H
#define MARIO_H


#include <QKeyEvent>
#include <chrono>
#include <QSoundEffect>
#include "Entity.h"



class Hitbox;

class Mario : public Entity{
public:
    Mario();
    void update();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void Reset(qreal x, qreal y);
    void addPoint();
    void beBig();
    void addBullet();
    State getState() const;
    void shootBullet(QPointF);
    int score;
    int hp;
    int ammo;
private:
    void controlHandler();
    void collideHandler();
    void stateUpdate();
    void updateImage();
    void friction();
    void boundryCheck();

    QSoundEffect jumpSound;
    QSoundEffect shootSound;

    void setDead();
    enum class Key{W, A, S, D, NONE};
    QList<QString> walking_annimation_L;
    QList<QString> walking_annimation_R;
    QList<QString> walking_annimation_L_big;
    QList<QString> walking_annimation_R_big;
    QList<QGraphicsItem*> Collisions;
    std::vector<bool> isKeyPressed;
    bool key_holding;
    bool is_big;
    bool is_invinsible;
    QTimer* JumpTimer;
    QTimer* InvincibleTimer;
    std::chrono::high_resolution_clock jumpTime;
    int animation_state;
    int animation_counter;

    Key key;
    Facing faceTo;
    State state;
    bool is_onground;
};
#endif // MARIO_H
