/*
* ���� ���� �κп� ���� ������ �����Ѵ�.
* @file		SnakeBody.cpp
* @date     Tue Nov 14 16:24:46 2017
* @author   keea
*/

#pragma once
#include "GameObj.h"
class SnakeBody : public GameObj
{
private:
	int x;
	int y;
public:
	SnakeBody getSnakeBody(int _x, int _y);
	virtual int GetX();
	virtual int GetY();
	virtual void SetX(const int _x);
	virtual void SetY(const int _y);
};

