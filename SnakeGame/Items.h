/*
* 아이템들
* @file		Items.h
* @date     Wed Nov 15 11:20:06 2017
* @author   keea
*/
#pragma once
#include "Item.h"
class Items
{
private:
	Item * items;
	int count = 0;
	int maxNum;
	char  shape = '@';

public:
	Items(int _maxNum);

	Item GetItem(const int num);
	void SetItem(const int _count, Item item);
	void SetCount(const int c);
	int GetCount();
	int GetMaxNum();
	char GetShape();
	~Items();
};

