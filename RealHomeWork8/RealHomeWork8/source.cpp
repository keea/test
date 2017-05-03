#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int getRandom();
int getBaseBall(int num1);
int getBaseBall(int num1, int num2);
int getStrike(int rNum1, int rNum2, int rNum3, int iNum1, int iNum2, int iNum3);
int getBall(int rNum1, int rNum2, int rNum3, int iNum1, int iNum2, int iNum3);
void CheckGameInfo(int strike, int ball, int count);
int getInput();

void main() {
	srand(time(NULL));
	int rand1 = getRandom();
	int rand2 = getBaseBall(rand1);
	int rand3 = getBaseBall(rand1, rand2);

	int count = 1;

	while (1)
	{
		int inputNum1, inputNum2, inputNum3;
		int checkRange = 1;

		printf("1의 자리 숫자 3개를 입력해주세요 : ");
		inputNum1 = getInput();
		inputNum2 = getInput();
		inputNum3 = getInput();


		int checkStrike = getStrike(rand1, rand2, rand3, inputNum1, inputNum2, inputNum3);
		int checkBall = getBall(rand1, rand2, rand3, inputNum1, inputNum2, inputNum3);

		CheckGameInfo(checkStrike, checkBall, count);

		count = count + 1;
	}
}

//입력값을 체크한다.
int getInput() {
	int num = 0;

	do
	{
		num = getch();

	} while ((num<'0') || (num > '9'));

	printf("%i ", num-'0');

	return num - '0';
}


//게임 상태를 보여준다.
void CheckGameInfo(int strike, int ball, int count) {
	printf("\r\n%d 스트라이크\r\n%d 볼\r\n", strike, ball);
	if (strike == 3) {
		printf("%d번째후 맞추셨습니다.\r\n", count);
		exit(0);
	}
}

//볼 갯수 반환
int getBall(int rNum1, int rNum2, int rNum3, int iNum1, int iNum2, int iNum3) {
	int ball = 3;
	if (rNum1 != iNum1 && rNum1 != iNum2 && rNum1 != iNum3) {
		ball = ball - 1;
	}

	if (rNum2 != iNum1 && rNum2 != iNum2 && rNum2 != iNum3) {
		ball = ball - 1;
	}

	if (rNum3 != iNum1 && rNum3 != iNum3 && rNum3 != iNum3) {
		ball = ball - 1;
	}
	return ball;
}


//스트라이크 갯수 반환
int getStrike(int rNum1, int rNum2, int rNum3, int iNum1, int iNum2, int iNum3) {
	int count = 0;

	if (rNum1 == iNum1) {
		count = count + 1;
	}

	if (rNum2 == iNum2) {
		count = count + 1;
	}

	if (rNum3 == iNum3) {
		count = count + 1;
	}

	return count;
}

//랜덤 반환
int getRandom() {
	return rand() % 9 + 1;
}

//중복없는 숫자 반환
int getBaseBall(int num1) {
	int rand = 0;
	do
	{
		rand = getRandom();
	} while (rand == num1);

	return rand;
}

//중복없는 숫자 반환
int getBaseBall(int num1, int num2) {
	int rand = 0;
	do
	{
		rand = getRandom();
	} while ((rand == num1) || (num2 == rand));

	return rand;
}