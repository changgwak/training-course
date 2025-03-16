// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int>   s = { 1,2,3,4,5,6,7,8,9,10 };

	// 1. 반복자의 정확한 타입
	// but, C++ 이후라면 아래 처럼 하지 마세요.
	// 아래 처럼 하면 contatiner 교체시 코드 수정 필요.
	// std::list<int>::iterator p1 = s.begin(); 

	auto p1 = s.begin();	// contariner 바꿔도 코드 수정 불필요.
	
}

/*
namepace std
{
	class list_iterator
{

};

	template<typename T>
	class list
	{
	public:
		using iterator = list_iterator;
	};

}
*/
