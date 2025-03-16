void foo(int a)
{
}

// 함수 주소를 반환하는 함수 만들려면 
// -> 함수 포인터 변수 모양에서 변수 위치에 "함수이름()"를 적으세요.
//  void(*fi)(int) : f1 위치에 "함수이름()"
void (* goo(int, int) )(int)
{
	return &foo;
}

// 후위 반환 타입으로 하면 훨씬 보기 좋음.
auto hoo(int, int) -> void(*)(int)
{
	return &foo;
}

int main()
{
	// 함수의 주소를 담는 함수 포인터 변수 만들기
	void(*fi)(int) = &foo;


}

