// 3_변수5
// 30 page ~

// 1. C언어는 typedef
typedef int DWORD;
typedef void(*PF)();

// 2. C++11 부터는 using 사용.
// -> 아래 2줄은 위 코드와 완전히 동일.
using DWORD = int;
using PF = void(*)();

// 3. using 을 만든 이유
// typedef : 타입의 별명만 만들 수 있음.
// using : 타입의 별명 + 템플릿의 별명도 만들수 있음.


// 4. 하나의 키워드가 여러가지 의미로 사용는 경우가 있음.
// using declaration, directive : namespace 에서 사용
// using alias : 타입의 별명을 만들 때 사용.

int main()
{
	DWORD n; // int n
	PF    f; // void(*f)()
}



