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

		do
		{
			printf("1�� �ڸ� ���� 3���� �Է����ּ��� ex)1 2 3 : ");
			scanf("%d %d %d", &inputNum1, &inputNum2, &inputNum3);

			checkRange = (inputNum1 >= 9) && (inputNum2 >= 9) && (inputNum3 >= 9);
		} while (checkRange);


		/*int inputnum1 = getch() - '0';
		printf("%d", inputnum1);
		int inputnum2 = getch() - '0';
		printf("%d", inputnum2);
		int inputnum3 = getch() - '0';
		printf("%d\r\n", inputnum3);*/

		int checkStrike = getStrike(rand1, rand2, rand3, inputNum1, inputNum2, inputNum3);
		int checkBall = getBall(rand1, rand2, rand3, inputNum1, inputNum2, inputNum3);

		CheckGameInfo(checkStrike, checkBall, count);

		count = count + 1;
	}
}


//���� ���¸� �����ش�.
void CheckGameInfo(int strike, int ball, int count) {
	printf("%d ��Ʈ����ũ\r\n%d ��\r\n", strike, ball);
	if (strike == 3) {
		printf("%d��°�� ���߼̽��ϴ�.\r\n", count);
		exit(0);
	}
}

//�� ���� ��ȯ
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


//��Ʈ����ũ ���� ��ȯ
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

//���� ��ȯ
int getRandom() {
	return rand() % 9 + 1;
}

//�ߺ����� ���� ��ȯ
int getBaseBall(int num1) {
	int rand = 0;
	do
	{
		rand = getRandom();
	} while (rand == num1);

	return rand;
}

//�ߺ����� ���� ��ȯ
int getBaseBall(int num1, int num2) {
	int rand = 0;
	do
	{
		rand = getRandom();
	} while ((rand == num1) || (num2 == rand));

	return rand;
}