// 3_OOP1 - 72page
#include <iostream>

// 사각형의 면적을 구하고, 사각형을 그리는 함수를 생각해 보자.

int getRectArea(int left, int top, int right, int bottom)
{
	return (right - left) * (bottom - top);
}

void drawRect(int left, int top, int right, int bottom)
{
	std::cout << "draw rect" << std::endl;
}

int main()
{
	int n1 = getRectArea(1, 1, 10, 10);
	drawRect(1, 1, 10, 10);
}

