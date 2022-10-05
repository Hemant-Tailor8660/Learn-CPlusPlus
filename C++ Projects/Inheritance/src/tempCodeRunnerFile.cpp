#include <iostream>
class A{
	public:
	void fun(int x ){std::cout<<"\nA's Function\n";}

};
class C
{
	public:
		void fun(){ cout<<"\nC's fun\n";}
};
class B:public A
{
	//using A::fun;
	public:
	using A::fun;
		void fun(){std::cout<<"\n B's fun\n";}
};

int main(){
	B b;
	b.fun(9);
}