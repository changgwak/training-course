// 3_추상클래스 - 157page ~

// 추상 클래스 : 순수 가상 함수가 1개 이상 있는 클래스
// 특징: 객체를 만드는 것이 불가능.
// 의도: 파생 클래스 설계자에게 약속된 함수를 
//        파생 클래스에서 반드시 구현하도록 강제하고 싶을 때 사용.

class Shape
{
public:
	virtual void Draw()  = 0; // 순수 가상함수(pure virtual function)
								// -> 구현부가 없고, "= 0" 으로 표기
};
class Rect : public Shape
{
public:
	// Shape 가 가진 순수 가상함수 Draw의
	// 구현을 제공하지 않으면 Rect 도 추상 클래스
	// 구현을 제공하면		Rect 는 추상 클래스가 아님.
	void Draw() override { } 

};
int main()
{
	Shape s; // error. 추상 클래스는 객체 생성 불가능.
	Rect  r; // ?
}




