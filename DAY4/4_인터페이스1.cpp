// 4_인터페이스 - 159 page ~
#include <iostream>

class Camera
{
public:
	void take() { std::cout << "take picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "take HD picture" << std::endl; }

};


class People
{
public:
	void use_camera(Camera* c) { c->take(); }
	void use_camera(HDCamera* c) { c->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

	// 위 코드의 문제점
	// -> OCP 위반
	// 기능확장에는 열려있고(Open), 코드 수정에는 닫혀야(Close) 한다는 이론(principle)

	// 객체지향 프로그래밍이 지켜야 하는 5대 원칙(논문 이론)
	// -> SRP, OCP, LSP, ISP, DIP -> 약자로 SOLID 원칙


}



