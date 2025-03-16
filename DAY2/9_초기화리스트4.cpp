#include <string>

// 나쁜 코드
class Person1
{
	std::string name;
	int age;

public:
	// 1. 생성자 {} 안에서 멤버 데이터에 값을 넣는 경우
	Person1(const std::string& n, int a) 
	{
		// call std::stringLLstring() <- 즉, name에 대해서 디폴트 생성자 호출.

		name = n;	// 대입.
					// 즉, 이 코드는 2번의 함수 호출로 name 에 값을 넣은 것.
					// std::string name;
					// name = n;
					// 함수 호출 2번!

		age = a;
	}
};

Person1 p1{ "kim", 20 };

// 좋은 코드
class Person2
{
	std::string name;
	int age;

public:
	Person2(const std::string& n, int a) : name{n}, age{a}
	{
		// call std::string::string(n) <- 즉, 인자 1개 생성자 호출.
								// 생성자 1회 호출로 초기화 한것.
		//							성능이 더 좋음.
		//만약, 제어문 필요 시 여기에 대입 이용해야됨. 초기화X

	}
};

Person2 p2{ "kim", 20 };

int main()
{

}

// 결론 : 생성자에서 멤버 데이터를 초기화 할 때 
// -> 멤버 초기화 리스트 에서 하는 것이 빠름.
// -> 대입이 아닌 진짜 초기화(생성자 초기화 한것)

// std::string은 실제 클래스 이름이 아닌 alias 입니다.

// using string = std::basic_string<char, std::char_traits<char>, std::allocator<char>>;

