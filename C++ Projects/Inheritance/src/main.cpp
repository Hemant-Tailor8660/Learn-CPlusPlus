// #include <iostream>


// class Base
// {
// 	int a,b;
// 	public:
// 	Base():a(10),b(20){}
// 	void funB()
// 	{
// 		std::cout<<" Base a,b:"<<a<<", "<<b;
// 	}
// 	void funMod(){
// 		a=600;
// 		b=700;
// 	}

// };

// class Child : public Base
// {
// 	int x,y;
// 	public:
// 	Child():x(100),y(200){}
// 	void funC()
// 	{
// 		Base::funMod();
// 		std::cout<<" Child x,y:"<<x<<", "<<y;
// 	}

// };
// int main(int argc, char *argv[])
// {
// 	Child c;
// 	Base b;
// 	c.funMod();
	
// 	b.funB();
// 	c.funB();
// 	//std::cout << "Hello world!" << std::endl;
// }


// #include <iostream>
// class A
// {

// 	public:
// 		A(){std::cout<<"A-Class\n";}
// 		~A(){std::cout<<"A-Dest\n";}	
// };


// class C
// {

// 	public:
// 		C(){std::cout<<"C-Class\n";}
// 		~C(){std::cout<<"C-Dest\n";}	
// };

// class B: public A , public C
// {

// 	public:
// 		B():C(),A()
// 		{std::cout<<"B-Class\n";}
// 		~B(){std::cout<<"B-Dest\n";}	
// };

// int main(){
// 	B b;
// }


// #include <iostream>
// #define VirtualBase
// class A
// {
// 	protected: int a;
// 	public:
// 		A():a(10){std::cout<<"A-Class const\n";}
// 		~A(){std::cout<<"A-Class Dest \n";}	
// };
// #if defined(VirtualBase)
// 	class B : virtual public A  
// 	{
// 		protected: int b;
// 		public:
// 			B():b(20){std::cout<<"B-Class Const\n";}
// 			~B(){std::cout<<"B-Class Dest\n";}	
// 	};
// #else 
// 	class B : public A
// 	{
// 		protected: int b;
// 		public:
// 			B():b(20){std::cout<<"B-Class Const\n";}
// 			~B(){std::cout<<"B-Class Dest\n";}	
// 	};
// #endif

// #if defined(VirtualBase)
// 	class C : virtual public A  
// 		{
// 		protected: int c;
// 		public:
// 		C():c(30){std::cout<<"C-Class Const\n";}
// 		~C(){std::cout<<"C-Class Dest\n";}

// 	};
// #else 
// 	class C : public A
// 	{
// 		protected: int c;
// 		public:
// 		C():c(30){std::cout<<"C-Class Const\n";}
// 		~C(){std::cout<<"C-Class Dest\n";}

// 	};
// #endif

// class D: public B,C
// {
// 	protected: int d;
// 	public:
// 	D():d(40){std::cout<<"D-Class Const\n";}
// 	~D(){std::cout<<"D-Class Dest\n";}
// 	void print()
// 	{
// 		std::cout<<"a: "<<a<<"\n";
// 		std::cout<<"b: "<<b<<"\n";
// 		std::cout<<"c: "<<c<<"\n";
// 		std::cout<<"d: "<<d<<"\n";
// 	}
// };

// int main()
// {
// 	D d;
// 	d.print();
// }


// #include <iostream>
// class A{
// 	public:
// 	void fun(int x ){std::cout<<"\nA's Function\n";}

// };
// // class C
// // {
// // 	public:
// // 		void fun(){ cout<<"\nC's fun\n";}
// // };
// class B:public A
// {
// 	//using A::fun;
// 	public:
// 	using A::fun;
// 	void fun(int x){std::cout<<"\n B's fun\n";}
// };

// int main(){
// 	B b;
// 	b.fun(9);
// }


#include <iostream>
class A{
	public:
	//void fun(int x ){std::cout<<"\nA's Function\n";}
	void fun(){std::cout<<"\n A's fun\n";}
};

class B
{
	//using A::fun;
	public:
	//using A::fun;
		//void fun(){std::cout<<"\n B's fun\n";}
		void fun(int x ){std::cout<<"\nB's Function\n";}
};

class C: public A, public B
{
	public:
	using A::fun;
	using B::fun; 
	
	void fun(){ std::cout<<"\nC's fun\n";}
};

int main(){
	C c;
	c.fun(6);
}