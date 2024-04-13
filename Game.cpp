#include "Game.h"
#include "Mario.h"
#include "Constants.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

Game::Game(int p_width, int p_height){
    setSize(p_width, p_height);
    tick = new QTimer();
    tick->start(1000 / TICK_PER_SEC);
}

void Game::view(){
    game_scene = new QGraphicsScene();
    game_view = new QGraphicsView();
    game_view->setScene(game_scene);
    game_view->setFixedSize(width, height);
    game_view->show();
}

void Game::setSize(int width, int height){
    this->width = width;
    this->height = height;
}

QTimer *Game::getTick(){
    return tick;
}

void Game::init(){
    Mario* player = new Mario(this);
    player->setRect(0,0,100,100);
    game_scene->addItem(player);
    player->setFocus();
}
