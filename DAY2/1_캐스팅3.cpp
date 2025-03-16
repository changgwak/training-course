#include <iostream>

// reinterpret_cast. 딱 아래 2가지 용도만 가능.
// 1. 서로 다른 타입의 "주소" 변환
// 2. 정수 <=> "포인터" 변환

int main()
{
	double d = 3.4;
	
	// 1. double* -> int* 변환
	int* p1 = (int*)&d;	// ok. C 캐스팅은 거의 모든 것을 허용.

	int* p2 = static_cast<int*>(&d);	// error. 서로 다른 타입 주소.
	int* p3 = reinterpret_cast<int*>(&d);	// ok. 서로 다른 타입 주소 전용 캐스팅

	// 2. 정수 -> 포인터
	int* p4 = 1000;	// error. 그냥은 정수를 포인터로 변환 불가능.
	int* p5 = (int*)1000;	// ok
	int* p6 = static_cast<int*>(1000);	// error
	int* p7 = reinterpret_cast<int*>(1000);	// ok. e.g, ip를 하드코딩할 때.

	// 3. reinterpret_cast 는 위 용도 외에는 사용 불가.
	// double -> int. double을 int로 변환.
	int n1 = d;	// ok. 하지만 경고.
	int n2 = reinterpret_cast<int>(d);	// error. 용도에 안 맞음.
	int n3 = static_cast<int>(d); // ok. 경고도 없음.

}



