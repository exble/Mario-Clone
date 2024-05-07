#include "Block.h"
#include "Mario.h"
#include "Hitbox.h"
#include "Game.h"
#include "Item.h"
#include "Mushroom.h"

extern Game* game;

Block::Block(Blocks block_type, Items item_type)
    :block_type(block_type),
    spawnType(item_type)
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
        setPixmap(QPixmap(":/images/image/brick/normal brick.png"));
        break;
    case Blocks::Pipe:
        setPixmap(QPixmap(":/images/image/brick/water pipe.png"));
        break;
    case Blocks::Stone:
        setPixmap(QPixmap(":/images/image/brick/stone brick.png"));
        break;
    }
    mhitbox = new Hitbox(this);
}

void Block::BlockEvent()
{
    if(block_type == Blocks::Broken){
        this->remove();
    }
    if(block_type == Blocks::Box){
        setPixmap(QPixmap(":/images/image/brick/stone brick.png"));
        if(spawnType == Items::SuperMushroom){
            Mushroom* mush = new Mushroom();
            mush->setPos(x(), y()-BLOCK_SIZE);
            game->getScene()->addItem(mush);
        }
        else{
            Item* it = new Item(spawnType);
            it->setPos(x(), y()-BLOCK_SIZE);
            game->getScene()->addItem(it);

        }
        spawnType = Items::None;
    }
}
