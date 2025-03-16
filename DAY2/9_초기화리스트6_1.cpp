#include <iostream>

int g = 10;

class Point
{

	int x = 0;	
	int y = ++g; // 나쁜 코드. 절대 사용 말기.
				// = 0 같은 literal 초기화만 사용.
public:
	Point() {}				// : x(0), y(++g)	{}
	Point(int a) : y{ a } {}	// : x(0), y(a) {}
};


int main()
{

	Point p1;
	Point p2(3);

	std::cout << g << std::endl;	// result : 11

}


// Zig 언어 :  보이는 대로 실행 된다.
//			=> 컴파일러가 추가하거나 변경하지 않는다.
//			=> 요즘 임베디드 분야에서 뜨고 있는 언어.










