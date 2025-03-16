#include <vector>

class Animal
{
public:	int age;
};

class Dog : public Animal
{
public:	int color;
};

class Cat : public Animal
{
public:	int speed;
};


// upcasting 활용/장점 1. 동종을 처리하는 함수
					//	(동일 기반 클래스를 사용하는 타입들)
// 새해가 되면 한 살이 증가하게 하는 함수
// void NewYear(Dog* p)	// Dog 객체만 처리하는 함수.
void NewYear(Animal* p)	// 모든 동물 처리 가능.
{
	++(p->age);

}



int main()
{
	Dog d;
	Cat c;
	NewYear(&d);
	NewYear(&c);

	// Upcasting 활용/장점 2.
	std::vector<Dog*> v1;	// Dog 객체만 보관하는 vector
	std::vector<Animal*> v2;	// 모든 동물 객체를 보관하는 vector 컨테이너
								// 동종을 보관하는 컨테이너(컬렉션)
								// color, speed 는 사용 못함. 내일 배움.
	
}



