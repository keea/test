/*
* ��������Ʈ ���� 2
* �������
* @date     Wed Mar 29 13:41:33 2017
* @author   ���
*/

#include <stdio.h>

//�Լ�����
void CheckYear(int year);

void main() {
	int year;
	printf("�⵵�� �Է����ּ��� : ");
	scanf("%d", &year);
	CheckYear(year);
}

/*
* ���� ���� �޾� �������� üũ
* @param  year ���� ����
* @return
* @date   Wed Mar 29 13:43:48 2017
*/
void CheckYear(int year) {
	if (year % 4 == 0) {
		printf("�����Դϴ�.\r\n");
	}
	else {
		printf("������ �ƴմϴ�.\r\n");
	}
}

