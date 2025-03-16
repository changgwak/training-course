#pragma once
#include <iostream>
#include<cstring>

class Vector
{

public:
	Vector(int size, int value = 0);
	~Vector();

	int& at(int idx);
	int size();
	bool empty();
	void resize(int newsize);

private:
	int* ptr;
	int sz;
};

// 클래스 만들 때 보통 멤버 데이터를 아래 부분에 배치하는 경우가 많음.
// -> 사용자 입장에서는 함수가 중요하므로 함수를 먼저 보여주기 위함.


