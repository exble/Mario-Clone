#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QScrollBar>
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
#include "Config.h"
#include "ToxicMushroom.h"
#include "TitleScreen.h"
#include "Flag.h"
#include "Map.h"
Game::Game(){

}

void Game::start()
{
    //setup QGraphicsView
    scene = new QGraphicsScene();
    view = new QGraphicsView();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setup tick and update()
    tick = new QTimer();
    tick->start(1000.0 / TICK_PER_SEC);
    connect(tick, SIGNAL(timeout()), this, SLOT(update()));

    //freeze main tick until title scene end
    tick->stop();

    //give control to TitleScreen
    TitleScreen ts;
    view->setFixedSize(TITLE_WIDTH, TITLE_HEIGHT);
    scene->setSceneRect(0,0,TITLE_WIDTH,TITLE_HEIGHT);
    view->setScene(ts.titleScene);
    view->show();

    //init game
    player = new Mario();
    player->setPos(500, 300);
    scene->addItem(player);
    player->setFocus();

    //init map
    Map::setUpMap();

    //Player dead init
    scroll_limit = 0;
    DeadTimer.setSingleShot(true);
    is_player_dying = false;
}

void Game::update()
{
    // If player state is Dying handle it
    playerDyingHandler();

    // set player on focus so that keyboard input can be obtain
    player->setFocus();

    // set scroll limit according to player x positon tod
    scroll_limit = std::max(player->x()-WINDOW_WIDTH/2, (double)scroll_limit);

    // focus view on player
    view->horizontalScrollBar()->setValue(scroll_limit);


}

void Game::playerDyingHandler()
{
    if(!DeadTimer.isActive() && is_player_dying){
        player->Reset(500, 300);
        is_player_dying = false;
        scroll_limit = 0;
    }
    else if(player->getState() == State::Dying && !is_player_dying){
        DeadTimer.start(2000);
        is_player_dying = true;
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

void Game::setUpBackGround()
{

    view->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    scene->setSceneRect(0,0,GAME_WIDTH,GAME_HEIGHT);
    scene->setBackgroundBrush(QBrush(QImage(":/images/image/background.png")));
    view->setScene(scene);

}

QTimer *Game::getTick() const{
    return tick;
}

