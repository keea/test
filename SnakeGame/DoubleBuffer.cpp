#include "DoubleBuffer.h"

#include <windows.h>



static HANDLE g_hBuffer[2];  //���� �ڵ�
static int g_nScreenIndex;   //���� ���� ���۰� ���� ����


void DoubleBuffer::CreateDoubleBuffer()
{
	COORD size = { 80, 25 }; //������ ũ�� ���� ����ä
	SMALL_RECT rect; //â ũ�� ���� ����ü
	rect.Left = 0;
	rect.Right = 80 - 1;
	rect.Top = 0;
	rect.Bottom = 25 - 1;

	//ù��° ���� ����
	g_hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); //���� ����

	SetConsoleScreenBufferSize(g_hBuffer[0], size); //�ܼ� ������ ũ�� ����
	SetConsoleWindowInfo(g_hBuffer[0], TRUE, &rect); //�ܼ� â�� ũ�� ����

													 //�ι�° ���� ����
	g_hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); //���� ����
	SetConsoleScreenBufferSize(g_hBuffer[1], size); //�ܼ� ������ ũ�� ����
	SetConsoleWindowInfo(g_hBuffer[1], TRUE, &rect); //�ܼ� â�� ũ�� ����
}

void DoubleBuffer::Draw(int x, int y, char str)
{
	DWORD dw;   //��ǥ�� �����ϱ� ���� ����ä�� ����.
	COORD CursorPosition = { x, y };    //��ǥ ����
	SetConsoleCursorPosition(g_hBuffer[g_nScreenIndex], CursorPosition);    //��ǥ �̵�
	WriteFile(g_hBuffer[g_nScreenIndex], &str, 1, &dw, NULL);    //���ۿ� ��
}

void DoubleBuffer::DrawString(int x, int y, char *str)
{
	DWORD dw;   //��ǥ�� �����ϱ� ���� ����ä�� ����.
	COORD CursorPosition = { x, y };    //��ǥ ����
	SetConsoleCursorPosition(g_hBuffer[g_nScreenIndex], CursorPosition);    //��ǥ �̵�
	WriteFile(g_hBuffer[g_nScreenIndex], str, strlen(str), &dw, NULL);    //���ۿ� ��
}

void DoubleBuffer::DrawString(int x, int y, std::string s) {
	DWORD dw;   //��ǥ�� �����ϱ� ���� ����ä�� ����.
	COORD CursorPosition = { x, y };    //��ǥ ����
	SetConsoleCursorPosition(g_hBuffer[g_nScreenIndex], CursorPosition);    //��ǥ �̵�
	WriteFile(g_hBuffer[g_nScreenIndex], s.c_str(), s.length(), &dw, NULL);    //���ۿ� ��
}

void DoubleBuffer::SwapBuffer()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hBuffer[g_nScreenIndex]);    //���۸� Ȱ���� �����ν� ȭ�鿡 ������ ������ �ѹ��� ���
	g_nScreenIndex = !g_nScreenIndex;   //���� ���� ����
}

void DoubleBuffer::ClearBuffer()
{
	COORD Coor = { 0, 0 }; //����° ���� �Լ��� ���� ����ü
	DWORD dw; //����° ���� �Լ��� ���� ����ü
	FillConsoleOutputCharacter(g_hBuffer[g_nScreenIndex], ' ', 80 * 30, Coor, &dw);
}

void DoubleBuffer::DeleteBuffer()
{
	CloseHandle(g_hBuffer[0]);    //���� ����
	CloseHandle(g_hBuffer[1]);    //���� ����
}

void DoubleBuffer::SetCursor(int n) // n: 0 - �����, 1 - ���̱�
{
	CONSOLE_CURSOR_INFO ConsoleCursor;

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(g_hBuffer[0], &ConsoleCursor);
	SetConsoleCursorInfo(g_hBuffer[1], &ConsoleCursor);
}
