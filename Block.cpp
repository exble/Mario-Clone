#include "Block.h"
#include "Mario.h"
#include "Hitbox.h"

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
    mhitbox = new Hitbox(this);
}

