/*
* CGameItem.cpp
* ---------------------------------------------
* Implementation for items
*
*/

#include "CGameItem.h"

// CSpell
CSpell::CSpell()
{
	_value = 5;
	_description = "Spell";
}

CSpell::CSpell(CSpell & right)
{
	_value = right._value;
	_description = right._description;
}

void CSpell::use()
{
	cout << "Cast spell" << endl;
}


// CPotion
CPotion::CPotion()
{
	_value = 2;
	_description = "Potion";
}

CPotion::CPotion(CPotion  & right)
{
	_value = right._value;
	_description = right._description;
}

void CPotion::use()
{
	cout << "Use potion" << endl;
}

// CWeapon
CWeapon::CWeapon()
{
	_value = 10;
	_description = "Weapon";
}

CWeapon::CWeapon(CWeapon  & right)
{
	_value = right._value;
	_description = right._description;
}

void CWeapon::use()
{
	cout << "Use Weapon" << endl;
}

// CTool
CTool::CTool()
{
	_value = 3;
	_description = "Tool";
}

CTool::CTool(CTool  & right)
{
	_value = right._value;
	_description = right._description;
}

void CTool::use()
{
	cout << "Use Tool" << endl;
}








