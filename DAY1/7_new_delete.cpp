// 메모리할당 - 47 page
#include <iostream>

int main()
{
	// C 스타일
	int* p = (int*)malloc(sizeof(int) * 20);
	free(p);

	// C++ 스타일
	int* p1 = new int; // int 한개, 즉, 4바이트 할당.
	delete p1;		// 메모리 제거

	int* p2 = new int[10];	// int 10개. 
	delete[] p2;			// 배열 할당한 경우는 배열로 delete 사용.

//	delete p2;	// 이렇게 하면 버그. "undefined behavior(미정의 동작)" 발생

}

// RUST 철학
// -> C++ "undefined behavior" 나쁘다.
// -> 왜? 미정의 동ㅇ작을 컴파일 되게 하는가?
// -> 차라리 컴파일 에러 나오게 하지.

//					malloc				new
// 정체				함수					키워드
// 헤더				<stdlib.h> 필요		키워드 이므로 헤더 필요 없음

// 인자				정수(크기)			데이타 타입

// 반환타입			void*				인자로 전달되는 타입의 포인터
//					사용자가 원하는 타입	캐스팅 필요없음
//					포인터로 캐스팅해서사용
// 
// 결정적 차이		생성자 호출안됨		생성자 호출됨

