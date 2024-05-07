#ifndef MOUSEMOVE_H
#define MOUSEMOVE_H

#include <QGraphicsRectItem>

class MouseMove : public QGraphicsRectItem{
public:
    MouseMove();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    QPointF getCord();
private:
    QPointF cord;
};

#endif // MOUSEMOVE_H
