/*
* ���� ��Ʈ���� �����Ѵ�.
* @file		SnakeCtrl.cpp
* @date     Tue Nov 14 19:05:26 2017
* @author   keea
*/

#include "SnakeCtrl.h"


SnakeCtrl::SnakeCtrl(Snake * _snake)
{
	snake = _snake;
}

void SnakeCtrl::SettingView(GameView * view)
{
	view->SettingView(snake);
}

void SnakeCtrl::Init(int x, int y, int _ahead)
{
	snake->SetCount(0);
	SnakeBody _body;
	snake->SetBody(0, _body.getSnakeBody(x, y));
	snake->SetAhead(_ahead);
	snake->SetCount(1);
}


//���� ���� �߰�
void SnakeCtrl::InsertBody()
{
	int tempCnt = snake->GetCount();

	if (snake->GetCount() < snake->GetMaxNum())
	{
		SnakeBody * bodys = snake->GetBodys();

		//������ �ִ� ���� ���� �����´�.
		int x = bodys[tempCnt - 1].GetX();
		int y = bodys[tempCnt - 1].GetY();

		//LEFT, RIGHT Ȧ��
		//DOWN, UP ¦��
		// RIGTH, DOWN �� ���̳ʽ�
		//LEFT, UP�� �÷���

		//�̵� ���⿡ ���� �߰��Ǵ� ��ġ�� �ٸ���.
		if (snake->GetAhead() % 2 == 0)
		{
			//y �� ����
			y = y + (snake->GetAhead() - 3);
		}
		else
		{
			//x �� ����
			x = x + ((snake->GetAhead() - 2) * 2);
		}

		SnakeBody body;
		snake->SetBody(tempCnt, body.getSnakeBody(x, y));
		snake->SetCount(tempCnt + 1);
	}
}

void SnakeCtrl::InsertBody(bool isTrue) {
	if (isTrue) {
		InsertBody();
	}
}

//���� �̵� ó��
void SnakeCtrl::Move() {
	SnakeBody * bodys = snake->GetBodys();

	int ChgX;
	int ChgY;

	for (int i = 0; i < snake->GetCount(); i++)
	{
		int beforeX = bodys[i].GetX(); // ������
		int beforeY = bodys[i].GetY(); // ������
		if (i == 0)
		{
			ChgHead(&bodys[i]); //�Ӹ������� �ٲ��ְ�.
		}
		else
		{
			bodys[i].SetX(ChgX);
			bodys[i].SetY(ChgY);
		}

		ChgX = beforeX;
		ChgY = beforeY;
	}
}

//Ű�� �Է°��� �޾� ��ȸ��
// key = 1�� ��� ������ -1�� ��� ���ʹ������� ȸ��
void SnakeCtrl::RotHead(int key)
{
	int tempAhead = snake->GetAhead() + key;
	//������ Ű�� ��� �������
	//RIGHT(�⺻)->DOWN->LEFT->UP
	if (tempAhead == 0)
		tempAhead = 4;
	else if (tempAhead == 5)
		tempAhead = 1;

	snake->SetAhead(tempAhead);
}

//���⿡���� �Ӹ� ������ �ٲپ��ش�.
void SnakeCtrl::ChgHead(SnakeBody * body)
{
	int x = 0;
	int y = 0;

	int ahead = snake->GetAhead();
	if (ahead % 2 == 0) //y�� �� ���� DOWN(2), UP(4)
						//UP(4)�� ��� ���� ���� 1�̴�.
						//y�� +�ϸ� ������ �������� -1�� �����ش�.
		y = (ahead - 3)*-1;
	else //x�� �� ����
		 //RIGHT(1)�� ��� ���� ���� -1�̴�.
		 //������ X�� 2����Ʈ �����ϱ� ������ 2�� �����ش�.
		 //-1�� ��� �������� �̵��ϴ� -1�� �����ش�.
		x = (((ahead - 2) * 2))*-1;

	body->SetX(body->GetX() + x);
	body->SetY(body->GetY() + y);
}

//�浹üũ
bool SnakeCtrl::IsCollision(int start, int _x, int _y) {
	for (int i = start; i < snake->GetCount(); i++) {

		SnakeBody * bodys = snake->GetBodys();

		//������ �ִ� ���� ���� �����´�.
		int x = bodys[i].GetX();
		int y = bodys[i].GetY();

		if (x == _x && y == _y) {
			return true;
		}
	}
	return false;
}

//�쳢�� �浹�ϴ°�
bool SnakeCtrl::IsSnakeColl() {
	SnakeBody * bodys = snake->GetBodys();
	int x = bodys[0].GetX();
	int y = bodys[0].GetY();

	bool isColl = IsCollision(1, x, y);

	return isColl;
}

int SnakeCtrl::GetHeadX()
{
	return snake->GetBodys(0).GetX();
}

int SnakeCtrl::GetHeadY()
{
	return snake->GetBodys(0).GetY();
}
