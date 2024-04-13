#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game game(800,600);

    game.view();
    game.init();
    return app.exec();
}
