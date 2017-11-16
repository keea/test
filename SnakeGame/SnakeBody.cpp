/*
* 뱀의 몸통 부분에 관한 정보를 관리한다.
* @file		SnakeBody.h
* @date     Tue Nov 14 16:30:54 2017
* @author   keea
*/
#include "SnakeBody.h"

SnakeBody SnakeBody::getSnakeBody(int _x, int _y)
{
	SnakeBody body;
	body.SetX(_x);
	body.SetY(_y);

	return body;
}

int SnakeBody::GetX()
{
	return x;
}

int SnakeBody::GetY()
{
	return y;
}

void SnakeBody::SetX(const int _x)
{
	x = _x;
}

void SnakeBody::SetY(const int _y)
{
	y = _y;
}
