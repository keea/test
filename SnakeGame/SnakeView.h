/*
* ���� ȭ�� ó��
* @file		SnakeView.h
* @date     Tue Nov 14 18:12:58 2017
* @author   keea
*/

#pragma once
#include "Snake.h"
#include "DoubleBuffer.h"

class SnakeView
{
private:
	Snake * snake;
public:
	SnakeView(Snake * _snake);
	void Display(DoubleBuffer buffer);
};

