/*
* GroundItem.h
*----------------------------------------------------
* Definition of GroundItem.
*
* A GroundItem is a collidable object that when hit becomes a CGameItem in the players inventory
*
*/



#ifndef _GROUNDITEM_H
#define _GROUNDITEM_H

#include <iostream>
#include <string>
#include "Entity.h"

using namespace std;

class GroundItem : public Entity{

protected:
	int _itemNumber;
public:
	//Enum itemtypes potion, weapon, spell, etc

	//I should take in a public item enum like POTION or SPELL insteal of a character here
	GroundItem(int x, int y, char item): Entity(x, y){
		_myChar = item;
		//_myChar = getItemChar();
	}

	int getItemNo(){
		return _itemNumber;
	}

	/*
	char getItemChar(){
		char itemChar = 'E';
		switch(_itemNumber){

		case SPELL:
			itemChar = 'S';
			break;
		case POTION:
			itemChar = 'P';
			break;
		}
		return itemChar;
	}
	*/

};


#endif
