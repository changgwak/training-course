// 1_레퍼런스3. 63 page
struct Data
{
	int buff[1024];	//4k 크기
};

// call by value : 복사본 생성.
//					원본을 변경하지 않을 것이라는 약속의 의미도 있음.
//					함수가 완벽히 분리 되므로 안전.
void foo(int n)
{
}

// 크기가 큰 타입을 인자로 받을 때는 
// call by value 가 아닌 const reference 로 하는 것이 좋음.

// Data& : 복사본을 만들지 않겠다는 것(메모리 오버헤드 제거)
// const : 변경하지 않겠다는 약속 (안정성 향상)

// Q) 크기가 작은것도 레퍼런스로 하는게 좋은거 아닌가? 아님.

// void goo(Data data) // Data 의 크기가 크기 때문에 복사본의 오버헤드가 있음.
void goo(const Data& data)
{
	data.buff[0] = 10;	//error. const 이므로 원본 못 바꿈.
}

int main()
{
	int x = 100;

	// foo 는 전달된 인자의 x 를 절대 변경하면 안된다.
	foo(x);


}


