/*
* 맵을 보여준다.
* @file		MapView.cpp
* @date     Tue Nov 14 11:27:55 2017
* @author   keea
*/

#include "MapView.h"


MapView::MapView(Map * _map)
{
	map = _map;
}

void MapView::Display(DoubleBuffer buffer)
{
	int width = map->GetWidth();
	int height = map->GetHeight();

	int xCount = 0;
	int yCount = 0;

	char ch = map->GetShpae();

	while (true)
	{
		bool xEnd = xCount > width;  //width보다 작을 때 까지
		bool yEnd = yCount > height; //height보다 작을 때 까지

		if (xEnd && xEnd) //둘다 트루일때 반복문 종료
			break;
		else
		{
			if (!xEnd)
			{
				buffer.Draw(xCount, 0, ch);
				buffer.Draw(xCount, height, ch);
				xCount += 1;
			}

			if (!yEnd)
			{
				buffer.Draw(0, yCount, ch);
				buffer.Draw(width, yCount, ch);
				yCount += 1;
			}
		}
	}
}
