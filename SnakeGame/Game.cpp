/*
* ����
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
	view.Init(); //�並 �ʱ�ȭ�Ѵ�.

	bool isNotEnd = true;
	int tickTimes = 1;
	snakeCtrl->InsertBody();
	snakeCtrl->InsertBody();

	while (isNotEnd)
	{
		DWORD tick = GetTickCount();
		if (tickTimes == 10)  //move 10�� �ϸ� 5�ʰ� ������.
		{
			//������ ����
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
			if (_kbhit()) //Ű���� �Է½�
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

					Sleep(100); //ȭ��ǥ Ű�� ���ÿ� �Է� ����
				}
			}
		}

		//�������� �Ծ��°�
		bool isCollion = itemCtrl->IsCollision(snakeCtrl->GetHeadX(),
			snakeCtrl->GetHeadY());

		snakeCtrl->InsertBody(isCollion);
		scoreCtrl->SetItemScore(isCollion, 100);

		view.Display(); //ȭ���� �����ش�.

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