// protected.   135 page ~



class Base
{
private:   int a;	// 자신의 멤버 함수만 접근 가능,
protected: int b;	// 자신과 파생 클래스의 멤버함수만 접근 가능. 
					// 상속 쓸때만 의미 있음. 잘 안 쓰긴 함.
public:    int c;	// 어디서도 접근 가능.

	  void set_a(int v)
	  {
		  if (v > 0 && v < 10)
			  a = v;
	  }

};
class Derived : public Base  
{
public:
	void foo()
	{
		a = 0;	// error. 기반 클래스의 private 멤버는 파생 클래스 라도 접근 불가.
				// 변경하려면 이반 클래스 함수 사용 set_a(0) et al.
		b = 0;  // ok
		c = 0;  // ok
	}
};
int main()
{
	Base base;
	base.a = 0; // error
	base.b = 0; // error. protected는 외부 접근 안됨.
	base.c = 0; // ok
}



