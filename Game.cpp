#include "Game.h"
#include "Mario.h"
#include "Constants.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

Game::Game(int p_width, int p_height){
    setSize(p_width, p_height);
    tick = new QTimer();
    tick->start(1000 / TICK_PER_SEC);
    connect(tick, SIGNAL(timeout()), this, SLOT(update()));
}



void Game::view(){
    game_scene = new QGraphicsScene();
    game_view = new QGraphicsView();
    game_view->setScene(game_scene);
    game_view->show();
    game_view->setFixedSize(width, height);
    game_scene->setSceneRect(0,0,width,height);
    game_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    game_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Game::setSize(int width, int height){
    this->width = width;
    this->height = height;
}

QTimer *Game::getTick() const{
    return tick;
}

void Game::init(){
    Mario* player = new Mario(this);
    player->setRect((width-100)/2,(height-100)/2,100,100);
    game_scene->addItem(player);
    player->setFocus();

}

int Game::getWidth() const
{
    return width;
}

int Game::getHeight() const
{
    return height;
}

void Game::update(){

}


