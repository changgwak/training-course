// 4_함수4
// C++ 함수의 특징 4. 함수 템플릿 - 39 page
// 중요합니다. 반드시 알아주세요.


/*
int square(int a)
{
	return a * a;
}
double square(double a)
{
	return a * a;
}
*/

// 타입만 다르고 구현이 유사(동일)한 함수가 여러 개 필요하면
// 1. 함수를 만들지 말고
// 함수를 찍어내는 틀(template)을 만들면 됨.

template<typename T> 
T square(T a)
{
	return a * a;
}



int main()
{
	// 함수 템플릿을 사용하는 방법 # 1. 타입인자를 명시적으로 전달
	square<int>(3);				// 1, 컴파일 할 때 int square(int) 함수 생성
								// 2. 이 위치는 call square(int) 기계어 생성.
	square<double>(3.4);		// 1. 컴파일 할 때 double square(double) 함수 생성.
								// 2. 이 위치는 call square(double) 기계어 생성.

	// 함수 템플릿을 사용하는 방법 # 2. 타입 인자 생략 가능.
	square(3); // 컴파일러가 함수인자 3으로 T =int  로 추론
	square(3.4);	// T=double 로 추론.
}

//1. godbolt 로 차이 이해.
//2. code bloat(코드 폭발) 현상
// -> 템플릿 사용 시 컴파일러가 너무나 많은 함수(클래스, 구조체) 등을 생성하므로 코드 메모리가 증가하는 현상.
// -> 임베디드 환경의 메모리가 부족한 경우 주의!

