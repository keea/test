/*
* 맵을 보여준다.
* @file		MapView.cpp
* @date     Tue Nov 14 11:25:36 2017
* @author   keea
*/

#pragma once
#include "Map.h"
#include "DoubleBuffer.h"

class MapView
{
private:
	Map * map;
public:
	MapView(Map * _map);
	void Display(DoubleBuffer buffer);
};

