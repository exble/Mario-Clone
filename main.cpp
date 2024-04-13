#include <QApplication>
#include "Game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new Game(800,600);

    game->view();
    game->init();
    return app.exec();
}
