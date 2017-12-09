//
// Created by peto184 on 09-Dec-17.
//

#include "object.h"

bool Object::checkCollisionY(Object& o){
    return mPosition.y >= o.mPosition.y && o.mPosition.y + o.mScale.y >= mPosition.y;
}

bool Object::checkCollisionX(Object& o){
    return mPosition.x + mScale.x >= o.mPosition.x && o.mPosition.x + o.mScale.x >= mPosition.x;
}
