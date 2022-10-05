#include <iostream>


class A
{

	public: 
	~A(){}
	//virtual ~A(){}
};

class B : public A
{


};
int main(int argc, char *argv[])
{
	A a;
	B b;
	A* pa=&b;
	std::cout<<typeid(pa).name();
	//std::cout << "Hello world!" << std::endl;
}