#ifndef ENDSCENE_H
#define ENDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "Config.h"
#include "TextBox.h"

class Restart : public QGraphicsPixmapItem{
public:
    Restart();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
private:
};

class EndScene : public QGraphicsScene{
public:
    EndScene();
private:
    TextBox* score;
    QGraphicsSimpleTextItem* text;
};

#endif // ENDSCENE_H
