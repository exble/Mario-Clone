#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QObject>
#include <QTimer>
#include "Config.h"

class Button : public QGraphicsPixmapItem, public QObject{
public:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:

};

class TitleScreen{
public:
    TitleScreen();
    QGraphicsScene* titleScene;
    Button* startbutton;
    QGraphicsPixmapItem* background;


private:
    void restart_tick();
};

#endif // TITLESCREEN_H
