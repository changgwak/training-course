#include <iostream>

// noexcept  - p182 - C++!1
// 1. 함수가 예외가 없음을 알릴때 사용
// 2. 함수가 예외가 없는지/있는지 조사할때 사용

// 모든 함수는 기본적으로 예외 가능성이 있음
void foo()
{

}

// 1. 함수를 만든 사람이 예외가 없다고 보잘 할수 있으므로
//    noexcept 를 붙이면 됨.
// -> 장점: 컴파일러가 보다 더 최적화된 기계어 코드를 만들게 되고
// -> 호출자가 예외 여부를 조사해서 보다 효율적인 코드를 작성 할수 있습니다.

// -> 단, 정호가히 알 때만 표기하기. 잘 모르면 표기 하지 말기.
void goo() noexcept
// void goo() noexcept(tru)
// void goo() noexcept(false)
// void goo() noexcept(다양한 조사를 통해서 결정할수도 있음)
{
}

int main()
{
	// 2. 함수가 예외가 없는지 조사
	bool b1 = noexcept(foo());
	bool b2 = noexcept(goo());

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	if (noexcept(goo()))
		goo();	// 예외 없다면 사용
	else
	{
		// 느리더라도 안전한 함수 사용.
	}

	std::pair<int, int> p;

}
