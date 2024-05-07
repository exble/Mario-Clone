#include "MouseMove.h"
#include "Game.h"
#include <QGraphicsSceneMouseEvent>

extern Game* game;

MouseMove::MouseMove()
{
    setRect(0, 80, 7000, 620);
    game->getScene()->addItem(this);
}

void MouseMove::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    cord = event->pos();
    game->getPlayer()->shootBullet(cord);
}

QPointF MouseMove::getCord()
{
    return cord;
}

