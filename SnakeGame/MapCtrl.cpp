/*
* 맵을 컨트롤 한다.
* @file		MapCtrl.h
* @date     Wed Nov 15 10:04:50 2017
* @author   keea
*/

#include "MapCtrl.h"



MapCtrl::MapCtrl(Map * _map)
{
	map = _map;
}


void MapCtrl::SettingView(GameView * view)
{
	view->SettingView(map);
}

bool MapCtrl::IsCollisonWall(int x, int y)
{
	int width = map->GetWidth();
	int height = map->GetHeight();

	if (x < 1 || x > width - 1)
		return true;
	if (y < 1 || y > height - 1)
		return true;

	return false;
}

