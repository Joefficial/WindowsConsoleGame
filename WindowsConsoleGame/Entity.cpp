#include <iostream>
#include "Entity.h"

int Entity::getX(){return _x;}

int Entity::getY(){return _y;}

char Entity::getChar(){return _myChar;}

bool Entity::detectCollision(Entity Other){
	return _x == Other.getX() && _y == Other.getY();
}