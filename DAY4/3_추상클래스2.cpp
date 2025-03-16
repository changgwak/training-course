#include <iostream>
#include <vector>

// 순수 가상 함수가 있으면 추상 클래스.

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	
	void set_color(int c) { color = c; }

	// 가상 함수: 파생 클래스가 override 하지 않으면 기본 구현을 물려주겠다는 것.
	// 순수 가상 함수: 파생 클래스 설계자에게 반드시 약속된 함수를 만들라고 지시하는 것.

//	virtual void draw() const { std::cout << "draw shape\n"; }
	virtual void draw() const = 0; // 순수 가상 함수

	// 아래 처럼 했다면 
	// 모든 도형 설계자는 반드시 아래 함수를 구현해야 됨.
	// 만약 구현하지 않으면 컴파일 오류.
//	virtual int get_area() const = 0;

	// 아래 처럼 했다면 모든 도형 클래스가 반드시 구현 할 필요는 없음.
	virtual int get_area() const { return -1; }
};

class Rect : public Shape
{
public:
	void draw() const override { std::cout << "draw rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() const override { std::cout << "draw circle\n"; }
};


int main()
{
	std::vector<Shape*> v;	// 추상 클래스는 객체 생성 불가능.
								// -> 포인터로만 사용해야 가능.

	while (1)
	{
		int cmd = 0;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw(); 
			}
		}
	}
}



