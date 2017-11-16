#pragma once
/*
* 게임 오브젝트 추상클래스
* @file		GameObj.h
* @date     Tue Nov 14 16:18:38 2017
* @author   keea
*/

class GameObj
{
public:
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual void SetX(const int _x) = 0;
	virtual void SetY(const int _y) = 0;
};

