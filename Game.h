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
    void setSize(int width, int height);
    QTimer* getTick() const;
    int getWidth() const;
    int getHeight() const;
    QGraphicsScene* scene;
    QGraphicsView* view;
    void start();
    Mario *getPlayer() const;

    QGraphicsScene *getScene() const;

    QGraphicsView *getView() const;
    void updateBlockHitbox();
    void traceMario();
    void checkCollision();
    QList<Block*> BlockList;
    QList<Object*> ObjectList;
    QList<Entity*> EntityList;
    QList<Hitbox*> StaticHitboxList;


private:
    int width;
    int height;
    QTimer* tick;
    Mario* player;
private slots:
    void update();
};

#endif // GAME_H
