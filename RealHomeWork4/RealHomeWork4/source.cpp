/*
* ��������Ʈ ���� 4
* �Ƕ�̵��� ���̸� �Է� �޾Ƽ� �� ���̸�ŭ ���
* @date     Wed Mar 29 13:48:57 2017
* @author   ���
*/

#include <stdio.h>
 
void DisplayPiramide(int height);


void main() {
	int height;
	printf("�Ƕ�̵��� ���̸� �Է����ּ��� : ");
	scanf("%d", &height);
	DisplayPiramide(height);
}

/*
* ���̸� �Է¹޾� �� ���̸�ŭ �Ƕ�̵� ���
* @param  line(�Ƕ�̵� ����)
* @return
* @date   Wed Mar 29 13:59:21 2017
*/
void DisplayPiramide(int height) {
	for (int i = 1; i <= height; i++) {
		for (int j = height; j > i; j--) {
			printf(" ");
		}
		for (int k = 1; k <= i; k++) {
			printf("*");
		}
		for (int l = 1; l < i; l++) {
			printf("*");
		}
		printf("\r\n");
	}
}