#include <iostream>

// Step 5. int 뿐만 아니라 다른 타입도 보관 가능하도록 하기.
// -> 클래스가 아닌 클래스를 만드는 template 설계
// -> 함수 뿐 아니라 클래스(구조체) 도 template 만들수 있음.


template<typename T>
class Vector
{
private:
	T* ptr;	// double이 되면 double* 이어야 하므로 T 로 하자
	int  sz;

public:
	Vector(int size, T value)
	{
		sz = size;
		ptr = new T[sz];

		for (int i = 0; i < sz; i++)
			ptr[i] = value;
	}
	~Vector() { delete[] ptr; }

	T& at(int idx) { return ptr[idx]; }

	void resize(int new_size)
	{
		if (new_size > sz)	// 커지는 경우
		{
			T* tmp = new T[new_size];	// tmp 라는 새로운 포인터 변수 만들기

			memcpy(tmp, ptr, sizeof(T) * sz);	// tmp의 메모리는 sizeof 만큼 만드는데 ptr 꺼는 그대로 복사.

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

	int size() { return sz; }
	bool empty() { return sz == 0; }
};

int main()
{
	// 함수 템플릿은 템플릿 인자 생략해도 되지만 (함수 인자로 추론)
	// 클래스 템플릿은 반드시 타입인자 전달해야됨. e.g, <int>, <double>
	Vector<int> v(4, 0);

	Vector<double> v(4, 0);

	v.at(0) = 10;

	v.resize(8);

	std::cout << v.at(0) << std::endl; // 10

	std::cout << v.size() << std::endl; // 8
}

