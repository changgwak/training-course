// 5_반복자1
#include <iostream>
#include <vector>
#include <list>

int main()
{
//	std::list<int>   c = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };


//	auto p1 = c.begin(); 
//	auto p2 = c.end();
	// 역반복자 ( reverse iterator ) 꺼내기.
	auto p1 = c.rbegin(); // std::rbegin(s)
	auto p2 = c.rend();   // std::rend(s)

	while (p1 != p2)
	{
		std::cout << *p1 << ", ";
		++p1;
	}
	std::cout << std::endl;

}



