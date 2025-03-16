#include <iostream>


class Vector
{
private:
	int* ptr;	// 주소 관리
	int sz;		// 사이즈 메모리 관리

public:
	Vector(int size, int value)
	{
		sz = size;
		ptr = new int[sz];

		for (int i = 0; i < sz; i++)
			ptr[i] = value;

	}

	~Vector()
	{
		delete[] ptr;
	}

	//핵심: reference return을 하면 함수 호출을 등호의 왼쪽에 놓을 수 있음.
	// "v.at(0) = 10" 이 가능.
	int& at(int idx) { return ptr[idx] ; }

};


int main()
{
	Vector v(4, 0); // 크기가 4인 동적 배열

//	v[0] = 10; // 실제 배열은 이렇게 하지만, 우리가 지원하려면 연산자 재정의 필요(5일차)

	v.at(0) = 10;
	v.at(1) = 20;

	std::cout << v.at(0) << std::endl;	// 10
	std::cout << v.at(1) << std::endl;	// 20
	std::cout << v.at(2) << std::endl;	// 0

}

// 복습 시 메모리 그림을 그리기.

