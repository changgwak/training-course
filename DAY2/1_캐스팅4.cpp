// const_cast 
// => 객체의 상수성 제거

int main()
{
	int n = 10;	// n 자체는 상수 아님. R/W 둘다 됨.

	// int* -> const int*는 위험하지 않음.
	// 아주 좋은 코드.
	// 원본은 R/W 이지만 p1을 통해서 R만 하겠다는 의도.
	// 따라서, 이 변환은 암시적 변환이 허용됨.
	const int* p1 = &n;	// 좋은 코드. p1을 통해서 Read 만 가능. 원본 n은 안 바뀜.

	// const int* -> int* 로 변환.
	// 위험한 캐스팅. 암시적 변환이 안됨. p1은 read만 되는데 다시 R/W가 되게 바꾸려는 것.
//	int* p2 = p1; // eror
	int* p3 = (int*)p1;	// ok. C 스타일 캐스팅은 대부분 성공.
	int* p4 = static_cast<int*>(p1); // error. 위험한 캐스팅. 허용 안됨.
	int* p5 = reinterpret_cast<int*>(p1); // error
										// -> 다른 타입 주소 캐스팅은 가능하지만 상수성 제거는 안됨.
										// -> 상수였던 놈을 다시 상수가 아니게는 안됨.

	int* p6 = const_cast<int*>(p1);	// ok
							// 동일 타입의 상수성 제거를 위한 캐스팅.

}

// 결론 C++ 언어에서 캐스팅이 필요하면 
// 1. 먼저 static_cast 사용.
// 2. 에러가 나오면 원인을 보고 아래 2개 중 하나로 변경.
//	-> reinterpret_cast, const_cast
//	-> 3개로 안 되면 C로도 캐스팅 불가한 경우.
// 3. dynamic_cast 라는 것은 상속을 배워야 이해 가능.

