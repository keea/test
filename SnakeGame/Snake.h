/*
* 뱀의 관한 정보를 관리한다.(뱀의 몸통들의 모임)
* @file		Snake.h
* @date     Tue Nov 14 16:31:18 2017
* @author   keea
*/

#pragma once
#include "Data.h"
#include "SnakeBody.h"

class Snake
{
private:
	SnakeBody * bodys;//뱀의 몸통들을 관리

	int count = 0; //뱀의 갯수
	int ahead = RIGHT; //뱀의 진행방향. 기본 값은 오른쪽이다.
	int maxNum; //뱀의 최고 갯수
	char * shape = "■";
	char * h_shape = "□"; //머리모양

public:
	Snake(const int _maxNum);
	SnakeBody * GetBodys();
	SnakeBody GetBodys(const int count);
	
	void SetBody(const int idx, SnakeBody body);
	void SetCount(const int _count);
	int GetCount();

	void SetAhead(const int _ahead);
	int GetAhead();

	int GetMaxNum();

	char * GetHeadShape();
	char * GetShape();

	~Snake();
};

