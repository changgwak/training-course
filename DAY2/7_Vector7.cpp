#include <iostream>

// Step3. resize() 멤버 함수

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

	void resize(int new_size)
	{
		if (new_size > sz)	// 커지는 경우
		{
			int* tmp = new int[new_size];	// tmp 라는 새로운 포인터 변수 만들기

			memcpy(tmp, ptr, sizeof(int) * sz);	// tmp의 메모리는 sizeof 만큼 만드는데 ptr 꺼는 그대로 복사.

			delete[] ptr;	// ptr을 제거하는게 아니라
			// ptr 이 가리키는 주소의 메모리 제거.

			ptr = tmp;	// ptr이 tmp의 주소를 가리키도록 하기.

			sz = new_size;


		}
		else
		{
			// 작아지는 경우
		}


	}
};

int main()
{
	Vector v(4, 0);

	v.at(0) = 10;

	v.resize(8);  //// 8 개로 키우기 


	std::cout << v.at(0) << std::endl; // 10
}

