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
	int cage; //������ ���� ĭ ��
	printf("���� �������� ���� ĭ ���� �Է����ּ��� : ");
	scanf("%d", &cage);

	int * snail = new int[cage*cage]; //�������� ũ�⸦ �Ҵ�޴´�.

	int checkNum = cage; // ������ ĭ
	int count = 1; //ó������ 1�� �ʱ�ȭ. ù���� �ѹ��� ���� ����

	while (checkNum >= 0)
	{
		MakeSnail(cage,checkNum, cage*cage, snail);
		count += 1;
		if (count == 2) { //2�� ���� ä������ ĭ�� �۾���.
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
	int spinRule[4] = { 1, cageNum, -1, -1*cageNum }; //ȸ����Ģ

	while (startNum < lastCan)
	{
		boxNum = boxNum + spinRule[countSpin];

		snail[boxNum - 1] = InputNum;

		startNum += 1;
		InputNum += 1;
	}

	countSpin += 1;

	if (countSpin > 3) //����ī���͸� 3�̻� �Ǹ� �ʱ�ȭ �Ѵ�.
		countSpin = 0;
}