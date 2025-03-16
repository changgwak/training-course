#include <iostream>


class Vector
{
private:
	// 1. 동적 할당된 메모리를 관리하려면 아래 2개의 데이터 필요.
	int* ptr;	// 주소 관리
	int sz;		// 사이즈 메모리 관리

public:
	//#1. 생성자 실행 후의 메모리 모양을 생각해보자.
	Vector(int size, int value)
	{
		sz = size;
		ptr = new int[sz];

		for (int i = 0; i < sz; i++)
			ptr[i] = value;

	}
	// 생성자에서 동적할당한 메모리 등이 있다면
	// 소멸자를 만들어서 삭제하는 것이 관례

	~Vector()
	{
		delete[] ptr;
	}


};


int main()
{
	//#2. 아래 한 줄 실행 시 메모리 모양을 생각해보자.
	Vector v(4, 0); // 크기가 4인 동적 배열

	
}

// 복습 시 메모리 그림을 그리기.

