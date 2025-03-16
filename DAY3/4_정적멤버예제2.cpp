#include <iostream>


class Date
{

public:
	
	Date(int year, int month, int day)
		: year{ year }, month{ month }, day{ day } {}

	int get_day() const { return day; }
	void set_day(int d) { day = d; }	

	Date after_days(int ds)
	{
		Date tmp(year, month, day + ds);	// 잘못된 구현
											// 복습시 제대로 구현하기.

		return tmp;
	}




private:
	int year;
	int month;
	int day;

	// 아래 같은 데이터는
	// -> 날짜 관련 데이터 이지만
	// -> 특정 날짜 객체와 관련이 있는 것은 아닌
	// -> Date 라는 클래스와 관련있는 데이터.
	// -> 이런 데이터는 static 멤버로 하자.
	inline static int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

};

int Date::days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


int main()
{
	Date d(2025, 3, 12);

	Date d2 = d1.after_days(1000);	// 1000일 뒤의 날짜를 알고 싶다.

	// 5월이 몇 일까지 있는지 알고 싶다. - 복습시 구현하기.
	// -> 2번 방법이 좋음.
	// 방법 1.
	Date d3(2025, 5, 1);
	int n1 = d3.days_in_month(5);

	// 방법 2.
	int n2 = Date::days_in_month(5);

	// 내일 날짜를 알고 싶다.
	// -> 내일은 오늘이라는 기준 날짜 필요
	// -> non-static!
	Date today(2025, 3, 12);
	Date d4 = today.tomorrow();

	// 윤년인지 알고 싶다.
	// -> 아래 2가지 방법 모두 제공하는 것이 좋음.
	// 인자가 다르기 때문에 함수 이름이 같아도 문제 없음.
	// 방법 1.
	bool b1 = today.is_leap_year();

	// 방법2
	bool b2 = Date::is_leap_year(2025);

}

