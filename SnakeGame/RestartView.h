/*
* 다시시작 화면 담당
* @file		RestartView.h
* @date     Tue Nov 14 10:55:23 2017
* @author   keea
*/
#pragma once
#include "View.h"

class RestartView : public View
{
private:
	int key;
public:
	RestartView();
	virtual void Display();
	int GetKey();
	void SetKey(int _key);
};

