#include <iostream>

// 함수 객체는 "동작 뿐 아니라 상태도 있습니다."
// => 멤버 데이타가 있다는 의미

// => 파이썬도 () 연산자 재정의 됩니다. 함수 객체 기술있습니다.

class URandom  // unique random 이라는 의미로!!
{
	int history[10];	// 좋게 하려면 10 비트로(비트 필드등의 기술)
public:

	URandom() {} // 생성자도 활용 가능

	int operator()()
	{
		// 난수 구한후, history 에 있었다면 다시 구하고
		// 없으면, history 에 기록후 리턴
		return rand() % 10;
	}
};

URandom urand;  // urand 는 객체지만 () 연산자를 재정의했으므로
// 함수처럼 사용가능합니다

int main()
{
	for (int i = 0; i < 10; i++)
		std::cout << urand() << std::endl;
}

