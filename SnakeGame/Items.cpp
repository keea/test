/*
* �����۵�
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

//���� ����
void Items::SetCount(const int c)
{
	count = c;
}

//���� ��������
int Items::GetCount() {
	return count;
}

//�ִ� ���� ��������
int Items::GetMaxNum() {
	return maxNum;
}

//������ ���� ��������
Item Items::GetItem(const int num) {

	return items[num];
}

//��� ��������
char Items::GetShape() {
	return shape;
}

//������ ����
void Items::SetItem(const int cunt, Item item) {
	items[cunt] = item;
}

Items::~Items()
{
	delete items;
}
