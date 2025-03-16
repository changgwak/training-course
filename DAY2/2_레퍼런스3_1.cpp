//  인자로 전달된 값을 수정하지 않고, 읽기만 하려고 합니다.
// 다음 중 좋은 코드는?

void f1(int n)	// call by value. int는 크기가 작아서 복사본 오버헤드가 작음.
{
	int k = n;
}

void f2(const int& n)
{
	// n은 refernece 지만 원리상 포인터 사용하는 경우가 대부분.
	int k = n;	// 따라서 이 코드는
	// int k = *(n 내부 포인터) 이므로 접근 시 오버헤드 발생.
}

int main()
{
	int x = 0;
	f1(x);
	f2(x);
}

// c++ 에서 함수 인자를 만드는 방법 - 반드시 외우고 규칙대로 사용하기.
//1. 인자의 값을 읽기만 하려고 함(in parameter)
// -> 인자의 타입이 primitive type 인 경우 (int, double 등)
//		-> call by value
//		-> void foo(int value)

// -> 인자의 타입이 user define type 인 경우(구조체, class)
//		-> const reference
//		-> void foo(const Rect& rc)

// 2. 인자의 값을 수정하려고 함. (in out parameter)
//    => 포인터   사용 : void inc1(int* p) { ++(*p);}
//    => 레퍼런스 사용 : void inc2(int& r) { ++r;}
//    => 결론: 레퍼런스 권장. 안전하고, 가독성이 좋은 코드


// 구글에서 C++ core guideline 검색 후 1번째 링크
// -> C++ 창시자가 만들고 있는 C++ 코딩에 대한 규칙 문서.


