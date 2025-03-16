// 6_함수1.cpp  34 page ~
// C++함수의 특징 1. 디폴트 파라미터

// 디폴트 값 사용 가능.
void foo(int a = 0, int b = 0, int c = 0);
//{
//}

// exam, 시험
// void f1(int a = 0, int b, int c =0) {};	// error


// 3. 원리
// godbolt.org 에서 확인.

int main()
{
	foo(1, 2, 3);
	foo(1, 2);		//1, 2, 0
	foo(1);			// 1, 0, 0
	foo();			// 0, 0, 0
}

// void foo(int a = 0, int b = 0, int c = 0)	// error
// void foo(int a , int b, int c ) // ok
void foo(int a /*= 0*/, int b /*= 0*/, int c /*= 0*/)	// ok
{

}


