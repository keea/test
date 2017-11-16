/*
* ���� ������ ����
* @file		Data.h
* @date     Mon Nov 13 14:31:20 2017
* @author   keea
*/

#pragma once

//���� ��������
enum STATE
{
	MAIN, //����ȭ��
	GAME, //����ȭ��
	RESTART, //�ٽý���
	END, //��������
};

//�޴�
enum KEY_MENU_STATE
{
	MENU1,
	MENU2,
};

//Ű�� ����
enum INPUT_KEY
{
	ARROW_KEY = -32,
	UP_KEY = 72,
	DOWN_KEY = 80,
	ENTER = 13,
	LEFT_KEY = 75,
	RIGHT_KEY = 77,
	ESC = 27,
};

//���� �̵� ����
enum SNAKE_AHEAD 
{
	RIGHT = 1, //�⺻ ���� 1�� �ش�.
	DOWN, //2
	LEFT, //3
	UP //4
};

