#include "EndScene.h"
#include "Game.h"
#include <QFont>
#include <QGraphicsSimpleTextItem>

extern Game* game;

EndScene::EndScene()
{
    setBackgroundBrush(QBrush(QImage(":/images/image/background.png")));
    setSceneRect(0, 0, END_WIDTH, END_HEIGHT);


    text = new QGraphicsSimpleTextItem();
    text->setPos(END_WIDTH/2 - 50, END_HEIGHT/2 - 100 - 30);
    text->setText(QString("Score\n   ") + std::to_string(game->getPlayer()->score).c_str());
    text->setFont(QFont("Times", 32, QFont::Black));
    addItem(text);
    Restart* res = new Restart();
    addItem(res);
}

Restart::Restart()
{
    setPixmap(QPixmap(":/images/image/Replay.png").scaled(100, 100));
    setPos(END_WIDTH/2 - 50, END_HEIGHT/2);
}

void Restart::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event){}
    game->cleanUp();
    game->start();
}
