/*
* 뷰를 담당한다.
* @file		View.h
* @date     Mon Nov 13 17:13:23 2017
* @author   keea
*/

#include "View.h"

void View::Init() 
{
	dBuffer.CreateDoubleBuffer();
	dBuffer.SetCursor(0);
}

void View::DeleteDisplay()
{
	dBuffer.DeleteBuffer();
}

DoubleBuffer View::GetBuffer() {
	return dBuffer;
}

