// pointer2.cpp

void foo(int* p)
{
	// main 에서 할당한 메모리 n을 여기서 접근하고 싶다.
	// -> 이름은 자신을 선언한 블록{}에서만 사용 가능.
	// -> main 에서 주소를 보내주고 포인터 변수로 받아야 한다.
	*p = 20;
}

int main()

{

	int n = 10;
	
	foo(&n); // n의 주소를 보냄.


}
