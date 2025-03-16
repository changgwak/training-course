#include <iostream>

// 던져진 예외 잡기 : try ~ catch
// 시험, exam
// 다음 예외를 던지는 것은? throw


int db_backup()
{
	if (1)		// 함수가 실패하면
		throw 1; // 에외 던지기

	return 100;
}

void db_remove() { std::cout << "remove db\n"; }

int main()
{
	try 
	{
		int ret = db_backup();

	}
		
	catch (int e)
	{
		std::cout << "Exception Occured\n";

		// 예외의 원인을 해결할 수 없다면 여기서
		// 사용자에세 알리고 종료 해야 함.
		std::exit(-1);

		// 종료 하지 않으면 프로그램은 계속 실행 됨.
	}

	db_remove();
}


