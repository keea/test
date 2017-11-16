/*
* 점수를 관리한다.
* @file		ScoreCtrl.cpp
* @date     Thu Nov 16 14:26:32 2017
* @author   keea
*/

#include "ScoreCtrl.h"



ScoreCtrl::ScoreCtrl(Score * _score)
{
	score = _score;
}

void ScoreCtrl::Init()
{
	score->SetScore(0);
}

void ScoreCtrl::SetItemScore(bool isTrue, int add) 
{
	if (isTrue) 
	{
		int temp = score->GetScore();
		score->SetScore(temp + add);
	}
}

void ScoreCtrl::SettingView(GameView * view)
{
	view->SettingView(score);
}
