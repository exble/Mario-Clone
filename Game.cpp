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
    QRectF blTopRect(bl->x(), bl->y(), bl->boundingRect().width(), 1);
    QRectF blBottomRect(bl->x(), bl->y() + bl->boundingRect().height() - 1, bl->boundingRect().width(), 1);
    QRectF blLeftRect(bl->x(), bl->y(), 1, bl->boundingRect().height());
    QRectF blRightRect(bl->x() + bl->boundingRect().width() - 1, bl->y(), 1, bl->boundingRect().height());


    //saperated hitbox
    QRectF playerTopRect(player->x(), player->y(), player->boundingRect().width(), 5);
    QRectF playerLeftRect(player->x()+10, player->y(), 5, player->boundingRect().height());
    QRectF playerRightRect(player->x() + player->boundingRect().width()-10 , player->y(), 5, player->boundingRect().height());
    QRectF playerBottomRect(player->x(), player->y() + player->boundingRect().height() -5 , player->boundingRect().width(), 5);
    qDebug() << "x: " << player->x() << "y: " << player->y();

    /*QGraphicsRectItem *playerTopBox = new QGraphicsRectItem(playerTopRect);
    QGraphicsRectItem *playerBottomBox = new QGraphicsRectItem(playerBottomRect);
    QGraphicsRectItem *playerLeftBox = new QGraphicsRectItem(playerLeftRect);
    QGraphicsRectItem *playerRightBox = new QGraphicsRectItem(playerRightRect);



    scene->addItem(playerTopBox);
    scene->addItem(playerBottomBox);
    scene->addItem(playerLeftBox);
    scene->addItem(playerRightBox);*/
    if (blTopRect.intersects(playerBottomRect) && player->vy() < 0)
    {
        // 停止玩家的垂直速度
        player->setVy(0);
    }
    if (blLeftRect.intersects(playerRightRect) && player->vx() > 0)
    {
        // 停止玩家的垂直速度
        player->setVx(0);
    }
    if (playerTopRect.intersects(blBottomRect) && player->vy() > 0)
    {
        // 停止玩家的垂直速度
        player->setVy(0);
    }
    if (playerLeftRect.intersects(blRightRect) && player->vx() < 0)
    {
        // 停止玩家的垂直速度
        player->setVx(0);
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




