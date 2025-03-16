#include <iostream>
// p154
//가상함수를 사용하면 컴파일러가 아래와 같이 많은 코드를 추가합니다.

void* animal_vftable[] = { Animal_TYPE_INFO, &Animal::Cry, &Animal::Run };
// &Animal::Cry: 가상함수의 주소.
// 가상함수가 많으면 메모리 오버헤드가 발생.



class Animal
{
	void* vtptr = animal_vftable;  // <= 컴파일러가 추가한 멤버
	int age;
public:
	virtual void Cry() {}
	virtual void Run() {}
};
//--------------------

void* dog_vftable[] = { Dog_TYPE_INFO, &Dog::Cry, &Animal::Run };
class Dog : public Animal
{
	void* vtptr = dog_vftable;
	int color;
public:
	void Cry() override {}
};

int main()
{
	Animal a1, a2;
	Dog    d;

	Animal* p = &d; 
	p->Cry();  


	// 1. p 는 Animal* 이므로 Animla 클래스에서
	//	     Cry 가 가상인지 아닌지 조사.
	//  가상이 아니면 : p->Animal::Cry() 호출

	// 가상이면, 몇 번째 가상함수인지 순서를 조사.
	// 그리고 vtptr 에서 해당 가상함수의 주소를 얻어서 호출.
	// 즉, 기계어 코드: p->vtptr[1]();  // p->vtptr[1] == &Dog::Cry
}


// 가상함수를 사용 시 오버헤드 발생
// 1. 메모리 오버헤드
// -> 클래스 당 1개의 가상함수 테이블(배열) 생성
//    가상함수가 1000개라면 1000*포인터 크기 만큼의 메모리 사용.(오버헤드)
// -> 객체당 1개의 가상함수 테이블을 가리키는 포인터 추가

// 2. 실행시간 오버헤드 (속도에 대한 오버헤드)
// -> 직접 호출이 아니라, 메모리에서 주소를 꺼내서 호출해야됨.
//    2~3회 정도의 메모리 접근이 필요(컴파일러마다 원리는 약간씩 다를수 있음.)


