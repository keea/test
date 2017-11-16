#include "DoubleBuffer.h"

#include <windows.h>



static HANDLE g_hBuffer[2];  //버퍼 핸들
static int g_nScreenIndex;   //현재 선택 버퍼가 뭔지 저장


void DoubleBuffer::CreateDoubleBuffer()
{
	COORD size = { 80, 25 }; //버퍼의 크기 관련 구조채
	SMALL_RECT rect; //창 크기 관련 구조체
	rect.Left = 0;
	rect.Right = 80 - 1;
	rect.Top = 0;
	rect.Bottom = 25 - 1;

	//첫번째 버퍼 생성
	g_hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); //버퍼 생성

	SetConsoleScreenBufferSize(g_hBuffer[0], size); //콘솔 버퍼의 크기 설정
	SetConsoleWindowInfo(g_hBuffer[0], TRUE, &rect); //콘솔 창의 크기 설정

													 //두번째 버퍼 생성
	g_hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); //버퍼 생성
	SetConsoleScreenBufferSize(g_hBuffer[1], size); //콘솔 버퍼의 크기 설정
	SetConsoleWindowInfo(g_hBuffer[1], TRUE, &rect); //콘솔 창의 크기 설정
}

void DoubleBuffer::Draw(int x, int y, char str)
{
	DWORD dw;   //좌표를 저장하기 위한 구조채를 선언.
	COORD CursorPosition = { x, y };    //좌표 설정
	SetConsoleCursorPosition(g_hBuffer[g_nScreenIndex], CursorPosition);    //좌표 이동
	WriteFile(g_hBuffer[g_nScreenIndex], &str, 1, &dw, NULL);    //버퍼에 씀
}

void DoubleBuffer::DrawString(int x, int y, char *str)
{
	DWORD dw;   //좌표를 저장하기 위한 구조채를 선언.
	COORD CursorPosition = { x, y };    //좌표 설정
	SetConsoleCursorPosition(g_hBuffer[g_nScreenIndex], CursorPosition);    //좌표 이동
	WriteFile(g_hBuffer[g_nScreenIndex], str, strlen(str), &dw, NULL);    //버퍼에 씀
}

void DoubleBuffer::DrawString(int x, int y, std::string s) {
	DWORD dw;   //좌표를 저장하기 위한 구조채를 선언.
	COORD CursorPosition = { x, y };    //좌표 설정
	SetConsoleCursorPosition(g_hBuffer[g_nScreenIndex], CursorPosition);    //좌표 이동
	WriteFile(g_hBuffer[g_nScreenIndex], s.c_str(), s.length(), &dw, NULL);    //버퍼에 씀
}

void DoubleBuffer::SwapBuffer()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hBuffer[g_nScreenIndex]);    //버퍼를 활성하 함으로써 화면에 버퍼의 내용을 한번에 출력
	g_nScreenIndex = !g_nScreenIndex;   //다음 버퍼 선택
}

void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 }; //세번째 줄의 함수를 위한 구조체
	DWORD dw; //세번째 줄의 함수를 위한 구조체
	FillConsoleOutputCharacter(g_hBuffer[g_nScreenIndex], ' ', 80 * 30, Coor, &dw);
}

void DoubleBuffer::DeleteBuffer()
{
	CloseHandle(g_hBuffer[0]);    //버퍼 해제
	CloseHandle(g_hBuffer[1]);    //버퍼 해제
}

void DoubleBuffer::SetCursor(int n) // n: 0 - 숨기기, 1 - 보이기
{
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(g_hBuffer[0], &ConsoleCursor);
	SetConsoleCursorInfo(g_hBuffer[1], &ConsoleCursor);
}
