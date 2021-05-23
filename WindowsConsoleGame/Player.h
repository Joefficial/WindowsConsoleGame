/*
* Player.h
*----------------------------------------------------
* Definition of Player.
*
* This class is what defines our player, all his stats including health and position are held here
* because the player is rendered and is a collidable object it is an Entity
*/



#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class Player : public Entity{
protected:
	int _health; //also inventory and maybe velocity someday

public:
	Player(int x, int y, char c, int health) : Entity(x,y,c){
		_health = health;
	}
	
	//These should probably be in player.cpp but that would require me to have more time
	void moveX(int velocity){
		_x += velocity;
	}

	void moveY(int velocity){
		_y += velocity;
	}
};

#endif
