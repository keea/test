/*
* ����� ����.
* @file		main.cpp
* @date     Mon Nov 13 14:15:19 2017
* @author   keea
*/

#include "Controller.h"
#include "Data.h"
#include "MainMenu.h"
#include "Game.h"
#include "Restart.h"

void main() 
{
	int state = STATE::MAIN;
	int nextState = state; //���� �������� �̵�

	Controller * ctrl[3];
	ctrl[STATE::MAIN] = new MainMenu;
	ctrl[STATE::GAME] = new Game;
	ctrl[STATE::RESTART] = new Restart;

	while (true)
	{
		if (state >= STATE::END)
			break;

		nextState = ctrl[state]->Update();
		state = nextState;
	}
}
