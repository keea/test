/*
* 메인메뉴
* @file		MainMenu.h
* @date     Mon Nov 13 14:26:49 2017
* @author   keea
*/

#pragma once

#include "Controller.h"
#include "MainMenuView.h"

class MainMenu: public Controller
{
private:
	MainMenuView view;
public:
	virtual int Update();
};

