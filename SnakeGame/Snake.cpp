/*
* 뱀의 관한 정보를 관리한다.(뱀의 몸통들의 모임)
* @file		Snake.h
* @date     Tue Nov 14 18:06:38 2017
* @author   keea
*/
#include "Snake.h"

Snake::Snake(const int _maxNum)
{

	maxNum = _maxNum;
	bodys = new SnakeBody[_maxNum];
}

SnakeBody * Snake::GetBodys()
{
	return bodys;
}

SnakeBody Snake::GetBodys(const int count)
{
	return bodys[count];
}

void Snake::SetBody(const int idx, SnakeBody body)
{
	bodys[idx] = body;
}

void Snake::SetCount(const int _count)
{
	count = _count;
}

int Snake::GetCount()
{
	return count;
}

void Snake::SetAhead(const int _ahead)
{
	ahead = _ahead;
}

int Snake::GetAhead()
{
	return ahead;
}

int Snake::GetMaxNum()
{
	return maxNum;
}

char * Snake::GetHeadShape()
{
	return h_shape;
}

char * Snake::GetShape()
{
	return shape;
}

Snake::~Snake()
{
	delete[] bodys;
}
