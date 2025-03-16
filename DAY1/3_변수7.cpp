// nullptr1.cpp    24 page

int main()
{
	// 0의 정체 : 0은 정수지만 포인터로 암시적 형변환된다.
	int  n1 = 0; // ok
	int* p1 = 0; // ok. 나쁜 코드.

	int* p2 = n1; // error
					// 리터럴 0은 포인터로 암시적 형변화 되지만
					// 0으로 초기화된 정수형 변수는 포인터로 변환될 수 없다.

	// 0은 포인터가 아닌 정수라는 사실이 많은 혼란을 초래.

	// 그래서 C++11부터는 포인터 의미의 0을 추가 했음. (키워드)
	// 시험, exam
	int* p3 = nullptr; //ok. 좋은 코드.
	// int n4 = nullptr; // error. nullptr은 포인터 초기화에만 사용 가능.

	// c/c++ 의 모든 리터럴은 타입이 있음.
	// 3: int
	// 3.4: double
	// nullptr: std::nullptr_t 라는 타입. 모든 포인터 타입으로 암시적 형변환 됨.
	std::nullptr_t a = nullptr;
	int* p5 = a; // ok. 결국 a가 nullptr

	// 
}


