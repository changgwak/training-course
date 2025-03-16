// 4_STL_컨테이너1.cpp
#include <iostream>
#include <vector>

// 185 ~

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	v.resize(3);	// 어떻게 구현 했을까요?


	std::cout << v.size() << ", " << v.capacity() << std::endl; 
	// 결과: 3 , 5 -> 이미 할당된 메모리는 안 줄임.

	v.push_back(0); // 끝에 한 개 추가.
					// 현재 size < capacity 상태이므로
					// 이 함수는 아주 빠르게 동작합니다.
					// not expensive

	std::cout << v.size() << ", " << v.capacity() << std::endl; 
	// 결과: 4, 5 -> 처음 할당된 메모리는 그대로.

	v.shrink_to_fit();  // 여분의 메모리는 제거해 달라.
					// 실제 구현은 4개 메모리 새로 할당해서 사용.
					// 기존 5개 메모리는 제거.

			
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	// 결과: 4, 4

	v.push_back(0);	// size == capacity 이므로 메모리 재할당 필요.
					// 이 경우는 expensive 한 함수.


	std::cout << v.size() << ", " << v.capacity() << std::endl;
	// 결과: 4, 6 -> capacity : g++은 2배, vs 는 1.5 배

	v.clear();	// 실제 메모리를 제거할까요? size만 0 일까요?

	std::cout << v.size() << ", " << v.capacity() << std::endl;
	// 결과: 0, 6 -> capacity의 메모리가 그대로 남아있음.

	v.shrink_to_fit();	// 이 순간 필요없는 메모리 제거.
						// 현재 sieze == 0 이므로
						// 버퍼를 완전히 제거.
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	// 결과: 0, 0 

	// 위 예제를 통해 capacity 라는 개념 알아 두세요.
	// python list도 동일함.
	// 대부분 언어에 있는 개념.



	// 스택은 중간에 메모리 지울 수 없음.
	/*
	void foo()
	{
		int a;
		int b;
	} // <-- b 파괴 먼저 이후 a 파괴
	// 지역 변수는 스택에 쌓이므로 나중에 들어온 놈이 먼저 파괴.

	
	*/
}


