#include <stdio.h>
#include <stdlib.h>

void DisplayMenu();
void Contorl();
int haveMoney(int num);
void DisplaySaveMoney();
void InputMoney();
void BuyDrink(int price);

void main() {
	while (1)
	{
		DisplayMenu();
		DisplaySaveMoney();
		Contorl();
	}
	
}

//�޴��� �����ش�.
void DisplayMenu() {
	printf({
		"/////////////////////���Ǳ�/////////////////////\r\n"
		"1. ���̴�\t800��\r\n"
		"2. ��ī��\t1000��\r\n"
		"3. �������꽺\t1200��\r\n"
		"////////////////////////////////////////////////\r\n"

		"9-���ֱ�\r\n"
		"0-����\r\n"
	});
	
}

//�ܿ��ݾ��� �����ش�.
void DisplaySaveMoney() {
	printf("�ܿ��ݾ� : %d��\r\n", haveMoney(0));
}

//���Ǳ��� ����
void Contorl() {
	int chose; //�޴� �Է°��� �����Ѵ�.
	scanf("%d", &chose);
	int price = 0; //����
	switch (chose)
	{
	case 1:
		BuyDrink(800);
		break;
	case 2:
		BuyDrink(1000);
		break;
	case 3:
		BuyDrink(1200);
		break;
	case 9:
		InputMoney();
		break;
	case 0:
		printf("%d���� ȯ���ϼ̽��ϴ�.\r\n", haveMoney(0));
		haveMoney(-1 * haveMoney(0));
		DisplaySaveMoney();
		exit(0);
		break;
	default:
		printf("�߸��� �Է°��Դϴ�.\r\n");
		break;
	}
}

//������� ������ �� ����
void BuyDrink(int price) {
	if (haveMoney(0) < price) {
		printf("�ݾ��� �����մϴ�.\r\n");
	}
	else {
		printf("������� �����߽��ϴ�.\r\n");
		int change =(-1 * price);
		haveMoney(change);
		DisplaySaveMoney();
	}
}


//���Ǳ⿡ �����ϴ� ���� ���¸� �����Ѵ�.
//num - ���� ��ȭ��
int haveMoney(int num) {
	static int money = 0;
	money = money + num;
	return money;
}

//���� �ִ´�.
void InputMoney() {
	int money;
	printf("����Ͻ� �ݾ��� �־��ּ���.");
	scanf("%d", &money);
	haveMoney(money);
}