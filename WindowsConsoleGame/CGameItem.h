/*
* CGameItem.h
*----------------------------------------------------
* Definition of item class and all derived classes.
*
* The student should add derived class definitions here.
*
*/



#ifndef _CGAMEITEM_H
#define _CGAMEITEM_H

#include <iostream>
#include <string>
using namespace std;

class CGameItem {
protected: // can be seen by derived classes 

	int      _value;
	bool _oneTimeUse, _isStackable;
	string   _description;

public:

	CGameItem()
	{
		_value = 0;
	}

	~CGameItem()
	{
	}

	int value() { return _value; }
	string description() { return _description; }

	// pure virtual function, everyone must override
	virtual void use() = 0;

};

class CSpell : public CGameItem{

public:

	CSpell();

	CSpell(CSpell & right);

	void use();

};

class CPotion : public CGameItem {
public:

	CPotion();

	CPotion(CPotion& right);

	void use();
};

class CWeapon : public CGameItem {
public:

	CWeapon();

	CWeapon(CWeapon& right);

	void use();
};

class CTool : public CGameItem {
public:

	CTool();

	CTool(CTool& right);

	void use();
};

#endif