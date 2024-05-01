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

/*
QRectF Block::hitbox(char x)
{
    //get hitbox
    QRectF boundingBox = this ->boundingRect();
    QRectF blocktopRect(boundingBox.topLeft(), QPointF(boundingBox.topRight().x(), boundingBox.topRight().y()));
    QRectF blockbottomRect(QPointF(boundingBox.bottomLeft().x() , boundingBox.bottomLeft().y()), boundingBox.bottomRight());
    QRectF blockleftRect(QPointF(boundingBox.topLeft().x() , boundingBox.topLeft().y()), boundingBox.bottomLeft());
    QRectF blockrightRect(QPointF(boundingBox.topRight().x() , boundingBox.topRight().y()), boundingBox.bottomRight());

    if(x=='t')
        return blocktopRect;
    if(x=='b')
        return blockbottomRect;
    if(x=='l')
        return blockleftRect;
    if(x=='r')
        return blockrightRect;

    return blockrightRect;
}*/

