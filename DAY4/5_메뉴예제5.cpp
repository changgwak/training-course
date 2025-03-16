#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// C언어는 메모리 구조(포인터 등)을 이해하기 위해 메모리 그림을 그리며 공부.

// 객체지향 디자인을 이해하려면 클래스 구조(Diagram) 을 그려야 함.

class BaseMenu
{

	std::string title;

public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	virtual void command() = 0;	// 모든 자식에 공통적으로 command 가 있으므로 부모 클래스에 정의.
							// 순수 가상 함수로 만들어야 함.


	std::string get_title() const { return title; }

};


class MenuItem : public BaseMenu
{
	
	int id;


public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) { }

	
	// 메뉴 선택시 호출할 함수
	void command() override
	{
		std::cout << get_title() << "메뉴 선택됨\n";
		_getch(); // 아무키나 누를때 까지 잠시 정지
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;

public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	// 팝업 메뉴 선택시 호출할 함수
	void command() override
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


			v[cmd - 1]->command();	// 다형성. polymorphism
								// v[cmd - 1] 의 타입은 BaseMenu* 이지만
						//  v[cmd - 1] 이 가리키는 실제 객체가 MenuItem 인지 
						// PopupMenu 인지에 따라 다르게 동작	


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

	pm.add(&m8);
	pm.add(&m9);

	pm.command();	// 팝업 메뉴 선택
}
