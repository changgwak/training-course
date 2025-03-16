#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // pt 는 이름있는 객체(named object)
					// 이름이 있으므로 여러 문장에서 접근 가능.
					// 수명: 자신을 선언한 {} 을 벗어날 때 파괴됨.

//	Point (1, 2);	// 이름이 없는 객체(unnamed object)
					// <- Point 는 함수가 아님. 함수 호출 아님.
					// 이름이 없으므로 다른 문장에서 사용 못함.
					// 수명: 자신을 선언한 문장의 끝(;)에서 파괴됨.

					// 임시 객체(tmeporary) 라고도 부름
					// RUST 언어 에서도 아주 중요.

	Point(1, 2), std::cout << "X\n";

	std::cout << "-------" << std::endl;
}







