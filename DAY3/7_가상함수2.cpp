// 145 page ~
class Shape
{
public:
	virtual void draw() {};
	virtual void clone() const {};
	virtual void move() {};
};
class Rect : public Shape
{
public:
	virtual void Draw()  {};
	virtual void clone() {};
	virtual void move(int n) {};
};
int main()
{

}



