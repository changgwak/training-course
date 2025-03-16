#include <iostream>
#include <string>
// 예외 전용 클래스

class file_not_found
{
public:
	std::string file_name;

	file_not_found(const std::string& s): file_name(s) {}

};

// 아무 멤버가 없는 클래스도 나쁘지 않음
// -> 클래스 이름 자체가 설명.
class network_error {};



int db_backup()
{
	if (1)
	{

		file_not_found e("a.txt");
		throw e;
	}
		
	if (2)
	{
		network_error e;
		throw e;

	}

	return 100;
}

void db_remove() { std::cout << "remove db\n"; }

int main()
{
	try
	{
		int ret = db_backup();

	}

	catch (const file_not_found& e)
	{
		std::cout << "Exception Occured\n";

	}

	catch (const network_error& e)
	{

	}

	catch (...)	// 모든 걸 다 받겠다.
	{
		std::cout << "위에서 잡지 않은 모든 예외는 여기서 처리\n";
	}

	db_remove();
}


