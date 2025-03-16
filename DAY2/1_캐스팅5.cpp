// 아래 예제는 실전에서는 사용할 이유가 없는 예제.
// -> 단지 문법 설명을 위한 것.

int main()
{
	const int c = 10;

	// c의 주소를 double* 에 담고 싶습니다.
	double* p1 = (double*)&c; // ok, C 스타일. 위험한 코드.

	// C++ 스탙일로 캐스팅 해보세요.
	double* p2 = static_cast<double*>(&c); // error. 다른 타입이라 안됨.
	double* p2 = reinterpret_cast<double*>(&c); // error. 상수성 제거 안됨.
	double* p2 = const_cast<double*>(&c); // error. 상수성 제거는 가능하지만 동일 타입만 가능.

	double* p2 = reinterpret_cast<double*>(const_cast<int*>(&c)); //ok
	// const int* => int* 로 상수성 제거 후
	// int* => double*    로 변경
	// 개발자 의도가 명확함.

}







