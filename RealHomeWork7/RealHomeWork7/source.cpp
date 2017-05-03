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

//메뉴를 보여준다.
void DisplayMenu() {
	printf({
		"/////////////////////자판기/////////////////////\r\n"
		"1. 사이다\t800원\r\n"
		"2. 포카리\t1000원\r\n"
		"3. 오렌지쥬스\t1200원\r\n"
		"////////////////////////////////////////////////\r\n"

		"9-돈넣기\r\n"
		"0-종료\r\n"
	});
	
}

//잔여금액을 보여준다.
void DisplaySaveMoney() {
	printf("잔여금액 : %d원\r\n", haveMoney(0));
}

//자판기의 동작
void Contorl() {
	int chose; //메뉴 입력값을 저장한다.
	scanf("%d", &chose);
	int price = 0; //가격
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
		printf("%d원을 환전하셨습니다.\r\n", haveMoney(0));
		haveMoney(-1 * haveMoney(0));
		DisplaySaveMoney();
		exit(0);
		break;
	default:
		printf("잘못된 입력값입니다.\r\n");
		break;
	}
}

//음료수를 구입할 때 동작
void BuyDrink(int price) {
	if (haveMoney(0) < price) {
		printf("금액이 부족합니다.\r\n");
	}
	else {
		printf("음료수를 구입했습니다.\r\n");
		int change =(-1 * price);
		haveMoney(change);
		DisplaySaveMoney();
	}
}


//자판기에 주입하는 돈의 상태를 관리한다.
//num - 돈의 변화량
int haveMoney(int num) {
	static int money = 0;
	money = money + num;
	return money;
}

//돈을 넣는다.
void InputMoney() {
	int money;
	printf("계산하실 금액을 넣어주세요.");
	scanf("%d", &money);
	haveMoney(money);
}