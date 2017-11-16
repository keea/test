/*
* 아이템들
* @file		Items.cpp
* @date     Wed Nov 15 11:31:35 2017
* @author   keea
*/

#include "Items.h"



Items::Items(int _maxNum)
{
	maxNum = _maxNum;
	items = new Item[_maxNum];
}

//갯수 설정
void Items::SetCount(const int c)
{
	count = c;
}

//갯수 가져오기
int Items::GetCount() {
	return count;
}

//최대 갯수 가져오기
int Items::GetMaxNum() {
	return maxNum;
}

//아이템 정보 가져오기
Item Items::GetItem(const int num) {

	return items[num];
}

//모양 가져오기
char Items::GetShape() {
	return shape;
}

//아이템 설정
void Items::SetItem(const int cunt, Item item) {
	items[cunt] = item;
}

Items::~Items()
{
	delete items;
}
