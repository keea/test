#include <stdio.h>

void main() {
	int maxLine = 3;
	int startNum = 1;
	int star = 1;
	int temp = 1;

	while (startNum <= maxLine)
	{
		int dan = 1; //´ÜÀ» ³ªÅ¸³¿.
		while (dan <= 9)
		{
			int blank = startNum;
			while (blank < maxLine)
			{
				printf("       ");
				blank = blank + 1;
			}
			star = 1;
			while (star < startNum * 2)
			{
				int dan2 = temp - (startNum - 1) + star - 1;

				printf("%d*%d=%2d ", dan2, dan, dan*dan2);
				star = star + 1;
			}
			dan = dan + 1;
			printf("\r\n");
		}
		temp = temp + star;
		startNum = startNum + 1;
	}
}