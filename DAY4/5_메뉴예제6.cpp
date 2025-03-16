#include <iostream>
#include <string>
#include <vector>
#include <conio.h>



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



		}



	}

};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add(new MenuItem("RED", 11));
	pm1->add(new MenuItem("GREEN", 12));
	pm1->add(new MenuItem("BLUE", 13));
	pm1->add(new MenuItem("WHITE", 14));

	pm2->add(new MenuItem("HD", 21));
	pm2->add(new MenuItem("FHD", 22));
	pm2->add(new MenuItem("UHD", 23));


	root->command();	// 메뉴 선택 시작

}

// 현실세계에서 세상은 다양한 객체(사람, 자동차, 컴퓨터, 기차등...)의 집합 입니다.

// 객체 지향 프로그래밍 관점에서 프로그래밍 이란 ?
// 1. 객체를 생성하고
// 2. 객체간의 관계를 설정하고
// 3. 객체간의 메세지를 주고 받는 과정이다 (서로의 멤버 함수 호출)

// 4. 프로그램의 기본 단위는 "함수"가 아니라 "클래스"이다.

// 장점: 유연성이 좋고, 유지보수가 쉽다

// 단점: 메모리 사용량이 C 보다 많고 복잡.
//			어렵다.


// C++
// C++

// level 1 : auto, template, reference 등을 이해 해서 사용할수 있는 능력
//			=> 1일차 배운 기술

// level 2 : std::string, std::vector 등의 미리 만들어진 표준 라이브러리를
//			사용하는 능력

// level 3 : 3일차 배운 "Date" 같은 클래스를 혼자 만들수 있는 능력
//			=> 클래스 문법의 이해

// level 4 : 위의 Menu 같은 라이브러리를 설계 할수 있는 능력
//			=> 단순 문법이 아닌, 객체지향 설계에 대한 학습이 필요
//			=> "디자인 패턴" 같은 과정 참고!!

// .... 그위에도 많은 이야기들이 있습니다.
// C++언어 진영의 고유 디자인 : C++ IDIoms
// 고급문법 : move, concept, template... 
// STL 라이브러리 자체의 설계
