// 4_인터페이스 - 159 page ~
#include <iostream>


// 용어 정리
// 인터페이스: 지켜야 할 규칙만 가진 클래스. (순수 가상 함수만 가진 클래스인듯.)
// 추상 클래스: 지켜야 하는 규칙 + 다른 멤버도 있는 클래스


// 규칙: 모든 카메라는 아래 클래스로부터 파생된다. 라고 표현하지 말고.
//			모든 카메라는 아래 클래스의 인터페이스를 구현해야 한다. 라고 표현하자.
class ICamera
{
public:
	virtual void take() = 0; // 순수 가상 함수. 
	// 모든 파생 클래스는 반드시 take() 함수를 구현해야 한다.
	virtual ~ICamera() {}	// 인터페이스도 결국 문법적으로는 기반 클래스이므로 
	//							소멸자 필요. 소멸자는 virtual 소멸자로 만들어야 함.
};


class People
{
public:
	void use_camera(ICamera* c) { c->take(); } // 객체는 없지만 포인터로 주소는 가리킬수 있음.
};

class Camera : public ICamera
{
public:
	void take() override { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() override { std::cout << "take HD picture" << std::endl; }

};

class UHDCamera : public ICamera
{
public:
	void take() override { std::cout << "take UHD picture" << std::endl; }

};


int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uhc;
	p.use_camera(&uhc);

}



