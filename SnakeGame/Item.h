/*
* æ∆¿Ã≈€
* @file		Item.h
* @date     Wed Nov 15 11:09:07 2017
* @author   keea
*/

#pragma once
#include "GameObj.h"
class Item : public GameObj
{
private:
	int x;
	int y;
public:
	Item();
	Item(const int _x, const int _y);
	virtual int GetX();
	virtual int GetY();
	virtual void SetX(const int _x);
	virtual void SetY(const int _y);
};

