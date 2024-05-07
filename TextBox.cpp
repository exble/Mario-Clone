#include "TextBox.h"
#include "QFont"
#include "Game.h"
#include <string>

extern Game* game;

TextBox::TextBox(qreal x, qreal y)
    :x(x), y(y)
{
    QFont font("Times", 16, QFont::Black);
    setFont(font);
    connect(game->getTick(),SIGNAL(timeout()),this,SLOT(update()));
    setZValue(100);
}

void TextBox::setTitle(QString title)
{
    Title = title;
}

void TextBox::setDigit(int digit)
{
    Digit = std::to_string(digit).c_str();
}

void TextBox::update()
{
    setPos(fmin(game->scroll_limit, GAME_WIDTH - WINDOW_WIDTH) + x, y);
    setText(Title + "\n" + Digit);
}
