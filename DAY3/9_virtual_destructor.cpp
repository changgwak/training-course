// virtual destructor - 148 page
#include <iostream>

class Base
{
public:
	Base() {}
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
	Derived* p = new Derived;
	delete p;
}


