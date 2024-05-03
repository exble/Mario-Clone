#include "Bullet.h"

Bullet::Bullet()
{
    setPixmap(QPixmap(":/images/image/bullet.png"));
}

Bullet::Bullet(int _vx)
{
    setPixmap(QPixmap(":/images/image/bullet.png"));
    setVx(_vx);
}

void Bullet::update()
{
    if(IsoutOfBound()){
        this->remove();
    }
}
