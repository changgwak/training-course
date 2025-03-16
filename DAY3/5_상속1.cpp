// 5_상속1.cpp   132page ~
#include <iostream>
#include <string>

// 상속
// 개념: 기존 타입을 확장해서 새로운 타입을 만드는 것

// 표기법
// C++		: class Student: public Person


// 용어
// Person	: Base(기반) class, Super class, Parent class
// Student	: Derived(파생) class, Sub class, child class

class Person
{
private:
	std::string name;
	int age;

public:
	Person(std::string n, int a) : name{n}, age{a} {}

};

class Student : public Person 
{	
	int    id;
};

class Professor : public Person
{
	int    major;
};

int main()
{
	Student s;
	Professor p;


}



