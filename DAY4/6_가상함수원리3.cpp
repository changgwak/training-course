#include <iostream>

//가상함수 원리   153page ~

class Animal
{
//	*vtptr = animal_가상함수테이블주소;
	int age;
public:
	virtual void Cry() {}
//	virtual void Run() {}
};
//--------------------
class Dog : public Animal
{
	int color;
public:
//	void Cry() override {}
};

int main()
{
	Animal a;
	Dog    d;

	std::cout << sizeof(a) << std::endl; // 4, int age 1개이므로 4 
	std::cout << sizeof(d) << std::endl; // 8

}


