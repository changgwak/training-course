#include <iostream>

// 예외. 176 page ~

// 반환값으로 오류를 전달하는 방식의 단점
// 1. 반환값과 오류가 명확히 분리되지 않는다.
//    (-1 은 연산의 결과인가 ? 실패로 약속된 값인가 ?)

// 2. 호출자에게 반드시 오류를 처리하라고 강제로 지시할수 없다.

int db_backup()
{
	if (실패)
		return -1;

	return 100;
}

void db_remove() { std::cout << "remove db\n"; }

int main()
{
	int ret = db_backup();

	if (ret == -1) {}

	db_remove();
}


