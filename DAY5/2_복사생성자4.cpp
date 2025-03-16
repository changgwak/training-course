#include <iostream>


// 

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

	// 사용자가 직접 만드는 복사 생성자.
	// -> 깊은 복사(deep copy) 로 구현
	Vector(const Vector& v): sz(v.sz)
	{
		// 1. 포인터가 아닌 멤버는 그냥 복사
		// sz = v.sz; <-- 이 위치보다는 초기화리스트가 좋다.

		// 2. 포인터는 메모리 할당 후, 메모리 자체를 복사.
		ptr = new int[sz];
		memcpy(ptr, v.ptr, sizeof(int) * sz);


	}
};

int main()
{
	Vector v1(4, 0);

	Vector v2 = v1;

}
