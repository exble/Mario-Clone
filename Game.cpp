#include "Game.h"
#include "Constants.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QImage>
#include <QBrush>

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
    scene->addItem(player);
    player->setFocus();

    Block* block = new Block(Blocks::Box);
    scene->addItem(block);
}

void Game::update(){
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




