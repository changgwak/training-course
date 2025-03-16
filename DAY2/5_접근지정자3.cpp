
#include <iostream>
#include <string>

// C++ 스타일 
// 시험, exam
class Person	
{
private:			
		// 멤버 데이터
	std::string name;	
	int  age;

public:				
	void set_age(int a)
	{
		if (a > 0 && a < 150)
			age = a;
	}

private:

public:

};



// C#, Java, Swift 등의 C++을 제외한 대부분의 언어
// => 멤버 마다 접근지정자 표기
class Person
{
	private std::string name;
	private int  age;

	public void set_age(int a)
	{
		if (a > 0 && a < 150)
			age = a;
	}
};


