/*
* 아이템을 관리한다.
* @file		ItemCtrl.h
* @date     Wed Nov 15 11:32:26 2017
* @author   keea
*/
#pragma once

#include "Items.h"
#include "SnakeCtrl.h"
#include "GameView.h"

class ItemCtrl
{
private:
	Items * items;
public:
	ItemCtrl(Items * _items);
	void Init();
	void SettingView(GameView * view);
	void CrateItem(SnakeCtrl * sCtrl, int width, int height);
	void DelItem(int num);
	bool IsCollision(const int _x, const int _y);
};

