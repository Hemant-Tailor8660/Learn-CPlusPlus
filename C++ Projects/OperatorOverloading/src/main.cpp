// #include <iostream>

// int main(int argc, char *argv[])
// {
// 	int* p = new int[5];//{};//();//{0};
// 	for(int i=0; i<5;++i)
// 	{
// 		std::cout<<" "<<p[i];
// 	}
// 	std::cout << "\nHello world!" << std::endl;
// }


// CPP program to demonstrate
// Overloading new and delete operator
// for a specific class
#include<iostream>
#include<cstdlib>

using namespace std;
class student
{
	string name;
	int age;
public:
	student()
	{
		cout<< "Constructor is called\n" ;
	}
	student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void display()
	{
		cout<< "Name:" << name << endl;
		cout<< "Age:" << age << endl;
	}
	void * operator new(size_t size)
	{
		cout<< "Overloading new operator with size: " << size << endl;
		//void * p = ::operator new(size);
		//void * p = malloc(size); will also work fine
		void* p=new student("hem",23);
		return p;
	}

	void operator delete(void * p)
	{
		cout<< "Overloading delete operator " << endl;
		free(p);
	}
};

int main()
{
	student * p = new student("Yash", 24);

	p->display();
	delete p;
}
