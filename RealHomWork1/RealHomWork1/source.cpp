/*
* ��������Ʈ ���� 1
* ������ �Է¹޾� A B C D - F�� ������ ���� ���� ���
* -1 �ޱ� ������ �ݺ�
* @date     Wed Mar 29 10:54:19 2017
* @author   ���
*/
#include <stdio.h>

//�Լ� ����
void displayGrade(int score);

void main() {
	int score;

	while (true)
	{
		printf("������ �Է��ϼ���(-1 ���α׷� ����) : ");
		scanf("%d", &score);

		if (score == -1) { //-1�� ������ �����ض�.
			break;
		}
		else {
			displayGrade(score);
		}
	}
}

/*
* A B C D - F�� ������ ���� ���� ���
* @param  score(����)
* @return
* @date   Wed Mar 29 10:57:26 2017
*/
void displayGrade(int score) {
	if (score >= 90) {
		printf("A");
	}
	else if (score >= 80) {
		printf("B");
	}
	else if (score >= 70) {
		printf("C");
	}
	else if (score >= 60) {
		printf("D");
	}
	else {
		printf("F");
	}
	printf("\r\n");
}