#include "Vector.h"

int main()
{
	Vector v1(5);
	v1.at(0) = 7;
	std::cout << v1.at(0) << std::endl;
}


// 헤더 include
#include <헤더파일>  // 컴파일러가 약속된 폴더에서 파일을 찾게 됨.
					// 표준 헤더 파일 include 할 때 사용

#include ""헤더파일" // 현재 디렉토리에서 파일을 찾게 됨.
					// 사용자가 만든 헤더 파일을 include 할 때.


