#include "Block.h"


Block::Block(Blocks block_type)
{
    switch (block_type){
    case Blocks::Box:
        setPixmap(QPixmap(":/images/image/brick/box brick.png"));
        break;
    case Blocks::Broken:
        setPixmap(QPixmap(":/images/image/brick/broken brick.png"));
        break;
    case Blocks::Floor:
        setPixmap(QPixmap(":/images/image/brick/floor brick.png"));
        break;
    case Blocks::Normal:
        setPixmap(QPixmap(":/images/image/brick/Normal brick.png"));
        break;
    case Blocks::Pipe:
        setPixmap(QPixmap(":/images/image/brick/Pipe brick.png"));
        break;
    case Blocks::Stone:
        setPixmap(QPixmap(":/images/image/brick/Stone brick.png"));
        break;
    }
}


QRectF Block::hitbox(char x)
{
    //get hitbox
    QRectF blocktopRect(this->x(), this->y(), this->boundingRect().width(), 1);
    QRectF blockbottomRect(this->x(), this->y() + this->boundingRect().height() - 1, this->boundingRect().width(), 1);
    QRectF blockleftRect(this->x(), this->y(), 1, this->boundingRect().height());
    QRectF blockrightRect(this->x() + this->boundingRect().width() - 1, this->y(), 1, this->boundingRect().height());

    if(x=='t')
        return blocktopRect;
    if(x=='b')
        return blockbottomRect;
    if(x=='l')
        return blockleftRect;
    if(x=='r')
        return blockrightRect;

    return blockrightRect;
}

