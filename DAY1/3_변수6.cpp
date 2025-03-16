// 3_변수6.cpp   31 page 

struct Point
{
	int x, y;
};
int main()
{
	Point pt = { 1,2 };

	// C/C++ 에서 사용하던 전통적인 방식
	int x = pt.x;
	int y = pt.y;

	// 1. C++17의 structure binding 문법
	//int a1, a2;
	auto [a1, a2] = pt;

}	// 2. auto만 사용 가능.
	int[b1, b2] = pt; // error

	// 3. 갯수가 동일해야됨.
	auto [c1, c2, c3] = pt;	// error
	auto [c1] = pt;			// error

	// 4. 특정 멤버는 관심 없을 때 
	auto [d1, _] = pt;	// ok
	auto [e1, _] = pt;	// error. 두번 사용은 안됨. 변수명이 _ 로 위에서 선언됨.(중복 변수명 사용 error)
	// 하지만 C++26 부터는 ok

	int _ = 10;	// ok
	int _ = 20; // C++26부터는 이름이 _ 인 변수는 여러 번 선언 가능.


	// 5. 구조체뿐만 아니라 배열도 가능.
	int arr[3] = { 1,2,3 };

	auto [e1, e2, e3] = arr;	// ok


// 참고
// visual studio 2022는 default가 C++14. 변경방법: 프로젝트 - 하단에 속성 - 
// 


