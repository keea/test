/*
* 리얼이펙트 과제 2
* 윤년계산기
* @date     Wed Mar 29 13:41:33 2017
* @author   희아
*/

#include <stdio.h>

//함수정의
void CheckYear(int year);

void main() {
	int year;
	printf("년도를 입력해주세요 : ");
	scanf("%d", &year);
	CheckYear(year);
}

/*
* 연도 값을 받아 윤년인지 체크
* @param  year 비교할 연도
* @return
* @date   Wed Mar 29 13:43:48 2017
*/
void CheckYear(int year) {
	if (year % 4 == 0) {
		printf("윤년입니다.\r\n");
	}
	else {
		printf("윤년이 아닙니다.\r\n");
	}
}

