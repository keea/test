/*
* 리얼이펙트 과제 1
* 성적을 입력받아 A B C D - F를 점수에 따라 성적 출력
* -1 받기 전까지 반복
* @date     Wed Mar 29 10:54:19 2017
* @author   희아
*/
#include <stdio.h>

//함수 정의
void displayGrade(int score);

void main() {
	int score;

	while (true)
	{
		printf("성적을 입력하세요(-1 프로그램 종료) : ");
		scanf("%d", &score);

		if (score == -1) { //-1를 받으면 종료해라.
			break;
		}
		else {
			displayGrade(score);
		}
	}
}

/*
* A B C D - F를 점수에 따라 성적 출력
* @param  score(점수)
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