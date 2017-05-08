#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

typedef struct Person {
	int index;		 //1���� ����
	char * id;		 //�� ���̵�
	int money;		 //�ܾ�
	double password; //��й�ȣ
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
void CtrlRemittance(Bank *bank, int arrNum);
void DisplayUser(Bank *bank, int arrNum);
int InputRemit(int arrNum, int regNum);
void TransMoney(Bank * bank, int sender, int recever, int money);
void CtrlDeleteUser(Bank *bank, int arrNum);
void DeleteUser(Bank * bank, int arrNum);
void CtrlDeleteUser(Bank * bank, int arrNum);
int InputDeleteUser();

void main() {
	//ó�� ���۽� �ʱ�ȭ
	Bank bank = {};
	 
	while (1)
	{
		DisplayMenu();
		Contorl(&bank);
	}
}

//�޴� �����ֱ�
void DisplayMenu() {
	printf({
		"//////////////////////����//////////////////////\r\n"
		"1. �Ա�\r\n"
		"2. ���\r\n"
		"3. �۱�\r\n"
		"4. �ܾ���ȸ\r\n"

		"5. ���µ��\r\n"
		"6. ���»���\r\n"
		"////////////////////////////////////////////////\r\n"

		"0-����\r\n\r\n"
	});
}

// ����
void Contorl(Bank *bank) {
	int chose; //�޴� �Է°��� �����Ѵ�.
	printf("�޴��� �������ּ��� : ");
	chose = getch();
	printf("%c\r\n", chose);
	switch (chose - '0')
	{
	case 1:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1) - 1;
			if(ArrNum != -1)
				CtrlDeposit(bank, ArrNum);
		}
		break;
	case 2:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1) - 1;
			if (ArrNum != -1)
				CtrlWithdraw(bank, ArrNum);
		}
		break;
	case 3:
		if (IsCtrlBlock(bank)) {
			if (PersonNum(bank) < 2) {
				printf("��ϵ� ��� ���� ��� �̿� �Ұ��� �մϴ�.\r\n");
			}
			else {
				int ArrNum = CtrlAcc(bank, 1) - 1;
				if (ArrNum != -1)
					CtrlRemittance(bank, ArrNum);
			}
		}
		break;
	case 4:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1) - 1;
			if (ArrNum != -1)
				DisplayBalance(bank, ArrNum);
		}
		break;
	case 5:
		CtrlAcc(bank,0);
		break;
	case 6:
		if (IsCtrlBlock(bank)) {
			int ArrNum = CtrlAcc(bank, 1) - 1;
			if (ArrNum != -1)
				CtrlDeleteUser(bank, ArrNum);
		}
		break;
	case 0:
		Destory(bank);
		exit(0);
		break;
	default:
		printf("\r\n�߸��� �Է°��Դϴ�.\r\n");
		break;
	}
}

//���� ������ ���� ���ΰ�?
// 0 - ����, 1 - ���� �ʴ´�.
int IsCtrlBlock(Bank *bank) {
	if (PersonNum(bank)) {
		return 1;
	}
	else {
		printf("������ �������� �ʾ� �̿��� �Ұ����մϴ�.\r\n");
		return 0;
	}
}


//��ϵ� ��� ��
int PersonNum(Bank *bank) {
	int perNum = 0; // �����
	for (int i = 0; i < 100; i++) {
		if ((*bank).person[i].index == 0)
			return perNum;
		perNum += 1;
	}
	return perNum;
}
//�۱�

//���� ���� ��Ʈ��
// 0 : ���̵� ����, 1 : ���̵� ã��
// return Person.index ��
int CtrlAcc(Bank *bank, int type) {
	while (1)
	{
		printf("���̵� �Է����ּ���(�ִ� 100�� ,��� 0) : ");
		char * creatID = InputID();

		if (strcmp(creatID, "0") == 0) {
			printf("����ȭ������ ���ư��ϴ�.\r\n\r\n");
			return 0;
		}

		int pIndex = CheckId(bank, creatID);
		if (CheckId(bank, creatID)==0) { //�������� ���� ���̵�
			if (type == 0) {
				double pwd = CreatePwd();
				if (pwd == 0)
					return 0;
				CreateID(bank, creatID, pwd);
				return pIndex;
			}
			else {
				printf("���̵� �������� �ʽ��ϴ�.\r\n\r\n");
			}
		}
		else { //���̵� ���� or ���̵� �ߺ�
			if(type==0)
				printf("���̵� �ߺ��Ǿ� �ֽ��ϴ�.\r\n");
			else {
				//printf("���̵� �����մϴ�.\r\n");
				return pIndex;
			}
		}
	}
}

//��й�ȣ �����
double CreatePwd() {
	double pwd = 0;
	while (pwd < 10)
	{
		printf("��й�ȣ�� �Է����ּ���(2�� �̻�, ����� 0) : ");
		scanf("%lf", &pwd);
		ClearLineFromReadBuffer();
		if (pwd == 0) {
			printf("���� ȭ������ �ǵ��ư��ϴ�.\r\n\r\n");
			return 0;
		}
			
	}
	return pwd;
}

//���������
void CreateID(Bank *bank, char* id, double pwd) {
	int perNum = PersonNum(bank); //���� ����
	(*bank).person[perNum].index = perNum + 1;
	(*bank).person[perNum].id = id;
	(*bank).person[perNum].password = pwd;
	(*bank).person[perNum].money = 0;

	printf("%d��° ��ϵǾ����ϴ�.\r\n\r\n", PersonNum(bank));
}

//���̵� üũ Person.index - �ߺ�, 0 - ���ߺ�
int CheckId(Bank* bank, char * ID) {
	int isOverlap = 0;

	int regpnum = PersonNum(bank);

	while (regpnum > 0)
	{
		char * regid = (*bank).person[regpnum-1].id;
		isOverlap = strcmp(regid, ID); //0 - ����, 1 - Ʋ��

		if (!isOverlap)
			return regpnum;
		
		regpnum -= 1;
	}
	return 0;
}

//���̵� �Է�
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

//�޸� ���� �Լ�
void Destory(Bank *bank) {
	int num = PersonNum(bank);
	while (num > 0)
	{
		delete[] (*bank).person[num - 1].id;
		num -= 1;
	}
}

//�Ա�
void Deposit(Bank *bank, int arrNum, int money) {
	(*bank).person[arrNum].money += money;
	printf("���� �ܾ��� %d�� �Դϴ�.\r\n", (*bank).person[arrNum].money);
}

//��й�ȣ üũ
// 0 - false, 1 - true
int CheckPwd(Bank *bank, int arrNum, double inputPwd) {
	return (*bank).person[arrNum].password == inputPwd;
}

//����
// 0 : false, 1 : true, -1 : ����
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


//�������� �Է¹ޱ�
int InputMoney(char * ctrl) {
	int money = 0;

	printf("%s�Ͻ� ���� �Է��ϼ��� : ", ctrl);
	scanf("%d", &money);

	ClearLineFromReadBuffer();

	return money;
}

//�Ա� ��Ʈ��
void CtrlDeposit(Bank * bank, int ArrNum)
{
	int auth = Auth(bank, ArrNum);

	if (auth) {
		char * text = "�Ա�";
		int money = InputMoney(text);
		if(money!=0)
		Deposit(bank, ArrNum, money);
	}
}

//�ܾ���ȸ
void DisplayBalance(Bank * bank, int ArrNum) {
	int auth = Auth(bank, ArrNum);
	if (auth) {
		printf("�ܾ��� %d�� �Դϴ�.\r\n", GetBalance(bank, ArrNum));
	}
}

//�ܾ� ��������
int GetBalance(Bank * bank, int ArrNum) {
	return (*bank).person[ArrNum].money;
}

//�� ���� ���� ��Ʈ��
int CtrlMinusMoney(Bank * bank, int ArrNum, char * text) {
	int haveBalance = GetBalance(bank, ArrNum); //������ �ִ� �ݾ�
	int withdraw;
	do
	{
		withdraw = InputMoney(text); //���� 0�� ���ϵ�
		if (withdraw > haveBalance) {
			printf("%s �ݾ��� �ܾ׺��� �����ϴ�.\r\n", text);
		}
	} while (withdraw > haveBalance);

	return withdraw;
}

//�����Ʈ��
void CtrlWithdraw(Bank * bank, int ArrNum) {
	int auth = Auth(bank, ArrNum);
	if (auth) {
		int withdraw = CtrlMinusMoney(bank, ArrNum, "���");
		Withdraw(bank, ArrNum, withdraw);
	}
}

//���
void Withdraw(Bank *bank, int arrNum, int money) {
	(*bank).person[arrNum].money += money*(-1);
	printf("���� �ܾ��� %d�� �Դϴ�.\r\n", (*bank).person[arrNum].money);
}

//�۱� ��Ʈ��
void CtrlRemittance(Bank *bank, int arrNum) {
	int auth = Auth(bank, arrNum);
	if (auth) {
		//�۱��� ��� �����ֱ�
		DisplayUser(bank, arrNum);
		int input = InputRemit(arrNum, PersonNum(bank));
		if (input != 0) {
			int money = CtrlMinusMoney(bank, arrNum, "�۱�");
			input -= 1;
			TransMoney(bank, arrNum, input, money);
		}
	}
}

//�۱� ����, ������, �޴���, ��
void TransMoney(Bank * bank, int sender, int recever, int money) {
	(*bank).person[sender].money += money*(-1);
	(*bank).person[recever].money += money;
	printf("%d�� �۱� �Ϸ��߽��ϴ�.\r\n", money);
	printf("���� �ܾ��� %d�� �Դϴ�.\r\n", (*bank).person[sender].money);
}

//���� ������ �����Ѵ�.
void CtrlDeleteUser(Bank * bank, int arrNum)
{
	int auth = Auth(bank, arrNum);
	if (auth) {
		if (InputDeleteUser()) {
			printf("������ �����Ǿ����ϴ�.\r\n");
			DeleteUser(bank, arrNum);
		}
		else {
			printf("������ ������ ����Ͽ����ϴ�.\r\n");
		}
	}
}

void DeleteUser(Bank * bank, int arrNum) {
	int lastNum = PersonNum(bank) ;
	int startNum = arrNum;
	(*bank).person[arrNum] = {}; //�ϴ� �� �ʱ�ȭ
	while (startNum < lastNum)
	{
		int tempNum = startNum + 1;
		if (tempNum < lastNum) {
			Person tempUser;
			tempUser.index = startNum;
			tempUser.id = (*bank).person[tempNum].id;
			tempUser.money = (*bank).person[tempNum].money;
			tempUser.password = (*bank).person[tempNum].password;

			(*bank).person[startNum] = tempUser;
		}

		if (startNum == lastNum - 1) {
			(*bank).person[startNum] = {}; //������ �� ���� �ʱ�ȭ
		}
		startNum += 1;
	}
}

//���� ���� ���� ���� �Է� ��Ʈ�� return 0 - ���, 1 - ����
int InputDeleteUser() {
	char choseMenu;
	do
	{
		printf("������ �����Ͻðڽ��ϱ�?(y/n)");
		choseMenu = getch();
		printf("%c\r\n", choseMenu);
		if (choseMenu == 'y') {
			return 1;
		}
		else if (choseMenu == 'n') {
			return 0;
		}
		else {
			printf("�߸��� �Է°��Դϴ�.\r\n");
		}

	} while (1);
}

//�۱� �Է� ��Ʈ��
int InputRemit(int arrNum ,int regNum) {
	int input;
	do
	{
		printf("\r\n�۱��Ͻ� ���̵� �������ּ���(����-0) : ");
		scanf("%d", &input);
		ClearLineFromReadBuffer();
		if ((0 <= input && input <= regNum) && input != arrNum+1) {
			return input;
		}
		else if (input==0) {
			return 0;
		}
		else {
			printf("�߸��� �Է°��Դϴ�.\r\n");
		}
	} while (1);
}

//���� ���������ֱ�(���̵�, index)
void DisplayUser(Bank *bank, int arrNum) {
	int regNum = PersonNum(bank); //�� ��� ��
	int index = 0;
	while (index < regNum)
	{
		if (index != arrNum) {
			Person user = (*bank).person[index];
			printf("%d. %s\r\n", user.index, user.id);
		}
		index += 1;
	}
}

//�Է¹��ۺ���
void ClearLineFromReadBuffer() {
	while (getchar() != '\n');
}