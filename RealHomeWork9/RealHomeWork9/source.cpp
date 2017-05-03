#include <stdio.h>
#include <iostream>

/*
1  2  3  4  5
16 17 18 19  6
15 24 25 20  7
14 23 22 21  8
13 12 11 10  9
*/

void MakeSnail(int cageNum, int lastCan, int maxNum, int snail[]);

void main() {
	int cage; //달팽이 가로 칸 수
	printf("만들 달팽이의 가로 칸 수를 입력해주세요 : ");
	scanf("%d", &cage);

	int * snail = new int[cage*cage]; //동적으로 크기를 할당받는다.

	int checkNum = cage; // 달팽이 칸
	int count = 1; //처음에만 1로 초기화. 첫줄은 한번만 돌기 때문

	while (checkNum >= 0)
	{
		MakeSnail(cage,checkNum, cage*cage, snail);
		count += 1;
		if (count == 2) { //2번 돌면 채워놓은 칸이 작아짐.
			count = 0;
			checkNum -= 1;
		}
	}

	for (int i = 1; i <= cage*cage; i++) {
		printf("%3d ", snail[i-1]);
		if (i % cage == 0)
			printf("\r\n");
	}
	printf("\r\n");

	delete [] snail;
}

void MakeSnail(int cageNum,int lastCan, int maxNum, int snail[]) {
	static int InputNum = 1;
	static int countSpin = 0;
	static int boxNum = 0;

	int startNum = 0;
	int spinRule[4] = { 1, cageNum, -1, -1*cageNum }; //회전규칙

	while (startNum < lastCan)
	{
		boxNum = boxNum + spinRule[countSpin];

		snail[boxNum - 1] = InputNum;

		startNum += 1;
		InputNum += 1;
	}

	countSpin += 1;

	if (countSpin > 3) //스핀카운터를 3이상 되면 초기화 한다.
		countSpin = 0;
}