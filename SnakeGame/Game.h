/*
* ∞‘¿”
* @file		Game.h
* @date     Mon Nov 13 14:33:35 2017
* @author   keea
*/

#pragma once
#include "Controller.h"
#include "GameView.h"
#include "MapCtrl.h"
#include "SnakeCtrl.h"
#include "ItemCtrl.h"
#include "ScoreCtrl.h"
#include <Windows.h>

class Game : public Controller
{
private:
	GameView view;
	int ANI_DURATION;
	DWORD aniTickCount;

	MapCtrl * mapCtrl;
	SnakeCtrl * snakeCtrl;
	ItemCtrl * itemCtrl;
	ScoreCtrl * scoreCtrl;

public:
	Game();
	void Init();
	virtual int Update();
	~Game();
};

