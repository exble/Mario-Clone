#include "TitleScreen.h"
#include "Game.h"

extern Game* game;

TitleScreen::TitleScreen()
{

    titleScene = new QGraphicsScene();
    background = new QGraphicsPixmapItem();
    startbutton = new Button();

    // deploy background and button
    background->setPixmap(QPixmap(":/images/image/start_screen.png"));
    startbutton->setPixmap(QPixmap(":/images/image/start_btn.png"));
    background->setPos(0, 0);
    startbutton->setPos(434, 454);
    titleScene->addItem(background);
    titleScene->addItem(startbutton);
}

// Below is Button class


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event){};
    game->setUpBackGround();
    game->getTick()->start();
    delete this;
}
