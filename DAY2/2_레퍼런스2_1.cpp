int main()
{
	int n = 0;

	// pointer vs reference
	// 공통점 : 모두 다른 변수에 접근하기 위해서 사용.

	int* p1 = &n;
	*p1 = 10;

	int& r1 = n;
	r1 = 10;

	// 포인터는 초기값을 생략할수 있지만
	// 레퍼런스는 생략할수 없음.

	int* p2; // ok
	int* p3 = nullptr; // ok

	int& r2;	// error. 초기값 필요.
	int& r3 = nullptr; // error. 포인터 아님.

}

void f1(int* p)
{
	// 포인터는 0이 될 수 있으므로 아래처럼 하는 것이 안전.
	if (p != nullptr)
		*p = 10;

}
f1(nullptr);	// 이 코드가 가능하므로 위의 if 문이 필요.

void f2(int& r)
{
	r = 10;	// 항상 안전합니다. 0값 확인 없어도 됨.

}
f2(nullptr); // error. 반드시 인자로 유효한 변수만 가능합니다.


