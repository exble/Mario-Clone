#include "Game.h"
#include "Config.h"
#include "Hitbox.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QImage>
#include <QBrush>
#include <QDebug>
#include <QList>
#include <QRect>
Game::Game(){

}

void Game::start()
{
    //setup QGraphicsView
    scene = new QGraphicsScene();
    view = new QGraphicsView();
    view->setScene(scene);
    view->show();
    setSize(GAME_WIDTH, GAME_HEIGHT);
    view->setFixedSize(width, height);
    scene->setSceneRect(0,0,width,height);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setup background
    scene->setBackgroundBrush(QBrush(QImage(":/images/image/background.png")));

    //setup tick and update()
    tick = new QTimer();
    tick->start(1000 / TICK_PER_SEC);
    connect(tick, SIGNAL(timeout()), this, SLOT(update()));
    //init game
    player = new Mario();
    player->setPos(500, 500);
    scene->addItem(player);
    player->setFocus();
    //player->hitbox = new Hitbox(player);


    bl = new Block(Blocks::Box);
    bl->setPos(500,250);
    scene->addItem(bl);
    //bl->hitbox = new Hitbox(bl);


}

void Game::update(){
    player->setFocus();


    //saperated hitbox
    /*QRectF blTopRect(bl->x(), bl->y(), bl->boundingRect().width(), 1);
    QRectF blBottomRect(bl->x(), bl->y() + bl->boundingRect().height() - 1, bl->boundingRect().width(), 1);
    QRectF blLeftRect(bl->x(), bl->y(), 1, bl->boundingRect().height());
    QRectF blRightRect(bl->x() + bl->boundingRect().width() - 1, bl->y(), 1, bl->boundingRect().height());*/


    //saperated hitbox
    QRectF playerTopRect(player->x()+1, player->y(), player->boundingRect().width()-2, 5);
    QRectF playerBottomRect(player->x()+1, player->y() + player->boundingRect().height() -5 , player->boundingRect().width()-2, 5);
    QRectF playerLeftRect(player->x()+10, player->y(), 5, player->boundingRect().height()-1);
    QRectF playerRightRect(player->x() + player->boundingRect().width()-10 , player->y(), 5, player->boundingRect().height()-1);

    qDebug() << "x: " << player->x() << "y: " << player->y();

    /*QGraphicsRectItem *playerTopBox = new QGraphicsRectItem(playerTopRect);
    QGraphicsRectItem *playerBottomBox = new QGraphicsRectItem(playerBottomRect);
    QGraphicsRectItem *playerLeftBox = new QGraphicsRectItem(playerLeftRect);
    QGraphicsRectItem *playerRightBox = new QGraphicsRectItem(playerRightRect);



    scene->addItem(playerTopBox);
    scene->addItem(playerBottomBox);
    scene->addItem(playerLeftBox);
    scene->addItem(playerRightBox);*/
    /*if (bl->hitbox('t').intersects(playerBottomRect) && player->vy() < 0)
    {
        player->setVy(0);
    }
    if (bl->hitbox('l').intersects(playerRightRect) && player->vx() > 0)
    {
        player->setVx(0);
    }
    if (playerTopRect.intersects(bl->hitbox('b')) && player->vy() > 0)
    {
        player->setVy(0);
    }
    if (playerLeftRect.intersects(bl->hitbox('r')) && player->vx() < 0)
    {
        player->setVx(0);
    }*/
    QList<QRectF> Righthitbox;
    QList<QRectF> Lefthitbox;
    QList<QRectF> Tophitbox;
    QList<QRectF> Bottomhitbox;
    Righthitbox.push_back( bl->hitbox('r'));
    Lefthitbox.push_back( bl->hitbox('l'));
    Tophitbox.push_back( bl->hitbox('t'));
    Bottomhitbox.push_back( bl->hitbox('b'));
    foreach (QRectF rect, Righthitbox)
    {
        if (playerLeftRect.intersects(rect) && player->vx() < 0)
        {
            player->setVx(0);
        }
    }
    foreach (QRectF rect, Lefthitbox)
    {
        if (rect.intersects(playerRightRect) && player->vx() > 0)
        {
            player->setVx(0);
        }
    }
    foreach (QRectF rect, Tophitbox)
    {
        if (rect.intersects(playerBottomRect) && player->vy() < 0)
        {
                player->setVy(0);
        }
    }
    foreach (QRectF rect, Bottomhitbox)
    {
        if (playerTopRect.intersects(rect) && player->vy() > 0)
        {
            player->setVy(0);
        }
    }
}

Mario *Game::getPlayer() const
{
    return player;
}

QGraphicsScene *Game::getScene() const
{
    return scene;
}

QGraphicsView *Game::getView() const
{
    return view;
}

void Game::setSize(int width, int height){
    this->width = width;
    this->height = height;
}

QTimer *Game::getTick() const{
    return tick;
}
int Game::getWidth() const
{
    return width;
}

int Game::getHeight() const
{
    return height;
}




