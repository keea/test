/*
* ���� ��Ʈ���� �����Ѵ�.
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
	void InsertBody(); //���� ���� �߰�
	void InsertBody(bool isTrue); //���� ���� �߰�
	void RotHead(int key); //���� �Ӹ� ȸ��
	void Move(); //���� �̵� ó��
	bool IsCollision(int start, int _x, int _y); //�浹üũ
	bool IsSnakeColl(); //�쳢�� �浹�ϴ� ��?

	int GetHeadX();
	int GetHeadY();
};

