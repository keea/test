/*
* 게임 화면 담당
* @file		GameView.h
* @date     Mon Nov 13 17:54:29 2017
* @author   keea
*/

#pragma once
#include "View.h"
#include "MapView.h"
#include "SnakeView.h"
#include "ItemsView.h"
#include "ScoreView.h"

class GameView : public View
{
private:
	MapView * mapView;
	SnakeView * snakeView;
	ItemsView * itemsView;
	ScoreView * scoreView;
public:
	GameView();

	void SettingView(Map * map);
	void SettingView(Snake * snake);
	void SettingView(Items * items);
	void SettingView(Score * score);

	virtual void Display();
	void ShowHowToPlay(DoubleBuffer buffer);

	~GameView();
};

