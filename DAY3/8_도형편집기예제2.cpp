// 예제1     149 page
#include <iostream>
#include <vector>


// #2. 모든 도형은 공통의 특징(color등) 이 있다.
// => 기반 클래스를 만들어서 관리하면 된다.

// #3. 또한, 기반 클래스(Shape) 가 있다면
// => 모든 도형을 한개의 컨테이너에 같이 보관할수 있다.
// => 객체지향 디자인에서 아주 널리 사용되는 개념!!  중요!!!


class Shape
{
	int color = 0;
public:

};


class Rect : public Shape
{

	// int x,y,w,h, 생성자.. 등은 생략. 있다고 가정.
public:
	void draw() const { std::cout << "draw rect\n"; }

};


class Circle : public Shape
{
public:
	void draw() const { std::cout << "draw circle\n"; }


};

int main()
{
	std::vector<Shape*> v; // 한개의 컨테이너에 모두 보관 가능.

}






