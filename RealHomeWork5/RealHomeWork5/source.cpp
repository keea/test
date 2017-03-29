/*
* 리얼이팩트 과제 5
* 구구단 삼각형 형식으로 출력, 단 시작단과 끝단을 입력받아 그 사이단만 출력
* @date     Wed Mar 29 14:06:16 2017
* @author   희아
*/

#include <stdio.h>

void DisplayGugudan(int start, int last);

void main() {
	int start, last; //시작단, 끝단
	printf("시작단과 끝단을 입력해주세요 : ");
	scanf("%d %d", &start, &last);
	if (start > last) {
		printf("시작단이 끝단보다 크므로 시작단과 끝단을 교체합니다.\r\n");
		int temp = start;
		start = last;
		last = temp;
	}
	DisplayGugudan(start, last);
}

/*
* 시작단과 끝단을 입력받아 삼각형 형식의 구구단으로 출력
* @param
* @return
* @date   Wed Mar 29 15:07:55 2017
*/
void DisplayGugudan(int start, int last) {
	int temp = 1;
	int flag = 0;
	for (int i = 1; ; i++) {
		for (int j = 1; j <= last; j++) {
			for (int k = 0; k < i; k++) {
				if (last < (k + temp + start) - 1) {
					flag = 1;
				}
				else {
					if (last == (k + temp + start) - 1) {
						flag = 1;
					}
					printf("%d * %d = %d\t", (k + temp + start) - 1, j, ((k + temp + start) - 1)*j);
				}
			}
			printf("\r\n");
		}
		if (flag == 1) {
			break;
		}
		printf("\r\n");
		temp += i;
	}
}