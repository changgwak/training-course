// 예제1     149 page
#include <iostream>
#include <vector>


class Shape
{
	int color = 0;
public:

};


class Rect : public Shape
{

	// int x,y,w,h, 생성자.. 등은 생략. 있다고 가정.
public:
	void draw() const { std::cout << "draw rect\n"; }

};


class Circle : public Shape
{
public:
	void draw() const { std::cout << "draw circle\n"; }


};

int main()
{
	std::vector<Shape*> v; // 한개의 컨테이너에 모두 보관 가능.

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			// 해결책 1. Shape* 인 s 를 Rect* 또는 Circle* 로 캐스팅
			// -> s가 가리키는 곳이 Rect 인지 Circle 인지 조사해야함.
			// 조사 방법은 내일.
			for (auto s : v)
			{
				if (s가 Rect 를 가리키면)
				{
					static_cast<Rect*>(s)->draw();
				}

				else if (s가 Circle 를 가리키면)
				{
					static_cast<Circle*>(s)->draw();
				}
			}

		}
	}
}

// OCP 원칙
// 기능 확장에는 열려있고(Open, 나중에 클래스가 추가되어도)
// 코드 수정에는 닫혀있어야 (Close, 기존 코드는 수정되지 않도록)
// 만들어야 한다는 원칙(Principle)


// Open Close Principle(개방 폐쇄의 법칙)

// 위 코드는 OCP를 만족할 수 없는 "나쁜 디자인" 입니다. 
// -> triangle 이 추가되면 코드 수정되어야 함.
