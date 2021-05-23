/*
* Entity.h
*----------------------------------------------------
* Definition of Entity class.
*
* Any Entity is any collidable object with an x and y coordinate
*
*/



#ifndef _ENTITY_H
#define _ENTITY_H

#include <iostream>
#include <string>
using namespace std;

class Entity{

protected:
	int _x, _y;
	char _myChar;
public:
	char getChar();
	int getX(), getY();
	bool detectCollision(Entity Other);
	
	Entity(){
		_x = -1;
		_y = -1;
		_myChar = 'E';
	}

	Entity(int x, int y){
		_x = x;
		_y = y;
		_myChar = 'E';
	}

	Entity(int x, int y, char c){
		_x = x;
		_y = y;
		_myChar = c;
	}

};


#endif
