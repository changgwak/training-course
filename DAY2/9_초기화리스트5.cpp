#include <iostream>



class Point
{
public:
	int x, y;

	// member initializer list 는 대입이 아닌 초기화 입니다.
	// 초기화는 멤버 데이터가 놓인 순서대로 수행됨.
	// 즉,	  (2)  (1)		<- 이 순서로 실행. : undefined error.
	Point() : y(0), x(y)	// error.
	{
	}
	// 권장
	// -> memebr intializer list 작성시
	// -> 멤버 데이터가 선언된 순서대로 작성해야됨.
};
int main()
{
	Point pt;

	std::cout << pt.x << std::endl; // 쓰레기값
	std::cout << pt.y << std::endl; // 0
}






