// 1_레퍼런스.cpp    57 page

#include <iostream>

int main()
{
	int n1 = 10;

	int& r1 = n1;

	r1 = 30;

	std::cout << n1  << std::endl; // ?
	
	std::cout << &r1 << std::endl;
	std::cout << &n1 << std::endl;

}





