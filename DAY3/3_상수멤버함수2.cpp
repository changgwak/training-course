// 상수 멤버함수는 "선택" 이 아닌 "필수" 임.
// -> 객체의 상태를 변경하지 않은 모든 멤버 함수는
//		반드시 상수 멤버 함수로 해야 됨.

// -> getter( getxxx 류의 함수들) 은 모두 상수 함수 이어야 함.

// github.com/webkit

// webkit 선택후
// Source/WTF/wtf 에서 seconds.h 에서 멤버 함수 보세요.. 


class Rect
{
	int x, y, w, h;
public:
	Rect(int a, int b, int c, int d)
		: x(a), y(b), w(c), h(d) {}

	// int getArea() { return w * h; }	// 틀린 코드.
	int getArea() const { return w * h; }	// 반드시 상수 멤버 함수로 했어야 됨. const
};


// void foo(Rect r)	// call by value. 복사본 오버헤드 있음.
void foo(const Rect& r)
{
	int n = r.getArea();
}

int main()
{
	Rect r(1, 1, 10, 10);	// 상수 객체 아님.
	int n = r.getArea();	// ok
	foo(r);
}






