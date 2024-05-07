#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

#include "BGM.h"
#include "Mario.h"
#include "Block.h"

class MouseMove;
class TextBox;

class Game : public QObject{
    Q_OBJECT
public:
    Game() = default;
    QTimer* getTick() const;
    void start();
    Mario *getPlayer() const;
    QGraphicsScene *getScene() const;
    QGraphicsView *getView() const;
    void setUpBackGround();
    void resetMap();
    MouseMove* mouse;
    QList<Block*> BlockList;
    QList<Object*> ObjectList;
    QList<Entity*> EntityList;
    QList<Hitbox*> HitboxList;
    int scroll_limit;
    TextBox* Score;
    TextBox* HP;
    TextBox* Ammo;
private:
    QTimer* tick;
    QTimer DeadTimer;
    QTimer mobspawn;
    Mario* player;
    BGM backgroundMusic;
    bool is_player_dying;
    QGraphicsScene* scene;
    QGraphicsView* view;

private slots:
    void update();
private:
    void playerDyingHandler();
};

#endif // GAME_H
