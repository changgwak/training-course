#include <iostream>

// #1. 변수의 주소를 다른 타입 포인터로 캐스팅 하는 이유
// -> 메모리의 해석 방법을 변경(interpret) 하겠다는 의도
// -> ex. 4바이트 메모리를 1바이트 단위로 접근
//
int main()
{
	// ipv4 주소를 보관하려면 4바이트가 필요.
	int ip = 0x64646464; // 100.100.100.100

	// 변수 ip 에서 마지막 바이트만 0x30 으로 하고 싶다.
	ip = 0x30;	// ip 라는 변수 이름을 사용하면 4바이트 단위로 접근한것. 
				// ip = 0x0000030

	// ip가 사용하는 4바이트 메모리를 1바이트 단위로 접근하려면
	// 1. 비트 연산자 사용하거나
	// 2. ip 변수의 주소를 char* 로 캐스팅 해서 접근.

//	char* p = (char*)&ip;	// ok. C 스타일 캐스팅. legacy stype
//  char* p = static_cast<char*>(&ip); // error. C++ 기본 캐스팅. 위험.
	char* p = reinterpret_cast<char*>(&ip);	// ok. 이런 용도에 사용하라고 만든 캐스팅
	*p = 0x30;



}



