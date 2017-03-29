/*
* 리얼이펙트 과제 4
* 피라미드의 높이를 입력 받아서 그 높이만큼 출력
* @date     Wed Mar 29 13:48:57 2017
* @author   희아
*/

#include <stdio.h>
 
void DisplayPiramide(int height);


void main() {
	int height;
	printf("피라미드의 높이를 입력해주세요 : ");
	scanf("%d", &height);
	DisplayPiramide(height);
}

/*
* 높이를 입력받아 그 높이만큼 피라미드 출력
* @param  line(피라미드 높이)
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