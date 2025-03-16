#include <iostream>

//1. C++11 시절 반환 타입을 후위에 표기한 것.
template<typename T1, typename T2>
auto Add1(T1 a, T2 b) -> decltype(a + b)
{
	if (b == 0) return a;
	return a + b;
}

//2.  C++14부터는 auto 만 표기해도 됩니다. 반환타입 자체를 생략.
// -> 컴파일러에게 return 문장을 보고 추론해 달라는 것.
// -> return 문장이 2개 이상이고 서로 다른 타입으로 반환하면 추론 못함. 컴파일 에러.

template<typename T1, typename T2>
auto Add2(T1 a, T2 b)
{
	if (b == 0) return a;
	return a + b;
}


int main()
{
	std::cout << Add1(1, 2.2) << std::endl;
	std::cout << Add2(1, 2.2) << std::endl;
}



