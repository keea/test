#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

typedef struct Person {
	int index;		 //1부터 시작
	char * id;		 //고객 아이디
	int money;		 //잔액
	double password; //비밀번호
};

typedef struct Bank {
	Person person[100];
};

int PersonNum(Bank *bank);
void DisplayMenu();
void Contorl(Bank *bank);
int IsCtrlBlock(Bank *bank);
int CheckId(Bank *bank, char * ID);
char * InputID();
int CtrlAcc(Bank *bank, int type);
void Destory(Bank *bank);
double CreatePwd();
void CreateID(Bank *bank, char* id, double pwd);
void ClearLineFromReadBuffer();
void Deposit(Bank *bank, int arrNum, int money);
int CheckPwd(Bank *bank, int arrNum, double inputPwd);
int Auth(Bank *bank, int ArrNum);
int InputMoney(char * ctrl);
void CtrlDeposit(Bank *bank, int ArrNum);
void DisplayBalance(Bank * bank, int ArrNum);
int GetBalance(Bank * bank, int ArrNum);
void CtrlWithdraw(Bank * bank, int ArrNum);
void Withdraw(Bank *bank, int arrNum, int money);

void main() {
	//처음 시작시 초기화
	Bank bank = {};
	 
	while (1)
	{
		DisplayMenu();
		Contorl(&bank);
	}
}

//메뉴 보여주기
void DisplayMenu() {
	printf({
		"//////////////////////은행//////////////////////\r\n"
		"1. 입금\r\n"
		"2. 출금\r\n"
		"3. 송금\r\n"
		"4. 잔액조회\r\n"

		"5. 계좌등록\r\n"
		"6. 계좌삭제\r\n"
		"////////////////////////////////////////////////\r\n"

		"0-종료\r\n\r\n"
	});
}

// 동작
void Contorl(Bank *bank) {
	int chose; //메뉴 입력값을 저장한다.
	printf("메뉴를 선택해주세요 : ");
	chose = getch();
	printf("%d\r\n", chose - '0');
	switch (chose - '0')
	{
	case 1:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1)-1;
			CtrlDeposit(bank, ArrNum);
		}
		break;
	case 2:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1) - 1;
			CtrlWithdraw(bank, ArrNum);
		}
		break;
	case 3:
		if (IsCtrlBlock(bank)) {
		}
		break;
	case 4:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1) - 1;
			DisplayBalance(bank, ArrNum);
		}
		break;
	case 5:
		CtrlAcc(bank,0);
		break;
	case 6:
		if (IsCtrlBlock(bank)) {
		}
		break;
	case 0:
		Destory(bank);
		exit(0);
		break;
	default:
		printf("잘못된 입력값입니다.\r\n");
		break;
	}
}

//다음 동작을 막을 것인가?
// 0 - 막다, 1 - 막지 않는다.
int IsCtrlBlock(Bank *bank) {
	if (PersonNum(bank)) {
		return 1;
	}
	else {
		printf("계정을 생성하지 않아 이용이 불가능합니다.\r\n");
		return 0;
	}
}


//등록된 사람 수
int PersonNum(Bank *bank) {
	int perNum = 0; // 사람수
	for (int i = 0; i < 100; i++) {
		if ((*bank).person[i].index == 0)
			return perNum;
		perNum += 1;
	}
	return perNum;
}

//출금

//송금

//계정 관련 컨트롤
// 0 : 아이디 생성, 1 : 아이디 찾기
// return Person.index 값
int CtrlAcc(Bank *bank, int type) {
	while (1)
	{
		printf("아이디를 입력해주세요(최대 100자 ,취소 0) : ");
		char * creatID = InputID();

		if (strlen(creatID) == 0 && atoi(creatID) == '0') {
			printf("이전화면으로 돌아갑니다.\r\n\r\n");
			break;
		}

		int pIndex = CheckId(bank, creatID);
		if (CheckId(bank, creatID)==0) { //존재하지 않은 아이디
			if (type == 0) {
				double pwd = CreatePwd();
				if (pwd == 0)
					return 0;
				CreateID(bank, creatID, pwd);
				return pIndex;
			}
			else {
				printf("아이디가 존재하지 않습니다.\r\n\r\n");
			}
		}
		else { //아이디 존재 or 아이디 중복
			if(type==0)
				printf("아이디가 중복되어 있습니다.\r\n");
			else {
				printf("아이디가 존재합니다.\r\n");
				return pIndex;
			}
		}
	}
}

//비밀번호 만들기
double CreatePwd() {
	double pwd = 0;
	while (pwd < 10)
	{
		printf("비밀번호를 입력해주세요(2자 이상, 종료시 0) : ");
		scanf("%lf", &pwd);
		ClearLineFromReadBuffer();
		if (pwd == 0)
			return 0;
	}
	return pwd;
}

//계정만들기
void CreateID(Bank *bank, char* id, double pwd) {
	int perNum = PersonNum(bank); //만든 고객수
	(*bank).person[perNum].index = perNum + 1;
	(*bank).person[perNum].id = id;
	(*bank).person[perNum].password = pwd;
	(*bank).person[perNum].money = 0;

	printf("%d번째 등록되었습니다.\r\n\r\n", PersonNum(bank));
}

//아이디 체크 Person.index - 중복, 0 - 미중복
int CheckId(Bank* bank, char * ID) {
	int isOverlap = 0;

	int regpnum = PersonNum(bank);

	while (regpnum > 0)
	{
		char * regid = (*bank).person[regpnum-1].id;
		isOverlap = strcmp(regid, ID); //0 - 같음, 1 - 틀림

		if (!isOverlap)
			return regpnum;
		
		regpnum -= 1;
	}
	return 0;
}

//아이디 입력
char * InputID() {
	char * inputID = new char[100];
	char tempChar;
	int count = 0;
	do
	{
		tempChar = getchar();
		inputID[count] = tempChar;
		count += 1;
	} while (tempChar != '\n');
	inputID[count - 1] = '\0';
	char * sendID = strdup(inputID);
	delete[] inputID;

	return sendID;
}

//메모리 해제 함수
void Destory(Bank *bank) {
	int num = PersonNum(bank);
	while (num > 0)
	{
		delete[] (*bank).person[num - 1].id;
		num -= 1;
	}
}


//아이디 삭제

//입력버퍼비우기
void ClearLineFromReadBuffer() {
	while (getchar() != '\n');
}

//입금
void Deposit(Bank *bank, int arrNum, int money) {
	(*bank).person[arrNum].money += money;
	printf("현재 잔액은 %d원 입니다.\r\n", (*bank).person[arrNum].money);
}

//비밀번호 체크
// 0 - false, 1 - true
int CheckPwd(Bank *bank, int arrNum, double inputPwd) {
	return (*bank).person[arrNum].password == inputPwd;
}

//인증
// 0 : false, 1 : true, -1 : 종료
int Auth(Bank *bank, int ArrNum) {
	while (1)
	{
		double pwd = CreatePwd();
		if (pwd == 0)
			return -1;

		if (CheckPwd(bank, ArrNum, pwd)) {
			return 1;
		}
	}
}


//금전관련 입력받기
int InputMoney(char * ctrl) {
	int money = 0;

	printf("%s하실 돈을 입력하세요 : ", ctrl);
	scanf("%d", &money);

	ClearLineFromReadBuffer();

	return money;
}

//입금 컨트롤
void CtrlDeposit(Bank * bank, int ArrNum)
{
	int auth = Auth(bank, ArrNum);

	if (auth != -1) {
		char * text = "입금";
		int money = InputMoney(text);
		if(money!=0)
		Deposit(bank, ArrNum, money);
	}
}

//잔액조회
void DisplayBalance(Bank * bank, int ArrNum) {
	int auth = Auth(bank, ArrNum);
	if (auth != -1) {
		printf("잔액은 %d원 입니다.\r\n", GetBalance(bank, ArrNum));
	}
}

//잔액 가져오기
int GetBalance(Bank * bank, int ArrNum) {
	return (*bank).person[ArrNum].money;
}

//출금컨트롤
void CtrlWithdraw(Bank * bank, int ArrNum) {
	int auth = Auth(bank, ArrNum);
	int haveBalance = GetBalance(bank, ArrNum); //가지고 있는 금액
	int withdraw;
	char * text = "출금";
	do
	{
		withdraw = InputMoney(text); //값이 0이 리턴됨
		if (withdraw > haveBalance) {
			printf("출금 금액이 잔액보다 많습니다.\r\n");
		}
	} while (withdraw > haveBalance);
	Withdraw(bank, ArrNum, withdraw);
}

//출금
void Withdraw(Bank *bank, int arrNum, int money) {
	(*bank).person[arrNum].money += money*-1;
	printf("현재 잔액은 %d원 입니다.\r\n", (*bank).person[arrNum].money);
}