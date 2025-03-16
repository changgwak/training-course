#include <iostream>

// C++ 은 용도에 따라 사용하는 4개의 캐스팅이 있음.
// 일반적인 용도 : static_cast

// 특수 목적 : reinterpret_cast, const_cast, dynamic_cast



// static_cast : 논리적으로 맞고 위험하지 않은 경우만 허용
//			표준 타입끼리의 값 캐스팅
//          void*=> 다른 타입*,
//			상속관계의 캐스팅 등.
//          반드시 연관성이 있어야 한다


int main()
{
	double d = 3.4;
//	int    n = d;		// 에러는 아니지만 경고 발생(데이터 손실 가능)
	int	   n = static_cast<int>(d); // ok. 경고도 없음.
					// template square<int>(3) 와 비슷하게 생김.

	// void* -> int* 로 변경
	// -> 반드시 필요한 작업이다. static_cast 허용
//	int* p1 = malloc(100);     // C언어 : ok. C++ : 에러
	int* p2 = (int*)malloc(100);	// C 스타일 캐스팅
	int* p3 = static_cast<int*>(malloc(100));	// C++ 스타일

	// int* -> double* 로 변경
	// -> 위험한 작업이고, 일반적인 프로그래밍에서는 필요 없는 작업.
	// -> 그래서, static_cast 는 허용 안됨.
	// 만약 필요 했다면, 전용 캐스팅을 사용해라. -> reinterpret_cast
	double* p4 = (double*)&n;	// ok. 아주 위험한 캐스팅. C-style 캐스팅은 허용.
	double* p5 = static_cast<double*>(&n);	// error. 잘 모르면 그냥 static_cast만 써라.

	double* p6 = reinterpret_cast<double*>(&n);	// ok. 전용 캐스팅 사용.

	// 하지만 절대 아래처럼 사용하면 안됨.
	*p6 = 3.4;

	// 개발자 요청이므로 캐스팅은 허용하지만, 주의해서 사용해야 됨.
}



