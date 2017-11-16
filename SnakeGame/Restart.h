/*
* 다시시작
* @file		Restart.cpp
* @date     Mon Nov 13 14:36:35 2017
* @author   keea
*/ 
#pragma once
#include "Controller.h"
#include "RestartView.h"

class Restart : public Controller
{
private:
	RestartView view;
public:
	virtual int Update();
};

