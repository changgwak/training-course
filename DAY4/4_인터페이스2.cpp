// 4_인터페이스 - 159 page ~
#include <iostream>

// 카메라를 먼저 만들지 말고
// 카메라 제작자와 카메라 사용자 사이에 지켜야 할 규칙을 먼저 설계하자

// 규칙: 모든 카메라는 아래 클래스로부터 파생된다.
class ICamera
{


public:
	virtual void take() = 0; // 순수 가상 함수. 
				// 모든 파생 클래스는 반드시 take() 함수를 구현해야 한다.
	virtual ~ICamera() {}
};


// 실제 카메라는 아직 없지만 규칙은 있음.
// 카메라 사용자는 카메라 규칙을 따라야함.
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



