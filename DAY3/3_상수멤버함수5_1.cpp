#include <iostream>
#include <string>

// 논리적 상수성(logical constness)
// -> 외부 사용자 입장에서는 "상수 멤버 함수" 가 되는 것이 맞지만 
// -> 클래스 멤버 함수 구현 시 상수 멤버 함수 아에서 멤버 데이터 수정이 필요한 경우

// 해결책 : mutable  키워드

class Point
{
	int x, y;

	mutable std::string cache;			// mutable!
	mutable bool cache_valid = false;

public:
	Point(int a, int b) : x(a), y(b) {}

	std::string to_string() const	// const 는 맞음.
	{
		if (cache_valid == false)
		{
			cache = std::to_string(x) + " ," + std::to_string(y);
			cache_valid = true;
				// 이제 x,y 가 변경되는 함수에서 cache_valid = false 로 변경.
		}
		
		return cache;
	}
};

int main()
{
	const Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}



