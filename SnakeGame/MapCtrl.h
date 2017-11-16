/*
* 맵을 컨트롤 한다.
* @file		MapCtrl.h
* @date     Wed Nov 15 10:01:41 2017
* @author   keea
*/

#pragma once
#include "Map.h"
#include "GameView.h"
class MapCtrl
{
private:
	Map * map;
public:
	MapCtrl(Map * _map);
	void SettingView(GameView * view);
	bool IsCollisonWall(int x, int y);
};

