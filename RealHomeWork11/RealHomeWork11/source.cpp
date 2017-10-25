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
	printf("아버지가 말한다.\r\n");
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
	printf("아들이 말한다.\r\n");
}

void main() 
{
	Father f;
	f.Say(); //자식 함수 호출
	f.Action(); // 부모 함수 호출
	f.SayHello();

	Son s;
	s.Say();
	s.Action();
	s.SayHello();
}