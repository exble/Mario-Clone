#ifndef OBJECT_H
#define OBJECT_H

#include <QTime>
#include <QGraphicsRectItem>
#include <QObject>
#include "Game.h"

class Object : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Object();
    void remove();
    virtual void update();
private slots:
    void update_handler();
private:
    bool delete_flag;
};

#endif // OBJECT_H
