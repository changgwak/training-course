//

#include <iostream>

//constexpr 함수 주의사항'
// -> 컴파일 시간에 할수 없는 작업이 있는 함수는 
//		constexpr 이 될 수 없음

constexpr int Add(int a, int b)
{
	std::cout << "Add\n";	// 화면 출력은 컴파일 시간에 못함.
	return a + b;
}

int main()
{

}

