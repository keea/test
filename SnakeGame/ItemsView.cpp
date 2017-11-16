/*
* 아이템 화면 처리
* @file		ItemsView.cpp
* @date     Thu Nov 16 13:32:37 2017
* @author   keea
*/
#include "ItemsView.h"



ItemsView::ItemsView(Items * _items)
{
	items = _items;
}

void ItemsView::Display(DoubleBuffer buffer)
{
	for (int i = 0; i < items->GetCount(); i++) {
		int x = items->GetItem(i).GetX();
		int y = items->GetItem(i).GetY();
		buffer.Draw(x, y, items->GetShape());
	}
}


