#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	std::string s = "ABCD";

	do
	{

		std::cout << s << std::endl;
	} while (std::next_permutation(s.begin(), s.end()));

	// permutation : 순열 구하기.

}
