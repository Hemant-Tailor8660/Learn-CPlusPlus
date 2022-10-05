#include <iostream>
class A{
	protected: int x;
	public:
		virtual void fun()=0;
		A(int i):x(i){}
		A(){}
		int getX(){return x;}
};

class B: public A{
	int y;
	public:
		virtual void fun(){
			std::cout<<"\nX: \n"<<x<<"\nY:\n"<<y<<std::endl;
		};
		B(int i, int j):A(i), y(j){}
		B(){}

};

int main(int argc, char *argv[])
{
	A* a=new B(10,20);
	a->fun();
}