#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

class Game {
public:
    Game(int width, int height);
    void setSize(int width, int height);
    void view();
    QTimer* getTick();
    void init();
private:
    int width;
    int height;
    QTimer* tick;
    QGraphicsScene* game_scene ;
    QGraphicsView* game_view;
};

#endif // GAME_H
