/*
* ������ �����Ѵ�.
* @file		ScoreCtrl.h
* @date     Thu Nov 16 14:24:20 2017
* @author   keea
*/

#pragma once
#include "Score.h"
#include "GameView.h"
class ScoreCtrl
{
private: 
	Score * score;
public:
	ScoreCtrl(Score * _score);
	void Init();
	void SetItemScore(bool isTrue, int add); //������ ȹ��� ���� ȹ��
	void SettingView(GameView * view);
};

