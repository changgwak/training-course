#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
// 프로그램에서 필요한 타입을 먼저 설계 한다.

class MenuItem
{
	std::string title;
	int id;
	

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
	std::vector<MenuItem*> v;   // MenuItem 객체를 여러 개 보관 가능.(vector)

public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// 팝업 메뉴 선택시 호출할 함수
	void command()
	{
		while (1)
		{
			system("cls");	// 화면 지우기

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
			{
				std::cout << "잘못된 입력 " << std::endl;
				continue;
			}


			v[cmd - 1]->command();		


		}



	}

};

int main()
{
	MenuItem m1("참치 김밥", 11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m3("돈까스 김밥", 13);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);
	kimbab.add(&m3);
	// --------------------------------------------------
	MenuItem m8("라면", 21);
	MenuItem m9("우동", 22);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&kimbab);		// <- error. 
							// MenuItem* 가 필요한데 PopupMenu* 가 들어감.
							// 해결은 다음 소스.
	pm.add(&m8);
	pm.add(&m9);

	pm.command();	// 팝업 메뉴 선택
}
