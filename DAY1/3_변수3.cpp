#include <iostream>

struct Point
{
	int x, y;
};
void foo(int n)    {} 
void goo(Point pt) {}

int main()
{
	Point p = { 1,2 };

	foo(3);	// int n = 3
	foo({3}); // int n = {3}
	
	goo({1,2}); // Point pt = {1,2}

	// goo(p);	
}
// 아래와 같이도 가능.
Point hoo() {
	return {1,2};

	// Point p = {1,2};
	// return p;
	//위 와 동일한 기계어.
}







