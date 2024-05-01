#include <QKeyEvent>
#include <QDebug>
#include "Mario.h"
#include "Game.h"


extern Game* game;

Mario::Mario()
    {
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPixmap(QPixmap(":/images/image/Mario_big/mario_L_stand.png"));
    key = Key::NONE;
    faceTo = Facing::Left;
    state = State::Stop;
    key_pressed = false;
    //init timer = 20ms
    key_holding_timer = new QTimer();
    key_holding_timer->setSingleShot(true);
    key_holding = false;
    qDebug() << (int32_t)this;
    //hitbox = new Hitbox(this);

    walking_annimation_L = {":/images/image/Mario_big/mario_L_run0.png",
                            ":/images/image/Mario_big/mario_L_run1.png",
                            ":/images/image/Mario_big/mario_L_run2.png"};
    walking_annimation_R = {":/images/image/Mario_big/mario_R_run0.png",
                            ":/images/image/Mario_big/mario_R_run1.png",
                            ":/images/image/Mario_big/mario_R_run2.png"};
    walking_state = 0;
    animation_counter = 0;
    setCollision(true);
}

void Mario::keyPressEvent(QKeyEvent* event){
    //qDebug() << "key_register" << endl;
    key_pressed = true;
    if(event->key() == Qt::Key_W){
        key = Key::W;
    }
    else if (event->key() == Qt::Key_A){
        key = Key::A;
    }
    else if (event->key() == Qt::Key_S){
        key = Key::S;
    }
    else if (event->key() == Qt::Key_D){
        key = Key::D;
    }
    else {
        key = Key::NONE;
    }
}


void Mario::update(){
    // register key input
    if(key_pressed){
        key_pressed = false;
        // qDebug() << "Key Pressed";
        //key board input register every 20ms
        key_holding_timer->start(20);
        key_holding = true;
    }
    if(key_holding_timer->isActive() == false){
        key_holding = false;
    }
    gravity();
    // update xx and vy accoding to key input
    controlHandler();

    // with vx determine facing and state
    stateUpdate();

    // update image according to facing and state
    update_image();

    // move according to Mario's vx and vy
    move();
    qDebug() << "vx: " << vx() << "vy: " << vy();

    //get hitbox
    QRectF boundingBox = this ->boundingRect();
    //saperate hitbox
    QRectF playertopRect(boundingBox.topLeft(), QPointF(boundingBox.topRight().x(), boundingBox.topRight().y() ));
    QRectF playerbottomRect(QPointF(boundingBox.bottomLeft().x() , boundingBox.bottomLeft().y()), boundingBox.bottomRight());
    QRectF playerleftRect(QPointF(boundingBox.topLeft().x() , boundingBox.topLeft().y()), boundingBox.bottomLeft());
    QRectF playerrightRect(QPointF(boundingBox.topRight().x() , boundingBox.topRight().y()), boundingBox.bottomRight());

}

void Mario::stateUpdate(){
    if(vy() > 0){
        state = State::Jumping;
    }
    else if(vy() < 0){
        state = State::Falling;
    }
    if(vx() == 0){
        state = State::Stop;
    }
    else{
        state = State::Running;
    }
    if(vx() > 0){
        faceTo = Facing::Right;
    }
    else if(vx() < 0){
        faceTo = Facing::Left;
    }
}

void Mario::controlHandler(){
    //move according to keyboard input
    if(key_holding){
        //qDebug() << "key_holding";
        switch (key){
        case Key::W :
            setVy(vy() + 2);
            break;
        case Key::A :
            setVx(vx() - 2);
            break;
        case Key::S :
            setVy(vy() - 2);
            break;
        case Key::D :
            setVx(vx() + 2);
            break;
        default:
            break;
        }
    }
}

void Mario::update_image(){
    //change image according to state and facing
    if(state == State::Stop){
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(":/images/image/Mario_big/mario_L_stand.png"));
        }
        else{
            setPixmap(QPixmap(":/images/image/Mario_big/mario_R_stand.png"));
        }
    }
    else if (state == State::Running){
        if(walking_state == walking_annimation_L.size()){
            walking_state = 0;
        }
        if(faceTo == Facing::Left){
            setPixmap(QPixmap(walking_annimation_L[walking_state]));
        }
        else if(faceTo == Facing::Right){
            setPixmap(QPixmap(walking_annimation_R[walking_state]));
        }
        if(animation_counter == TICK_PER_ANIMATION){
            walking_state++;
            animation_counter = 0;
        }
        animation_counter++;
    }
    else if (state == State::Jumping){

    }
    else if (state == State::Falling){

    }
}

void Mario::gravity()
{
    setVy(vy() - SEC_TO_TICK(GRAVITATIONAL_ACCELERATION_PER_SEC) );
}

void Mario::friction()
{

}
/*
QRectF Mario::hitbox( char x)
{
    get hitbo
    QRectF boundingBox = this ->boundingRect();
    //saperate hitbox
    QRectF playertopRect(boundingBox.topLeft(), QPointF(boundingBox.topRight().x(), boundingBox.topRight().y() ));
    QRectF playerbottomRect(QPointF(boundingBox.bottomLeft().x() , boundingBox.bottomLeft().y()), boundingBox.bottomRight());
    QRectF playerleftRect(QPointF(boundingBox.topLeft().x() , boundingBox.topLeft().y()), boundingBox.bottomLeft());
    QRectF playerrightRect(QPointF(boundingBox.topRight().x() , boundingBox.topRight().y()), boundingBox.bottomRight());


    QGraphicsRectItem *playerTopBox = new QGraphicsRectItem(playertopRect);
    QGraphicsRectItem *playerBottomBox = new QGraphicsRectItem(playerbottomRect);
    QGraphicsRectItem *playerLeftBox = new QGraphicsRectItem(playerleftRect);
    QGraphicsRectItem *playerRightBox = new QGraphicsRectItem(playerrightRect);



    game->scene->addItem(playerTopBox);
    game->scene->addItem(playerBottomBox);
    game->scene->addItem(playerLeftBox);
    game->scene->addItem(playerRightBox);

    if(x=='t')
        return playertopRect;
    if(x=='b')
        return playerbottomRect;
    if(x=='l')
        return playerleftRect;
    if(x=='r')
        return playerrightRect;

    return playertopRect;
}
*/
