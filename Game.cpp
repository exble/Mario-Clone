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

    Block* bl;
    bl = new Block(Blocks::Box);
    bl->setPos(500,250);
    scene->addItem(bl);
    BlockList.push_back(bl);
    bl = new Block(Blocks::Floor);
    bl->setPos(400,250);
    scene->addItem(bl);
    BlockList.push_back(bl);
    for(int i = 0; i < 30; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50, 500);
        scene->addItem(m_block);
    }
}

void Game::update(){
    player->setFocus();

    updateBlockHitbox();
    traceMario();
    checkCollision();

    qDebug() << "x: " << player->x() << "y: " << player->y();
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

void Game::updateBlockHitbox()
{
    Righthitbox.clear();
    Lefthitbox.clear();
    Tophitbox.clear();
    Bottomhitbox.clear();
    foreach(Block* m_block, BlockList){
        Righthitbox.push_back(m_block->hitbox('r'));
        Lefthitbox.push_back( m_block->hitbox('l'));
        Tophitbox.push_back( m_block->hitbox('t'));
        Bottomhitbox.push_back( m_block->hitbox('b'));
    }
}
void Game::traceMario()
{
    //saperated hitbox
    playerTopRect.setRect(player->x()+1, player->y(), player->boundingRect().width()-2, 5);
    playerBottomRect.setRect(player->x()+1, player->y() + player->boundingRect().height() -5 , player->boundingRect().width()-2, 5);
    playerLeftRect.setRect(player->x()+10, player->y(), 5, player->boundingRect().height()-1);
    playerRightRect.setRect(player->x() + player->boundingRect().width()-10 , player->y(), 5, player->boundingRect().height()-1);
}
void Game::checkCollision()
{
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
            player->setState(State::Stop);
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






