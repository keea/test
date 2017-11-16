/*
* 메인메뉴 화면 담당
* @file		MainMenuView.cpp
* @date     Mon Nov 13 17:19:02 2017
* @author   keea
*/

#include "MainMenuView.h"
#include "Data.h"



MainMenuView::MainMenuView()
{
	key = KEY_MENU_STATE::MENU1;
	View::Init();
}


void MainMenuView::Display() 
{
	GetBuffer().ClearBuffer();

	GetBuffer().DrawString(35, 6, "뱀게임");
	GetBuffer().DrawString(34, 10, "게임시작");
	GetBuffer().DrawString(35, 12, "끝내기");
	GetBuffer().DrawString(33, 16, "PRESS ENTER");
	GetBuffer().DrawString(67, 1, "@author keea");
	GetBuffer().DrawString(55, 0, "https://github.com/keea/");

	if (KEY_MENU_STATE::MENU1 == key) {
		GetBuffer().DrawString(31, 10, "->");
	}
	else if (KEY_MENU_STATE::MENU2 == key) {
		GetBuffer().DrawString(31, 12, "->");
	}

	GetBuffer().SwapBuffer();
}

int MainMenuView::GetKey() {
	return key;
}

void MainMenuView::SetKey(int _key)
{
	key = _key;
}