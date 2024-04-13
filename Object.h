#ifndef OBJECT_H
#define OBJECT_H

#include <QTime>
#include <QGraphicsRectItem>
#include <QObject>
#include "Game.h"

class Object : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Object(Game* game);
    Game* getGame();
    void set_world_tick(QTimer* timer);
    void remove();
    virtual void update();
private slots:
    void delete_handler();
private:
    QTimer* world_tick;
    Game* my_game;
    bool delete_flag;
};

#endif // OBJECT_H
