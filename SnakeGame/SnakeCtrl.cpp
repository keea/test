/*
* 뱀의 컨트롤을 관리한다.
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


//뱀의 몸통 추가
void SnakeCtrl::InsertBody()
{
	int tempCnt = snake->GetCount();

	if (snake->GetCount() < snake->GetMaxNum())
	{
		SnakeBody * bodys = snake->GetBodys();

		//이전에 있던 뱀의 값을 가져온다.
		int x = bodys[tempCnt - 1].GetX();
		int y = bodys[tempCnt - 1].GetY();

		//LEFT, RIGHT 홀수
		//DOWN, UP 짝수
		// RIGTH, DOWN 은 마이너스
		//LEFT, UP은 플러스

		//이동 방향에 따라 추가되는 위치가 다르다.
		if (snake->GetAhead() % 2 == 0)
		{
			//y 값 변경
			y = y + (snake->GetAhead() - 3);
		}
		else
		{
			//x 값 변경
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

//뱀의 이동 처리
void SnakeCtrl::Move() {
	SnakeBody * bodys = snake->GetBodys();

	int ChgX;
	int ChgY;

	for (int i = 0; i < snake->GetCount(); i++)
	{
		int beforeX = bodys[i].GetX(); // 이전값
		int beforeY = bodys[i].GetY(); // 이전값
		if (i == 0)
		{
			ChgHead(&bodys[i]); //머리방향을 바꿔주고.
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

//키의 입력값을 받아 뱀회전
// key = 1일 경우 오른쪽 -1일 경우 왼쪽방향으로 회전
void SnakeCtrl::RotHead(int key)
{
	int tempAhead = snake->GetAhead() + key;
	//오른쪽 키만 계속 누를경우
	//RIGHT(기본)->DOWN->LEFT->UP
	if (tempAhead == 0)
		tempAhead = 4;
	else if (tempAhead == 5)
		tempAhead = 1;

	snake->SetAhead(tempAhead);
}

//방향에따라 머리 방향을 바꾸어준다.
void SnakeCtrl::ChgHead(SnakeBody * body)
{
	int x = 0;
	int y = 0;

	int ahead = snake->GetAhead();
	if (ahead % 2 == 0) //y의 값 변경 DOWN(2), UP(4)
						//UP(4)일 경우 값을 빼면 1이다.
						//y를 +하면 밑으로 내려가니 -1를 곱해준다.
		y = (ahead - 3)*-1;
	else //x의 값 변경
		 //RIGHT(1)일 경우 값을 빼면 -1이다.
		 //하지만 X는 2바이트 차지하기 때문에 2를 곱해준다.
		 //-1일 경우 왼쪽으로 이동하니 -1를 곱해준다.
		x = (((ahead - 2) * 2))*-1;

	body->SetX(body->GetX() + x);
	body->SetY(body->GetY() + y);
}

//충돌체크
bool SnakeCtrl::IsCollision(int start, int _x, int _y) {
	for (int i = start; i < snake->GetCount(); i++) {

		SnakeBody * bodys = snake->GetBodys();

		//이전에 있던 뱀의 값을 가져온다.
		int x = bodys[i].GetX();
		int y = bodys[i].GetY();

		if (x == _x && y == _y) {
			return true;
		}
	}
	return false;
}

//뱀끼리 충돌하는가
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
