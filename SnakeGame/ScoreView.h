/*
* 점수를 보여준다.
* @file		ScoreView.h
* @date     Thu Nov 16 14:30:24 2017
* @author   keea
*/

#pragma once

#include "Score.h"
#include "DoubleBuffer.h"

class ScoreView
{
private:
	Score * score;
public:
	ScoreView(Score * _score);
	void Display(DoubleBuffer buffer);
};

