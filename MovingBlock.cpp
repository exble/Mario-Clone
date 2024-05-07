#include "MovingBlock.h"
#include "Hitbox.h"

MovingBlock::MovingBlock(Blocks block_type)
    :block_type(block_type)
{
    switch (block_type){
    case Blocks::Broken:
        setPixmap(QPixmap(":/images/image/brick/broken brick.png"));
        break;
    case Blocks::Normal:
        setPixmap(QPixmap(":/images/image/brick/normal brick.png"));
        break;
    case Blocks::Stone:
        setPixmap(QPixmap(":/images/image/brick/stone brick.png"));
        break;
    default:
        break;
    }
    mhitbox = new Hitbox(this);
    setVy(2);
}

void MovingBlock::update()
{
    if(y() >= GAME_HEIGHT){
        setPos(x(), -50);
    }
    else if(y() <= -50){
        setPos(x(), GAME_HEIGHT);
    }
    move();
}
