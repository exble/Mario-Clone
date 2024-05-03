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

    ToxicMushroom* Toxic;
    Toxic = new ToxicMushroom();
    Toxic->setPos(600,400);
    scene->addItem(Toxic);

    Block* bl;
    bl = new Block(Blocks::Box);
    bl->setPos(500,500);
    scene->addItem(bl);
    BlockList.push_back(bl);
    bl = new Block(Blocks::Floor);
    bl->setPos(700,500);
    scene->addItem(bl);
    BlockList.push_back(bl);
    for(int i = 0; i < 150; i++){
        if(i >= 15 && i <= 18)
            continue;
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50, 600);
        scene->addItem(m_block);
    }
    scroll_limit = 0;
}

void Game::update()
{
    // set player on focus so that keyboard input can be obtain
    player->setFocus();

    // set scroll limit according to player x positon tod
    scroll_limit = std::max(player->x()-WINDOW_WIDTH/2, (double)scroll_limit);

    // focus view on player
    view->horizontalScrollBar()->setValue(scroll_limit);

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










