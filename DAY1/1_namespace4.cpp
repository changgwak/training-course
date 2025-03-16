// 10 page 

// #include <stdio.h> // c언어용 헤더, printf가 global에만 있음. std 붙여서 못 씀.
#include <cstdio> // c++이 다시 만든 C언어용 헤더
					// 모든 C표준 함수가 global 과 std:: 안에 모두 있음.

// #1. C++에서는 대부분의 C헤더도 계속 사용가능.

// #2. C++은 모든 C언어 헤더를 다시 만들었음.
// <xxxx.h> 		==> <cxxxx>
// <stdio.h> 		==> <cstdio>
// <stdlib.h>    	==> <cstdlib>
// <string.h>    	==> <cstring>
// <math.h>    		==> <cmath>


int main()
{
	// printf 는 C 표준이지만 c++ 표준이기도 함.
	printf("hello\n"); // ok

	std::printf("hello\n"); // ??
}


