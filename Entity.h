#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"
#include <math.h>

class collide_info{
private:
    struct sub_cell
    {
        bool is_collide = false;
        Object* collider = nullptr;
    };
    sub_cell mdata[4];
public:
    sub_cell& operator[](Direction dir){
        return mdata[(int)dir - 1];
    }
};



class Entity : public Object{
public:
    Entity();
    // Right for positive vx, Up for positive vy
    void move();

    float vx() const;
    float vy() const;
    collide_info getCollide();
    void setVx(float newVx);
    void setVy(float newVy);
    void setSpeed(float Vx, float Vy);

private:
    float _vx, _vy;
};

#endif // ENTITY_H
