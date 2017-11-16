/*
* 뷰를 담당한다.
* @file		View.h
* @date     Mon Nov 13 17:10:50 2017
* @author   keea
*/

#pragma once
#include "DoubleBuffer.h"

class View
{
private:
	DoubleBuffer dBuffer;
public:
	void Init();
	virtual void Display() = 0;
	void DeleteDisplay();
	DoubleBuffer GetBuffer();
};

