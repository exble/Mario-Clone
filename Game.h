#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

class Game : public QObject{
    Q_OBJECT
public:
    Game(int width, int height);
    void setSize(int width, int height);
    void view();
    QTimer* getTick() const;
    void init();
    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;
    QTimer* tick;
    QGraphicsScene* game_scene ;
    QGraphicsView* game_view;
private slots:
    void update();
};

#endif // GAME_H
