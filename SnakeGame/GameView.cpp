/*
* 게임 화면 담당
* @file		GameView.h
* @date     Mon Nov 13 17:54:29 2017
* @author   keea
*/
#include "GameView.h"

GameView::GameView()
{
	View::Init();
}

void GameView::SettingView(Map * map)
{
	mapView = new MapView(map);
}

void GameView::SettingView(Snake * snake)
{
	snakeView = new SnakeView(snake);
}

void GameView::SettingView(Items * items)
{
	itemsView = new ItemsView(items);
}

void GameView::SettingView(Score * score)
{
	scoreView = new ScoreView(score);
}

void GameView::Display()
{
	DoubleBuffer buffer = GetBuffer();
	buffer.ClearBuffer();

	mapView->Display(buffer);
	itemsView->Display(buffer);
	snakeView->Display(buffer);
	scoreView->Display(buffer);

	ShowHowToPlay(buffer);

	buffer.SwapBuffer();
}


void GameView::ShowHowToPlay(DoubleBuffer buffer)
{
	int width = /*gData->map.GetWidth()*/50 + 3;

	buffer.DrawString(width, 6, "     How To Play!!!!!");
	buffer.DrawString(width, 8, "-> 오른쪽 방향으로 회전");
	buffer.DrawString(width, 9, "<- 왼쪽   방향으로 회전");

	buffer.DrawString(67, 1, "@author keea");
	buffer.DrawString(55, 0, "https://github.com/keea/");
}


GameView::~GameView()
{
	delete mapView;
}
