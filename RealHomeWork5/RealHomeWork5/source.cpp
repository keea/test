/*
* ��������Ʈ ���� 5
* ������ �ﰢ�� �������� ���, �� ���۴ܰ� ������ �Է¹޾� �� ���̴ܸ� ���
* @date     Wed Mar 29 14:06:16 2017
* @author   ���
*/

#include <stdio.h>

void DisplayGugudan(int start, int last);

void main() {
	int start, last; //���۴�, ����
	printf("���۴ܰ� ������ �Է����ּ��� : ");
	scanf("%d %d", &start, &last);
	if (start > last) {
		printf("���۴��� ���ܺ��� ũ�Ƿ� ���۴ܰ� ������ ��ü�մϴ�.\r\n");
		int temp = start;
		start = last;
		last = temp;
	}
	DisplayGugudan(start, last);
}

/*
* ���۴ܰ� ������ �Է¹޾� �ﰢ�� ������ ���������� ���
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