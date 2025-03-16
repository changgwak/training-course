#include <iostream>

class Point
{
	int x;
	int y;
public:
	// exam, 시험. 다음 중 생성자에 대한 설명 중 틀린 것은?
	// 생성자
	// 1. 클래스 이름과 동일한 멤버 함수
	// 2. return 타입을 표기하지 않고 인자는 없어도 되고 있어도 됨.
	// 3. 여러개 만들 수 있음.
	// 4. 객체를 생성하면 반드시 생성자가 호출된다.
	// 5. 개발자가 생성자를 1개도 안 만들면 컴파일러가 인자 없는 생성자 제공.
	// -> (인자 없는 생성자를 defualt 생성자 라고 함.)

	Point()             { x=0; y=0; std::cout << "Point()"         << std::endl; } // 생성자1
	Point(int a, int b) { x=a; y=b; std::cout << "Point(int, int)" << std::endl; } // 생성자2
};
int main()
{
	// 6. C++98 스타일 객체 생성 방식
	Point p1;		// 생성자1 호출
	Point p2(1, 2); // 생성자2 호출

	// 7. C++11 부터는 {}도 사용 가능. {}가 trend
	Point p3{ 1,2 };   
	Point p4 = { 1,2 };	// -> Point 에 생성자 없고 x,y 가 public 이면 구조체 초기화 구문. 
						// -> Point 에 생성자가 있다면 생성자 호출.
						// -> 생성자 없는데 x,y 가 private 이면 error

	// 8. 객체가 생성되면 반드시 생성자를 호출 해야됨.
	Point arr1[5];		// 배열, 생성자1번이 5회 호출
	Point arr2[5] = { {1,2},{2,3} };	// 생성자2번이 2회, 생성자1번이 3회 호출


	Point* p; // 객체 생성 아님, 생성자 호출 안됨.

	// 9. malloc vs new
	p = (Point*)malloc( sizeof(Point) );	// 8 바이트 메모리 할당
											// 생성자 호출 안됨
											
	free(p);							// 메모리 해지, 소멸자 호출 안됨.

	p = new Point;	// 데이터 타입, 생성자 호출됨. 디폴트 생성자 
	delete p;		// 소멸자 호출

	p = new Point(1, 1); // 생성자 2번 호출
	delete p;

}
// malloc: 메모리 할당
// new  : 객체 생성 (메모리 할당 + 생성자 호출)

//python
// c = Car() // 1. Car 크기의 메모리 할당 후 init 메소드 호출.

// Car.__new__()
// c.__init__()

