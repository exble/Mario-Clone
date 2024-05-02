#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QImage>
#include <QBrush>
#include <QDebug>
#include <QList>
#include <QRect>
#include "Game.h"
#include "Config.h"
#include "Hitbox.h"
#include "Entity.h"
#include "ToxicMushroom.h"
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
    player->setPos(500, 300);
    scene->addItem(player);
    player->setFocus();
    //player->hitbox = new Hitbox(player);

    ToxicMushroom* Toxic;
    Toxic = new ToxicMushroom();
    Toxic->setPos(600,400);
    scene->addItem(Toxic);

    Block* bl;
    bl = new Block(Blocks::Box);
    bl->setPos(500,400);
    scene->addItem(bl);
    BlockList.push_back(bl);
    bl = new Block(Blocks::Floor);
    bl->setPos(700,400);
    scene->addItem(bl);
    BlockList.push_back(bl);
    for(int i = 0; i < 30; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50, 500);
        scene->addItem(m_block);
    }
}

void Game::update()
{
    player->setFocus();



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










