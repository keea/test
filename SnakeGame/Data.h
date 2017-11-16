/*
* 게임 데이터 관리
* @file		Data.h
* @date     Mon Nov 13 14:31:20 2017
* @author   keea
*/

#pragma once

//게임 스테이지
enum STATE
{
	MAIN, //메인화면
	GAME, //게임화면
	RESTART, //다시시작
	END, //게임종료
};

//메뉴
enum KEY_MENU_STATE
{
	MENU1,
	MENU2,
};

//키의 동작
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

//뱀의 이동 방향
enum SNAKE_AHEAD 
{
	RIGHT = 1, //기본 값을 1로 준다.
	DOWN, //2
	LEFT, //3
	UP //4
};

