// cout - 169page
#include <cstdio>

namespace std
{
	class ostream
	{
	public:
		ostream& operator<<(int n) { printf("%d\n", n); return *this; }
		ostream& operator<<(double d) { printf("%lf\n", d); return *this; }
		ostream& operator<<(const char* s) { printf("%s\n", s); return *this; }
	};

	ostream cout;
}


int main()
{
	int    n = 10;
	double d = 3.4;

	std::cout << n << ", " << d;
	// cout.operator<<(n).operator<<(", ").operator<<(d);

}




