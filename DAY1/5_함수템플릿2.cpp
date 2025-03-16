#include <iostream>

//1. 인자 2개가 서로 다른 타입이 될수 있도록
//		타입 인자를 2개 받는 템플릿

// ? 를 채워야됨.
// -> 라이브러리 설계자들이 아래 같은 코드를 만들기 때문에 복잡한 코드가
// 필요하게 됩니다.
template<typename T1, typename T2>
? Add(T1 a, T2 b)
{
	return a + b;
}

int main()
{
	// 타입을 명시적으로 전달해도 되고 생략해도 됨.
	std::cout << Add<int, double>(1, 2.2) << std::endl;

	std::cout << Add(1, 2.2) << std::endl;

}



