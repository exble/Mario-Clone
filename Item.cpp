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
    is_moving = false;
    coinTimer = new QTimer();
    coinTimer->setSingleShot(true);
}

void Item::update()
{
    if(item_type == Items::Coin){
        if(!is_moving && vy()!=0){
            is_moving = true;
            coinTimer->start(200);
        }
        else if(is_moving && !coinTimer->isActive()){
            this->remove();
        }
    }


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

