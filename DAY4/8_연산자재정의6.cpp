#include <iostream>

class Vector
{
private:
	int* ptr;
	int  sz;

public:
	Vector(int size, int value)
	{
		sz = size;
		ptr = new int[sz];

		for (int i = 0; i < sz; i++)
			ptr[i] = value;
	}
	~Vector() { delete[] ptr; }

	int& at(int idx) { return ptr[idx]; }


	// operator[] 연산자 재정의
	// -> 객체를 배열처럼 사용가능하게 하기 위해 사용.
	// -> 멤버 함수로만 구현 가능(non-member 는 안됨.)
	// -> 등호의 왼쪽에 올수 있게 하기 위해 reference 로 반환
	//  "v[0] = 10"
	int& operator[](int idx) { return ptr[idx]; }

	
};

int main()
{
	Vector v(4, 0);

//	v.at(0) = 10;
	//	std::cout << v.at(0) << std::endl; 

	v[0] = 10; // v.operator[](0) = 10; 로 해석됨.
	std::cout << v[0] << std::endl; // 10

    v.operator[](1) = 10; // 이것도 가능하지만 잘 안 씀.
}


