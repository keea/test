/*
* 게임
* @file		Game.cpp
* @date     Mon Nov 13 14:34:36 2017
* @author   keea
*/
#include "Game.h"

#include <iostream>
#include <conio.h>
#include "Data.h"
#include "GameView.h"

Game::Game() 
{
	mapCtrl = new MapCtrl(new Map(50, 24));
	snakeCtrl = new SnakeCtrl(new Snake(100));
	itemCtrl = new ItemCtrl(new Items(100));
	scoreCtrl = new ScoreCtrl(new Score);
}

void Game::Init() {
	aniTickCount = GetTickCount();
	snakeCtrl->Init(10,10, SNAKE_AHEAD::RIGHT);
	itemCtrl->Init();
	scoreCtrl->Init();

	mapCtrl->SettingView(&view);
	snakeCtrl->SettingView(&view);
	itemCtrl->SettingView(&view);
	scoreCtrl->SettingView(&view);

	ANI_DURATION = 500;
}

int Game::Update() {
	Init();
	view.Init(); //뷰를 초기화한다.

	bool isNotEnd = true;
	int tickTimes = 1;
	snakeCtrl->InsertBody();
	snakeCtrl->InsertBody();

	while (isNotEnd)
	{
		DWORD tick = GetTickCount();
		if (tickTimes == 10)  //move 10번 하면 5초가 지난다.
		{
			//아이템 생성
			itemCtrl->CrateItem(snakeCtrl, 50, 24);
			tickTimes = 0;
		}
		else if (tick - aniTickCount > ANI_DURATION)
		{
			snakeCtrl->Move();
			aniTickCount = tick;
			tickTimes += 1;
		}
		else 
		{
			if (_kbhit()) //키보드 입력시
			{
				char key = _getch();

				if (key == INPUT_KEY::ARROW_KEY)
				{
					key = _getch();

					switch (key)
					{
					case INPUT_KEY::LEFT_KEY:
						snakeCtrl->RotHead(-1);
						break;

					case INPUT_KEY::RIGHT_KEY:
						snakeCtrl->RotHead(1);
						break;
					}

					Sleep(100); //화살표 키가 동시에 입력 막기
				}
			}
		}

		//아이템을 먹었는가
		bool isCollion = itemCtrl->IsCollision(snakeCtrl->GetHeadX(),
			snakeCtrl->GetHeadY());

		snakeCtrl->InsertBody(isCollion);
		scoreCtrl->SetItemScore(isCollion, 100);

		view.Display(); //화면을 보여준다.

		isNotEnd = !(mapCtrl->IsCollisonWall(snakeCtrl->GetHeadX(), snakeCtrl->GetHeadY())
			|| snakeCtrl->IsSnakeColl());
	}

	view.DeleteDisplay();
	return STATE::RESTART;
}

Game::~Game() 
{
	delete mapCtrl;
	delete snakeCtrl;
	delete itemCtrl;
	delete scoreCtrl;
}