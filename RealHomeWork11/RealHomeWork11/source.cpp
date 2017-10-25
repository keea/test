#include <stdio.h>

class Person 
{
private:
	
	virtual void Say() = 0;
public:
	virtual void Action();
	void SayHello();
};

void Person::SayHello() {
	Say();
	printf("Hello!!! \r\n\r\n");
}

void Person::Action() {
	printf("I'm your ");
}


class Father : public Person
{
private:
public:
	virtual void Action();
	virtual void Say();
};

void Father::Say() 
{
	printf("�ƹ����� ���Ѵ�.\r\n");
}

void Father::Action() {
	Person::Action();
	printf("Father\r\n\r\n");
}



class Son : public Father{
private:
public:
	virtual void Action();
	virtual void Say();
};

void Son::Action() {
	Person::Action();
	printf("Son\r\n\r\n");
}

void Son::Say() {
	printf("�Ƶ��� ���Ѵ�.\r\n");
}

void main() 
{
	Father f;
	f.Say(); //�ڽ� �Լ� ȣ��
	f.Action(); // �θ� �Լ� ȣ��
	f.SayHello();

	Son s;
	s.Say();
	s.Action();
	s.SayHello();
}