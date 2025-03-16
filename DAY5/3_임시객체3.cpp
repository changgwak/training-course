
#include <iostream>




class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

void draw_line(const Point& from, const Point& to) {}

int main()
{
	// draw_line 함수로 (1,1) - (5,5)에 선을 그려보세요.

	Point p1(1, 1);
	Point p2(5, 5);

	draw_line(p1, p2);

	// p1, p2가 더 이상 필요 없음. 즉시 파괴되었을까?

	// 핵심: 함수 인자로만 사용할 객체가 필요하면
	//			임시객체(temporary) 로 전달하는 것이 효율적.
	draw_line(Point(1, 1), Point(5, 5));
					// 이때 () 사용하면 함수호출 로 오해 할 수 있음.

	draw_line(Point{ 1,1 }, Point{ 5,5 }); // C++11 이후에는 이 코드 권장

}







