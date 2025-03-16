class network_error {};


void f3()
{
	network_error e;
	throw e;	// 대부분의 컴파일러는 e 객체의 복사본을 힙에 생성.
}

void f2()
{
	f3();
}

void f1()
{
	f2();

}

int main()
{
	try
	{
		f1();
	}
	catch (const network& e)
	{
		// catch 끝에서 힙에 있는 던져진 객체 e 를 delete 하는 코드가 추가됨.
		// -> 약간의 오버헤드 있음.
		// -> critical 한 error 만 throw 예외처리하고 다른 간단한건 return 으로 처리.
	}
}


// Python, C#, Java : 예외처리 많이 사용

// C++ 관례
// 간단한 오류 처리: 함수 반환값(return) 으로 처리
// 심각한 오류(처리하지 않으면 종료되는게 좋은 경우) : 예외 사용

// 많은 임베디드 개발에서 예외 사용 안함.
