/*
* ���� ���� ������ �����Ѵ�.(���� ������� ����)
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
	SnakeBody * bodys;//���� ������� ����

	int count = 0; //���� ����
	int ahead = RIGHT; //���� �������. �⺻ ���� �������̴�.
	int maxNum; //���� �ְ� ����
	char * shape = "��";
	char * h_shape = "��"; //�Ӹ����

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

