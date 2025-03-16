#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
// 프로그램에서 필요한 타입을 먼저 설계 한다.

class MenuItem
{
	std::string title;
	int id;
	//	std::string shortcut; // 나중에 복습할때 추가해 보세요

public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) { }

	std::string get_title() const { return title; }


	// 메뉴 선택시 호출할 함수
	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";
		_getch(); // 아무키나 누를때 까지 잠시 정지
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;

public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// 팝업 메뉴 선택시 호출할 함수
	void command()
	{
		auto sz = v.size();

		for (int i = 0; i < sz; i++)
		{
			std::cout << i+1 << ". " << v[i]->get_title() << std::endl;
		}
		std::cout << sz + 1 << ". 종료\n";

		std::cout << "메뉴를 선택하세요 >> ";

		int cmd;
		std::cin >> cmd;

		v[cmd - 1]->command();		// 선택한 메뉴 실행

	}

};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);
	MenuItem m3("우동", 13);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&m1);
	pm.add(&m2);
	pm.add(&m3);

	pm.command();	// 팝업 메뉴 선택
}


