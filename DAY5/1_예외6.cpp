#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v(4, 0);

	// [] 연산자: 인덱스가 잘못 되었는지 확인안함. 잘못 전달하면 비정상 종료됨. 
	// at() 함수 : 인덱스가 잘못되면 예외 발생.
//	v[10] = 10;				// ptr[idx] = value;
//	v.at(10) = 10;			// if (idx > sz) throw std::out_of_range

	try
	{
		//v.at(10) = 10;
		v[10] = 10;
	}
				
	catch (const std::out_of_range& e)
	{
		std::cout << "예외 발생\n";

	}

	for (int i = 0; i < v.size(); i++)
	{
		// 다음 중 좋은 코드는 ?
		// index 가 잘못 될 확률이 없음
		// --> 1번 사용
		v[i] = 0;		// 1
		v.at(i) = 0;	// 2

	}
}
