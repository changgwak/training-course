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
			for (auto s : v)	// s는 Shape* 임.
				s->draw();	// A, error, 

		}
	}
}

// 위 코드는 어디서 왜 에러인가?
// -> A 부분
// -> s의 타입이 Shape*인데, Shape 에는 draw 가 없음.
// -> Shape* 로는 Shape 의 멤버만 접근 가능하고
//    Rect, Circle 이 추가한 멤버 접근 안됨. 
// 
// 해결책은 뭘까요 ?
// => 다음 소스에서!!!
// 이소스는 에러의 이유만 정확히 알아 두세요
