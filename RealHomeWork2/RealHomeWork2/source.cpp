/*
* ��������Ʈ ���� 2
* 2~100���� �� �� �Ҽ� ���
* @date     Wed Mar 29 13:29:46 2017
* @author   ���
*/

#include<stdio.h>

void main() {
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= i; j++) {
			if (i == j) {
				printf("%i\t", i);
			}
			else if (i%j == 0) {
				break;
			}
		}
	}
}
