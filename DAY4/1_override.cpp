// override  145 page ~

class Shape
{
public:
	virtual void draw() {};
};
class Rect : public Shape
{
public:
	// 가상함수를 override 할 때는 virtual 표시 않해도 됨.
	// -> but, virtual 키워드를 붙이는 것이 보기 좋음.

//	virtual void draw()  {};
//  void draw() {};

	// 2. 가상함수 override 시 실수(오타)가 있어도
	// -> 에러가 발생하지 않음.
	// -> 컴파일러는 새로운 가상함수를 만드는 것으로 간주함.
//	void draw() override {};

	// 3. 2번의 경우 많은 버그 발생의 원인.
	// C++11에서 override 키워드를 사용하면, 실수(오타)를 잡아줌.
	// -> override 키워드를 사용하면, 부모 클래스에 해당 함수가 있는지 검사함.(새로운 함수 말고 기존 함수 확인)
//	virtual void Draw() override {};	// error. 함수 이름이 다름.
	virtual void draw() override {};	// ok
	void draw() override {};	// ok


};
int main()
{

}


