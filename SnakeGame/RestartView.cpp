/*
* �ٽý��� ȭ�� ���
* @file		RestartView.cpp
* @date     Tue Nov 14 10:57:06 2017
* @author   keea
*/

#include "RestartView.h"
#include "Data.h"



RestartView::RestartView()
{
	key = KEY_MENU_STATE::MENU1;
	View::Init();
}

void RestartView::Display()
{
	DoubleBuffer buffer = GetBuffer();

	buffer.ClearBuffer();

	buffer.DrawString(67, 1, "@author keea");
	buffer.DrawString(55, 0, "https://github.com/keea/");

	buffer.DrawString(31, 6, "���ӿ���");
	buffer.DrawString(31, 10, "�ٽý���");
	buffer.DrawString(32, 12, "������");

	if (KEY_MENU_STATE::MENU1 == key) {
		buffer.DrawString(28, 10, "->");
	}
	else if (KEY_MENU_STATE::MENU2 == key) {
		buffer.DrawString(28, 12, "->");
	}

	buffer.SwapBuffer();
}

int RestartView::GetKey()
{
	return key;
}

void RestartView::SetKey(int _key)
{
	key = _key;
}



