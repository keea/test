/*
* ������ ȭ�� ó��
* @file		ItemsView.h
* @date     Thu Nov 16 13:31:18 2017
* @author   keea
*/
#pragma once
#include "Items.h"
#include "DoubleBuffer.h"

class ItemsView
{
private:
	Items * items;
public:
	ItemsView(Items * _items);
	void Display(DoubleBuffer buffer);
};

