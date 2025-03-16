// cout - 169page
#include <cstdio>

// std::endl 원리
// -> 어려운 내용. 몰라도 됨.

namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d", n); return *this; }
		ostream& operator<<(double d) { printf("%lf", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s", s); return *this; }
	

		ostream& operator<<(ostream& (*f)(ostream&))
	{
		f(*this);
		return *this;

	}
	};
	ostream cout;

	// endl 은 아래처럼 만들어진 함수.
	ostream& endl(ostream& os)
	{
		os << "\n";
		return os;
	}




}


int main()
{
//	std::cout << std::endl;	// 개행
	std::endl(std::cout);	// std::endl 은 함수이다.
	                        // 위 코드와 동일.

	std::cout << std::endl; // cout.operator<<(std::endl);


}




