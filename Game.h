#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

#include "Mario.h"
#include "Block.h"


class Game : public QObject{
    Q_OBJECT
public:

    Game();
    QTimer* getTick() const;
    void start();
    Mario *getPlayer() const;
    QGraphicsScene *getScene() const;
    QGraphicsView *getView() const;
    void setUpBackGround();
    QList<Block*> BlockList;
    QList<Object*> ObjectList;
    QList<Entity*> EntityList;
    QList<Hitbox*> HitboxList;
    int scroll_limit;

private:
    QTimer* tick;
    QTimer* DeadTimer;
    Mario* player;
    bool is_player_dying;
    QGraphicsScene* scene;
    QGraphicsView* view;

private slots:
    void update();
private:
    void playerDyingHandler();
};

#endif // GAME_H
