#include <QApplication>
#include "Game.h"

//game is in global so it can be accesed easily
Game* game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new Game();
    game->start();

    return app.exec();
}
