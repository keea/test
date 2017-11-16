/*
* 뱀의 컨트롤을 관리한다.
* @file		SnakeCtrl.h
* @date     Tue Nov 14 19:03:31 2017
* @author   keea
*/

#pragma once
#include "Snake.h"
#include "GameView.h"

class SnakeCtrl
{
private:
	Snake * snake;
	void ChgHead(SnakeBody * body);
public:
	SnakeCtrl(Snake * _snake);
	void SettingView(GameView * view);

	void Init(int x, int y, int _ahead);
	void InsertBody(); //뱀의 몸통 추가
	void InsertBody(bool isTrue); //뱀의 몸통 추가
	void RotHead(int key); //뱀의 머리 회전
	void Move(); //뱀의 이동 처리
	bool IsCollision(int start, int _x, int _y); //충돌체크
	bool IsSnakeColl(); //뱀끼리 충돌하는 가?

	int GetHeadX();
	int GetHeadY();
};

