//
// Created by peto184 on 09-Dec-17.
//

#include "object.h"

bool Object::checkCollisionY(Object& o1, Object& o2){
    return o1.mPosition.y >= o2.mPosition.y && o2.mPosition.y + o2.mScale.y >= o1.mPosition.y;
}

bool Object::checkCollisionX(Object& o1, Object& o2){
    return o1.mPosition.x + o1.mScale.x >= o2.mPosition.x && o2.mPosition.x + o2.mScale.x >= o1.mPosition.x;
}
