/*
* 리얼이펙트 과제 2
* 2~100까지 수 중 소수 출력
* @date     Wed Mar 29 13:29:46 2017
* @author   희아
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
