#include <iostream>

// 클래스를 만드는 방법
// 1. 클래스 선언에 함수 구현까지 포함하는 방법
// 2. 클래스 선언에는 멤버 함수는 선언만 넣고, 멤버 함수의 구현은 클래스 외부(.cpp) 에서 작성 하는 방법


// #1. 클래스 선언에 함수 구현까지 포함하는 방법
class Vector
{
	int* ptr;
	int sz;
public:
	Vector(int size, int value = 0)
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

	int& at(int idx)
	{
		return ptr[idx];
	};
	int size() { return sz; }
	bool empty() { return sz == 0; }

	void resize(int newsize)
	{
		if (sz < newsize)
		{
			int* tmp = new int[newsize];
			memcpy(tmp, ptr, sizeof(int) * sz);
			delete[] ptr;
			ptr = tmp;
			sz = newsize;
		}
	}
};

int main()
{
	Vector v1(5);	
	v1.at(0) = 7; 
	std::cout << v1.at(0) << std::endl;
}





