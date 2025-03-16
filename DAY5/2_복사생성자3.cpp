#include <iostream>

// 왜 복사생성자를 알아야 하나요 ?
// 그냥 컴파일러가 만들어주는 것 사용하면 안되나요 ?
// => 대부분의 경우는 컴파일러 버전사용하면 됩니다.

// 그런데, 사용자가 만들어야 할때가 있습니다.
// => 아래 코드!!! (중요합니다. , C++뿐 아니라 모든 언어에 있는 개념)


// 클래스 안에 포인터 멤버가 있다면

// 컴파일러가 제공하는 복사 생성자는 "얕은 복사(Shallow Copy)" 현상을
// 일으키게 됩니다.

// 사용자가 반드시 복사 생성자를 만들어서 해결해야 합니다.
// => 다음소스에서 해결

class Vector
{
private:
	int* ptr;
	int  sz;
public:
	Vector(int size, int value) : sz(size)
	{
		ptr = new int[sz];
		for (int i = 0; i < sz; i++)
			ptr[i] = value;
	}
	~Vector() { delete[] ptr; }
};

int main()
{
	Vector v1(4, 0);

	Vector v2 = v1; // 이 코드가 있으면 이 소스는 버그 입니다.

}
