#include "Item.h"
#include "Hitbox.h"
#include "Mario.h"
#include "Block.h"

Item::Item(Items item_type)
    :item_type(item_type)
{
    switch(item_type){
    case Items::Coin:
        setPixmap(QPixmap(":/images/image/item/coin.png"));
        break;
    case Items::FireFlower:
        setPixmap(QPixmap(":/images/image/item/Fire Flower.png"));
        break;
    case Items::SuperMushroom:
        setPixmap(QPixmap(":/images/image/item/super mushroom.png"));
        break;
    default:
        break;
    }
}

void Item::update()
{
    collider = collidingItems();
    Mario* player;
    foreach(QGraphicsItem* item, collider){
        player = dynamic_cast<Mario*>(item);
        if(player){
            switch(item_type){
            case Items::Coin:
                player->addPoint();
                break;
            case Items::FireFlower:
                player->addBullet();
                break;
            default:
                break;
            }
            this->remove();
            break;
        }
    }

}

