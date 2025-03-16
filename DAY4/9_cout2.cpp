// cout - 169page
// #include <iostream>
#include <cstdio>


// 사용자가 std namespace 를 만들어서 추가하면 안되지만, 아래 코드는 학습을 위해서.

namespace std
{
	class ostream
	{
	public:
		// 실제 화면 출력은 아래 처럼 printf 가 아니고
		// 각 OS의 시스템콜을 사용함.(복잡한 코드)

		void operator<<(int n) { printf("%d\n", n); }
		void operator<<(double d) { printf("%lf\n", d); }
		void operator<<(const char* s) { printf("%s\n", s); }
	};

	ostream cout;
}


int main()
{
	int    n = 10;
	double d = 3.4;

	std::cout << n;
	std::cout << d;



}




