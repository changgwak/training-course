//

int a;		// a는 int 타입 변수
double d;	// d는 double 타입 변수
int arr[2];	// arr 배열 변수

void foo(); // foo 는 함수 선언

void(*f)(); // f는 함수 포인터 변수
int(*p)[2]; // p는 배열을 가리키는 포인터 변수



// typedef : 변수 위치의 심볼을 타입으로 해달라.
typedef int A;		// A는 int 타입 타입
typedef double D;	// D는 double 타입  타입
typedef int ARR[2]; // ARR 배열  타입

typedef void FOO();	// FOO 는 함수  타입
typedef void(*F)();	// F 는 함수 포인터  타입
typedef int(*P)[2];	// P 는 배열을 가리키는 포인터  타입

// using ARR = int[2];

int main()
{
	A n1 = 10;
	D d1 = 2.3;

	ARR x = { 1,2 }; // integer 2개짜리 배열.

	F f1 = nullptr; // f 는 함수 포인터 타입.
	                // void(*f1)() = nullptr;
	P p1 = &x;

	FOO ff; // FOO 는 함수 타입이므로
	        // 이 코드는 ff 라는 함수의 선언 입니다.
	        // void ff(); 입니다.
}

