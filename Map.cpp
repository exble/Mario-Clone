#include "Map.h"
#include "Game.h"
#include "Flag.h"
#include "Config.h"
#include "ToxicMushroom.h"
#include "TextBox.h"
#include "Flower.h"
#include "Item.h"
#include "KoopaTroopa.h"
#include "MovingBlock.h"

extern Game* game;

Map::Map()
{
    connect(game->getTick(), SIGNAL(timeout()), this, SLOT(update()));
}

void Map::__setUpMap()
{
    QGraphicsScene* scene = game->getScene();
    auto& BlockList = game->BlockList;
    for(int i = 0; i < 30; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50, 600);
        scene->addItem(m_block);
    }

    KoopaTroopa* koop = new KoopaTroopa();
    koop->setPos(300, 400);
    scene->addItem(koop);

    ToxicMushroom* toxic = new ToxicMushroom();
    toxic->setPos(100, 200);
    toxic->setVx(1);
    scene->addItem(toxic);

    Block* bl;



    bl = new Block(Blocks::Box, Items::SuperMushroom);
    bl->setPos(700,450);
    scene->addItem(bl);
    BlockList.push_back(bl);

    bl = new Block(Blocks::Box, Items::FireFlower);
    bl->setPos(900,300);
    scene->addItem(bl);
    BlockList.push_back(bl);


    Block* norm;
    Item* item;
    for(int i=0;i<3;i++){
        norm = new Block(Blocks::Normal);
        norm->setPos(850+i*50,450);
        scene->addItem(norm);
        BlockList.push_back(norm);

        item = new Item(Items::Coin);
        item->setPos(850+i*50, 400);
        scene->addItem(item);
    }

    Block* pipe;
    pipe = new Block(Blocks::Pipe);
    pipe->setPos(1150,500);
    scene->addItem(pipe);
    BlockList.push_back(pipe);

    //vicious Flower
    Flower* flower = new Flower();
    flower->setPos(300,535);
    scene->addItem(flower);
    flower->setZValue(10);

    pipe = new Block(Blocks::Pipe);
    pipe->setPos(150,500);
    scene->addItem(pipe);
    BlockList.push_back(pipe);

    Block* stone;
    for(int i=0;i<3;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(1350+i*50,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }

    MovingBlock* m_block = new MovingBlock(Blocks::Normal);
    m_block->setPos(1550, 330);
    scene->addItem(m_block);

    m_block = new MovingBlock(Blocks::Normal);
    m_block->setPos(1550, 660);
    scene->addItem(m_block);

    stone = new Block(Blocks::Stone);
    stone->setPos(1400,550);
    scene->addItem(stone);
    BlockList.push_back(stone);
    stone = new Block(Blocks::Stone);
    stone->setPos(1450,550);
    scene->addItem(stone);
    BlockList.push_back(stone);
    stone = new Block(Blocks::Stone);
    stone->setPos(1450,500);
    scene->addItem(stone);
    BlockList.push_back(stone);


    for(int i = 0; i < 30; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50+1700, 600);
        scene->addItem(m_block);
    }
    for(int i=0;i<3;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(1700+i*50,450+i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    stone = new Block(Blocks::Stone);
    stone->setPos(1700,500);
    scene->addItem(stone);
    BlockList.push_back(stone);
    stone = new Block(Blocks::Stone);
    stone->setPos(1700,550);
    scene->addItem(stone);
    BlockList.push_back(stone);
    stone = new Block(Blocks::Stone);
    stone->setPos(1750,550);
    scene->addItem(stone);
    BlockList.push_back(stone);

    toxic = new ToxicMushroom();
    toxic->setPos(1900, 550);
    scene->addItem(toxic);

    Block* broken;
    for(int i=0;i<3;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(2050+i*250,450-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);

        broken = new Block(Blocks::Broken);
        broken->setPos(2000+i*250,450-i*50);
        scene->addItem(broken);
        BlockList.push_back(broken);

        broken = new Block(Blocks::Broken);
        broken->setPos(2100+i*250,450-i*50);
        scene->addItem(broken);
        BlockList.push_back(broken);

        broken = new Block(Blocks::Stone);
        broken->setPos(1950+i*50,250);
        scene->addItem(broken);
        BlockList.push_back(broken);
    }
    stone = new Block(Blocks::Stone);
    stone->setPos(2250,250);
    scene->addItem(stone);
    BlockList.push_back(stone);
    broken = new Block(Blocks::Broken);
    broken->setPos(2300,250);
    scene->addItem(broken);
    BlockList.push_back(broken);
    broken = new Block(Blocks::Broken);
    broken->setPos(2200,250);
    scene->addItem(broken);
    BlockList.push_back(broken);

    bl = new Block(Blocks::Box, Items::Coin);
    bl->setPos(2000,100);
    scene->addItem(bl);
    BlockList.push_back(bl);


    for(int i=0;i<3;i++){
        Block* pipe;
        pipe = new Block(Blocks::Pipe);
        pipe->setPos(2450+i*200,500);
        scene->addItem(pipe);
        BlockList.push_back(pipe);

        toxic = new ToxicMushroom();
        toxic->setPos(2460+i*200, 500);
        scene->addItem(toxic);
    }

    for(int i=0;i<2;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(3150+i*50,500);
        scene->addItem(stone);
        BlockList.push_back(stone);
        stone = new Block(Blocks::Stone);
        stone->setPos(3500+i*50,500);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i=0;i<3;i++){
        //Block* norm;
        norm = new Block(Blocks::Normal);
        norm->setPos(3300+i*50,400);
        scene->addItem(norm);
        BlockList.push_back(norm);
    }

    bl = new Block(Blocks::Box, Items::SuperMushroom);
    bl->setPos(3350,250);
    scene->addItem(bl);
    BlockList.push_back(bl);

    for(int i = 0; i < 15; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50+3550, 600);
        scene->addItem(m_block);
    }



    for(int i=0;i<4;i++){

        norm = new Block(Blocks::Normal);
        norm->setPos(3800+i*50,450);
        scene->addItem(norm);
        BlockList.push_back(norm);

        broken = new Block(Blocks::Broken);
        broken->setPos(4150+i*50,250);
        scene->addItem(broken);
        BlockList.push_back(broken);

        broken = new Block(Blocks::Broken);
        broken->setPos(4450+i*50,200);
        scene->addItem(broken);
        BlockList.push_back(broken);
    }
    for(int i=0;i<2;i++){

        norm = new Block(Blocks::Normal);
        norm->setPos(3850+i*50,300);
        scene->addItem(norm);
        BlockList.push_back(norm);

        broken = new Block(Blocks::Broken);
        broken->setPos(3800+i*150,300);
        scene->addItem(broken);
        BlockList.push_back(broken);

        stone = new Block(Blocks::Stone);
        stone->setPos(3850+i*50,150);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i = 0; i < 16; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50+4500, 600);
        scene->addItem(m_block);
    }

    for(int i=0;i<3;i++){
        pipe = new Block(Blocks::Pipe);
        pipe->setPos(i*250+4700,500);
        scene->addItem(pipe);
        BlockList.push_back(pipe);
    }


    for(int i = 0; i < 40; i++){
        Block* m_block = new Block(Blocks::Floor);
        BlockList.push_back(m_block);
        m_block->setPos(i*50+5500, 600);
        scene->addItem(m_block);
    }

    for(int i=0;i<3;i++){
        pipe = new Block(Blocks::Pipe);
        pipe->setPos(i*350+5500,500);
        scene->addItem(pipe);
        BlockList.push_back(pipe);

        toxic = new ToxicMushroom();
        toxic->setPos(i*350+5510, 550);
        scene->addItem(toxic);
    }

    for(int i=0;i<5;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(i*50+4850,350);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }

    bl = new Block(Blocks::Box, Items::SuperMushroom);
    bl->setPos(4950,200);
    scene->addItem(bl);
    BlockList.push_back(bl);

    m_block = new MovingBlock(Blocks::Normal);
    m_block->setPos(5350, 300);
    m_block->setVy(-10);
    scene->addItem(m_block);

    m_block = new MovingBlock(Blocks::Normal);
    m_block->setPos(5400, 300);
    m_block->setVy(-10);
    scene->addItem(m_block);

    for(int i=0;i<2;i++){
        norm = new Block(Blocks::Normal);
        norm->setPos(5650+i*50,400);
        scene->addItem(norm);
        BlockList.push_back(norm);

        norm = new Block(Blocks::Normal);
        norm->setPos(i*200+4850,300);
        scene->addItem(norm);
        BlockList.push_back(norm);


        norm = new Block(Blocks::Normal);
        norm->setPos(6000+i*50,400);
        scene->addItem(norm);
        BlockList.push_back(norm);
    }

    for(int i=0;i<6;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(6400+i*50,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i=0;i<5;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(6450+i*50,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i=0;i<4;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(6500+i*50,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i=0;i<3;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(6550+i*50,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i=0;i<2;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(6600+i*50,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    for(int i=0;i<6;i++){
        stone = new Block(Blocks::Stone);
        stone->setPos(6700,550-i*50);
        scene->addItem(stone);
        BlockList.push_back(stone);
    }
    stone = new Block(Blocks::Stone);
    stone->setPos(6650,550);
    scene->addItem(stone);
    BlockList.push_back(stone);
    Flag* flag = new Flag(FlagPart::Flag);
    Flag* pole = new Flag(FlagPart::Pole, flag);
    flag->setPos(6890, 540);
    pole->setPos(6950, 98);
    scene->addItem(flag);
    scene->addItem(pole);

}

Map& Map::getMap()
{
    static Map map;
    return map;
}

void Map::update()
{
    if(game->getPlayer()->x() > 2900 && game->getPlayer()->x() < 2910){
        ToxicMushroom* toxic = new ToxicMushroom();
        toxic->setPos(3950, 450);
        toxic->setVx(-1);
        game->getScene()->addItem(toxic);
    }
}

void Map::setUpMap()
{
    getMap().__setUpMap();
}
