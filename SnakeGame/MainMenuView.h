/*
* 메인메뉴 화면 담당
* @file		MainMenuView.cpp
* @date     Mon Nov 13 17:16:23 2017
* @author   keea
*/
#pragma once
#include "View.h"
class MainMenuView : public View
{
private:
	int key;
public:
	MainMenuView();
	virtual void Display();
	int GetKey();
	void SetKey(int _key);
};