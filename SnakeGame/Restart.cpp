/*
* 다시시작
* @file		Restart.h
* @date     Mon Nov 13 14:37:32 2017
* @author   keea
*/
#include "Restart.h"
#include <iostream>
#include <conio.h>
#include "Data.h"

int Restart::Update() {
	view.Init();

	int state;
	while (true)
	{
		if (_kbhit())
		{
			char input = _getch();
			int key = view.GetKey();
			if (input == INPUT_KEY::ENTER)
			{
				if (key == KEY_MENU_STATE::MENU1) {
					view.DeleteDisplay();
					return STATE::MAIN;
				}
				else if (key == KEY_MENU_STATE::MENU2) {
					view.DeleteDisplay();
					return STATE::END;
				}
			}

			if (input == INPUT_KEY::ARROW_KEY) {
				input = _getch();

				switch (input)
				{
				case INPUT_KEY::UP_KEY:
					if (key == KEY_MENU_STATE::MENU2)
						key = KEY_MENU_STATE::MENU1;
					break;
				case INPUT_KEY::DOWN_KEY:
					if (key == KEY_MENU_STATE::MENU1)
						key = KEY_MENU_STATE::MENU2;
					break;
				}
			}
			view.SetKey(key);
		}
		view.Display();
	}
}
