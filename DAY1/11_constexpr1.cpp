// 69 page

// 프로그래밍 세계에서 "상수" 라는 용어가 가진 2가지 의미
// -> 대부분의 언어에 적용되는 개념

//1. 실행시간에 변경할 수 없다. - immutable, readonly
// // -> C/C++의 const 키워드
// --> 컴파일 시간에 값을 알 필요는 없다.
// --> 따라서, "초기값으로 변수도 사용 가능!" <= 핵심
// 
//2. 컴파일 시간에 값을 알 수 있다. - compile time constant, compile time expression.

// -> C++11에ㅔ서 추가된 constexpr
// -> 반드시 컴파일 할 때 초기값을 알아야 함.
// -> 즉, 초기값으로 변수 사용 안됨 <= 핵심

// 왜? 컴파일 시간에 값을 아는 것이 중요한가?
// -> 1. 거의 완벽한 최적화(모든 연산을 컴파일 시가넹 수행가능)
// -> 2. C++은 많은 문법이 컴파일 시간에 값을 알아야 함.
//		--> 배열의 크기, 템플릿 인자 등.


// 시험, exam. 다음 중 error 인것은?
int main()
{
	int n = 3;

	const     int c1 = 3;	// ok
	const     int c2 = n;	// ok

	constexpr int c3 = 3;	// ok
	constexpr int c4 = n;	// error

}

