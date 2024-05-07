#include <QKeyEvent>
#include <QDebug>
#include <time.h>
#include "Mario.h"
#include "Entity.h"
#include "Hitbox.h"
#include "Bullet.h"
#include "ToxicMushroom.h"
#include "Flag.h"
#include "Item.h"
#include "Game.h"
#include "Flower.h"




extern Game* game;

Mario::Mario()
{
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPixmap(QPixmap(":/images/image/Mario_small/s_mario_stand_L.png"));
    key = Key::NONE;
    faceTo = Facing::Left;
    state = State::Stop;
    isKeyPressed.assign(30,0);
    walking_annimation_L = {":/images/image/Mario_small/s_mario_run1_L.png",
                            ":/images/image/Mario_small/s_mario_run2_L.png"};
    walking_annimation_R = {":/images/image/Mario_small/s_mario_run1_R.png",
                            ":/images/image/Mario_small/s_mario_run2_R.png"};
    walking_annimation_L_big = {":/images/image/Mario_big/mario_L_run0.png",
                                ":/images/image/Mario_big/mario_L_run1.png",
                                ":/images/image/Mario_big/mario_L_run2.png"};
    walking_annimation_R_big = {":/images/image/Mario_big/mario_R_run0.png",
                                ":/images/image/Mario_big/mario_R_run1.png",
                                ":/images/image/Mario_big/mario_R_run2.png"};
    animation_state = 0;
    animation_counter = 0;
    is_enemy = false;
    is_big = false;
    is_invinsible = false;
    score = 0;
    ammo = 0;
    hp = 3;
    JumpTimer = new QTimer();
    JumpTimer->setSingleShot(true);
    InvincibleTimer = new QTimer();
    InvincibleTimer->setSingleShot(true);
    mhitbox = new Hitbox(this);
}

void Mario::keyPressEvent(QKeyEvent* event){

    if(event->key() == Qt::Key_W){
        isKeyPressed[(int)Key::W] = true;
    }
    if (event->key() == Qt::Key_A){
        isKeyPressed[(int)Key::A] = true;
    }
    if (event->key() == Qt::Key_S){
        isKeyPressed[(int)Key::S] = true;
    }
    if (event->key() == Qt::Key_D){
        isKeyPressed[(int)Key::D] = true;
    }
    //if (event->key() == Qt::Key_Shift){
    //    shootBullet();
    //}
}

void Mario::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        isKeyPressed[(int)Key::W] = false;
    }
    if (event->key() == Qt::Key_A){
        isKeyPressed[(int)Key::A] = false;
    }
    if (event->key() == Qt::Key_S){
        isKeyPressed[(int)Key::S] = false;
    }
    if (event->key() == Qt::Key_D){
        isKeyPressed[(int)Key::D] = false;
    }
}

void Mario::Reset(qreal x, qreal y)
{
    is_big = false;
    ammo = 0;
    hp = 3;
    state = State::Stop;
    setPos(x, y);
    game->resetMap();
}

void Mario::addPoint()
{
    score++;
}

void Mario::beBig()
{
    setPos(x(), y()-30);
    is_big = true;
    hp = std::min(3, hp+1);
}

void Mario::addBullet()
{
    ammo += 3;
}

void Mario::update(){



    // If Mario is Dead, play death animation and ignore other things
    if(state == State::Dying){
        gravity();
        move();
        return;
    }

    // if hp is lower or equal to 0 Mario must have died
    if(hp <= 0){
        setDead();
    }

    //handle collision with blocks and gravity
    collideHandler();

    //apply friction so mario will stop eventually
    friction();

    // update xx and vy accoding to key input
    controlHandler();

    // with vx determine facing and state
    stateUpdate();

    // update image according to facing and state
    updateImage();

    //boundry check
    boundryCheck();

    // move according to Mario's vx and vy
    move();
#if DEBUG_PLAYER
    qDebug() << "vx: " << vx() << "vy: " << vy();
    qDebug() << "x: " << x() << "y: " << y();
#endif
}

void Mario::stateUpdate()
{
    if(state == State::Dying){
        //do nothing
    }
    else if(vy() > 0){
        state = State::Jumping;
    }
    else if(vy() < 0){
        state = State::Falling;
    }
    else if(vx() == 0 && vy() == 0){
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

void Mario::controlHandler()
{
    //move according to keyboard input

    /*
    if(isKeyPressed[(int)Key::W]){
        if(JumpTimer->isActive()){
            setVy(vy() + 0.2);
        }
        else if(!(state == State::Jumping || state == State::Falling)){
            JumpTimer->start(JUMP_HOLDING_MAX_MILISEC);

        }
    }
    */

    if(isKeyPressed[(int)Key::W]){
        if(state == State::Stop || state == State::Running){
            if(is_big){
                setVy(vy() + JUMP_ACCELERATION_PER_TICK * 1.22);
            }
            else{
                setVy(vy() + JUMP_ACCELERATION_PER_TICK);
            }
        }
    }
    if(isKeyPressed[(int)Key::A]){
        if(is_big){
            setVx(fmax(vx() - SEC_TO_TICK(WALKING_ACCELERATION_PER_SEC), -MAX_SPEED * 1.4));
        }
        else{
            setVx(fmax(vx() - SEC_TO_TICK(WALKING_ACCELERATION_PER_SEC), -MAX_SPEED));
        }

    }
    if(isKeyPressed[(int)Key::S]){

    }
    if(isKeyPressed[(int)Key::D]){
        if(is_big){
            setVx(fmin(vx() + SEC_TO_TICK(WALKING_ACCELERATION_PER_SEC), MAX_SPEED * 1.4));
        }
        else{
            setVx(fmin(vx() + SEC_TO_TICK(WALKING_ACCELERATION_PER_SEC), MAX_SPEED));
        }

    }
}

void Mario::collideHandler()
{
    collide_info info = getCollide();
    Object* collider;
    if(info[Direction::Up].is_collide){
#if DEBUG_HITBOX
        qDebug() << "Colliding from Top";
#endif
        collider = info[Direction::Up].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vy() > 0){
                setVy(0);
                setPos(x(), collider->y()+collider->boundingRect().height());
            }
            dynamic_cast<Block*>(collider)->BlockEvent();
        }
    }
    if(info[Direction::Down].is_collide){
#if DEBUG_HITBOX
        qDebug() << "Colliding from Down";
#endif
        collider = info[Direction::Down].collider;
        if(typeid(*collider) == typeid(Block)){
            if(vy() < 0){
                setVy(0);
                state = State::Stop;
                setPos(x(), collider->y() - boundingRect().height());
            }
        }
        if(typeid(*collider) == typeid(ToxicMushroom)){
            collider->remove();
            setVy(2);
        }
        if(typeid(*collider) == typeid(Flower)){
            if(! InvincibleTimer->isActive()){
                if(is_big){
                    is_big = false;
                    InvincibleTimer->start(2000);
                }
                else{
                    InvincibleTimer->start(2000);
                    hp--;
                }
            }
        }
    }
    else{
        gravity();
    }
    if(info[Direction::Left].is_collide){
#if DEBUG_HITBOX
        qDebug() << "Colliding from Left";
#endif
        collider = info[Direction::Left].collider;
        if(typeid(*collider) == typeid(Block)){
            setPos(collider->x()+collider->boundingRect().width(), y());
            if(vx() < 0){
                setVx(0);
            }
        }
        if(typeid(*collider) == typeid(ToxicMushroom) || typeid(*collider) == typeid(Flower)){
            if(! InvincibleTimer->isActive()){
                if(is_big){
                    is_big = false;
                    InvincibleTimer->start(2000);
                }
                else{
                    InvincibleTimer->start(2000);
                    hp--;
                }
            }
        }
    }
    if(info[Direction::Right].is_collide){
#if DEBUG_HITBOX
        qDebug() << "Colliding from Right";
#endif
        collider = info[Direction::Right].collider;
        if(typeid(*collider) == typeid(Block)){
            setPos(collider->x() - boundingRect().width(), y());
            if(vx() > 0){
                setVx(0);
            }
        }
        if(typeid(*collider) == typeid(Flag)){
            setPos(collider->x()-50, y());
            if(vx() > 0){
                setVx(0);
            }
        }
        if(typeid(*collider) == typeid(ToxicMushroom) || typeid(*collider) == typeid(Flower)){
            if(! InvincibleTimer->isActive()){
                if(is_big){
                    is_big = false;
                    InvincibleTimer->start(2000);
                }
                else{
                    InvincibleTimer->start(2000);
                    hp--;
                }
            }
        }
    }
}

void Mario::updateImage(){
    //change image according to state and facing
    if(is_big){
        if(state == State::Stop){
            if(faceTo == Facing::Left){
                setPixmap(QPixmap(":/images/image/Mario_big/mario_L_stand.png"));
            }
            else{
                setPixmap(QPixmap(":/images/image/Mario_big/mario_R_stand.png"));
            }
        }
        else if (state == State::Running){
            if(animation_state == walking_annimation_L_big.size()){
                animation_state = 0;
            }
            if(faceTo == Facing::Left){
                setPixmap(QPixmap(walking_annimation_L_big[animation_state]));
            }
            else if(faceTo == Facing::Right){
                setPixmap(QPixmap(walking_annimation_R_big[animation_state]));
            }
            if(animation_counter == TICK_PER_ANIMATION){
                animation_state++;
                animation_counter = 0;
            }
            animation_counter++;
        }
        else if (state == State::Jumping || state == State::Falling){
            if(faceTo == Facing::Left){
                setPixmap(QPixmap(":/images/image/Mario_big/mario_L_jump1.png"));
            }
            else {
                setPixmap(QPixmap(":/images/image/Mario_big/mario_R_jump1.png"));
            }
        }
        else if(state == State::Dying){
            setPixmap(QPixmap(":/images/image/Mario_big/b_mario_die.png"));
        }
    }
    else{
        if(state == State::Stop){
            if(faceTo == Facing::Left){
                setPixmap(QPixmap(":/images/image/Mario_small/s_mario_stand_L.png"));
            }
            else{
                setPixmap(QPixmap(":/images/image/Mario_small/s_mario_stand_R.png"));
            }
        }
        else if (state == State::Running){
            if(animation_state == walking_annimation_L.size()){
                animation_state = 0;
            }
            if(faceTo == Facing::Left){
                setPixmap(QPixmap(walking_annimation_L[animation_state]));
            }
            else if(faceTo == Facing::Right){
                setPixmap(QPixmap(walking_annimation_R[animation_state]));
            }
            if(animation_counter == TICK_PER_ANIMATION){
                animation_state++;
                animation_counter = 0;
            }
            animation_counter++;
        }
        else if (state == State::Jumping || state == State::Falling){
            if(faceTo == Facing::Left){
                setPixmap(QPixmap(":/images/image/Mario_small/s_mario_jump1_L.png"));
            }
            else {
                setPixmap(QPixmap(":/images/image/Mario_small/s_mario_jump1_R.png"));
            }
        }
        else if(state == State::Dying){
            setPixmap(QPixmap(":/images/image/Mario_small/s_mario_die.png"));
        }
    }
}

void Mario::friction()
{
    if(abs(vx()) < EPSILON){
        setVx(0);
    }
    else if(vx() > 0){
        setVx(vx()-SEC_TO_TICK(FRICTION_ACCELERATION_PER_SEC));
    }
    else if(vx() < 0){
        setVx(vx()+SEC_TO_TICK(FRICTION_ACCELERATION_PER_SEC));
    }
    setVx(0.999*vx());
}

void Mario::boundryCheck()
{
    if(x() < fmin(game->scroll_limit, GAME_WIDTH - WINDOW_WIDTH) && vx() < 0){
        setVx(0);
        setPos(fmin(game->scroll_limit, GAME_WIDTH - WINDOW_WIDTH), y());
    }
    if(x() > GAME_WIDTH - 50 && vx() > 0){
        setVx(0);
        setPos(GAME_WIDTH - 50, y());
    }
    if(y() > GAME_HEIGHT){
        setDead();
    }
}

void Mario::shootBullet(QPointF location)
{
    if(ammo <= 0)
        return;
    Bullet* bullet = new Bullet(faceTo);
    if(faceTo == Facing::Left){
        bullet->setPos(x()-3, y()+15);
    }
    else{
        bullet->setPos(x()+53, y()+15);
    }
    QLineF line;
    line.setPoints(bullet->pos(), location);
    bullet->setVx(BULLET_SPEED * cosf((line.angle() * PI)/180.0));
    bullet->setVy(BULLET_SPEED * sinf((line.angle() * PI)/180.0 ));
    game->getScene()->addItem(bullet);
    ammo--;

}

void Mario::setDead()
{
    hp = 0;
    setVy(4);
    setVx(0);
    setZValue(100);
    state = State::Dying;
    updateImage();
}

State Mario::getState() const
{
    return state;
}

