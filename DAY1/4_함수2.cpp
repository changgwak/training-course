#include <cstdio>
// 37page. overloading 

// 1. 함수 오버로딩
// -> 동일한 이름의 함수를 여러 개 만들 수 있음.
// -> 단, 인자의 갯수나 타입이 달라서, 호출 시 구별 가능해야됨.
int square(int a)
{
	return a * a;
}

double square(double a)
{
	return a * a;
}

int main()
{
	square(3);
	square(3.4);
}


