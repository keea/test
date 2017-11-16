/*
* æ∆¿Ã≈€
* @file		Item.h
* @date     Wed Nov 15 11:10:36 2017
* @author   keea
*/

#include "Item.h"



Item::Item()
{
}

Item::Item(const int _x, const int _y)
{
	x = _x;
	y = _y;
}

int Item::GetX() 
{
	return x;
}

int Item::GetY() 
{
	return y;
}

void Item::SetX(const int _x)
{
	x = _x;
}

void Item::SetY(const int _y) {
	y = _y;
}

