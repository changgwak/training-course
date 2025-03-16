hpp, h 차이?

call by value

utf8


	// #4. Animal* 인 p3로 Dog 고유 멤버 에 접근하려면
	//     Dog* 타입으로 캐스팅해서 사용해야 한다.
	// 즉, 개발자가 Dog 가 맞다고, 컴파일러에게 알려주는 것

	static_cast<Dog*>(p3)->color = 10;// ok


	// 단, 이경우 p3가 가리키는 곳이 Dog 가 아니라면
	// 실행시간에 오류 나올수 있습니다.
	// 개발자 책임!!
	// "Dog 라는 확신" 이 있을때만 사용해야 합니다.


포인터, 레퍼런스, 



// 예제1     149 page
#include <iostream>
#include <vector>


// 2. 


class Rect
{

	// int x,y,w,h, 생성자.. 등은 생략. 있다고 가정.
public:
	void draw() const { std::cout << "draw rect\n"; }

};


class Circle
{
public:
	void draw() const { std::cout << "draw circle\n"; }


};

int main()
{
	std::vector<Rect*> v1;	// 왜 *??
	std::vector<Circle*> v2;

}





// s->draw()
// -> Rect의 draw() 안에서 Rect 가 추가한 멤버 접근하는 것은 문제 없음. Q)
