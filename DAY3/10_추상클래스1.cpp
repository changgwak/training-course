// 추상클래스 - 156page

class Shape
{
public:
	virtual void Draw()  = 0;
};
class Rect : public Shape
{
public:
};
int main()
{
	Shape s; // ?
	Rect  r; // ?
}





