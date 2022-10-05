// #include<iostream>
// #include<memory>
// using namespace std;
// class MyClass{
// public:
//     MyClass(){
//         std::cout << "Constructor invoked" << std::endl;
//     }
//     ~MyClass(){
//         std::cout << "Destructor invoked" << std::endl;
//     }
// };

// int main()
// {
// 	//std::shared_ptr<MyClass[]> sobj = std::make_shared<MyClass[5]>();  
// 	std::shared_ptr<int[]> iobj = std::make_shared<int[5]>();
// }

// // int main(){
// // 	std::unique_ptr<MyClass> obj(new MyClass());
// // 	return 0;
// // }

#if 1
#include<iostream>
#include<memory>
using namespace std;
class MyClass{
public:
    MyClass(){
        std::cout << "Constructor invoked" << std::endl;
    }
    ~MyClass(){
        std::cout << "Destructor invoked" << std::endl;
    }
};

int main()
{

	// std::shared_ptr<MyClass[]> obj = std::make_shared<MyClass[]>(new MyClass[10]);
	// // std::shared_ptr<MyClass[]> sobj = std::make_shared<MyClass[5]>();
	// // auto ssobj = std::make_shared<MyClass[]>(5);
	// //std::shared_ptr<int[]> iobj = std::make_shared<int[]>(5);
	// //iobj.get()[0] = 5;
	// // std::cout<<iobj.get()[0]<<"    , "<<iobj.get()[1]<<std::endl;
	
	
	
	// // std::unique_ptr<int[]> ip = std::make_unique<int[]>(5);
	// // std::cout<<ip.get()[1];

	std::shared_ptr<MyClass> sp1 = std::make_shared<MyClass>();
	//auto sp2 = sp1;
	sp1.reset();
	std::cout<<std::boolalpha<<(sp1.get() == nullptr);
}

#endif

#if 0
#include<iostream>
#include<memory>
using namespace std;
class MyClass{
public:
    // MyClass(int x){
    //     std::cout << "Parameterized Constructor invoked" << std::endl;
    // }
    MyClass(){
        std::cout << "Constructor invoked" << std::endl;
    }
    ~MyClass(){
        std::cout << "Destructor invoked" << std::endl;
    }
};

template<typename T>
struct array_deleter
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

void deleter(int* ptr)
{
	std::cout<<"\nOur deleter\n";
	delete[] ptr;
}
int main()
{

	std::shared_ptr<MyClass> sharedObject (new MyClass[10], std::default_delete<MyClass[]>());
	std::shared_ptr<int> intObj (new int[10], deleter /*array_deleter<int>()*/ /*std::default_delete<int[]>()*/);
// 	std::unique_ptr<int[]> ip = std::make_unique<int[]>(5);
// 	std::cout<<ip.get()[1];
}
#endif

// #include <memory>
// #include <vector>
// #include <iostream>
// #include <type_traits>
 
// struct C
// {
//     // constructors needed (until C++20)
//     C(int i) : i(i) {}
//     C(int i, float f) : i(i), f(f) {}
//     int i;
//     float f{};
// };
 
// int main()
// {
//     // using `auto` for the type of `sp1`
//     auto sp1 = std::make_shared<C>(1); // overload (1)
//     static_assert(std::is_same_v<decltype(sp1), std::shared_ptr<C>>);
//     std::cout << "sp1->{ i:" << sp1->i << ", f:" << sp1->f << " }\n";
 
//     // being explicit with the type of `sp2`
//     std::shared_ptr<C> sp2 = std::make_shared<C>(2, 3.0f); // overload (1)
//     static_assert(std::is_same_v<decltype(sp2), std::shared_ptr<C>>);
//     static_assert(std::is_same_v<decltype(sp1), decltype(sp2)>);
//     std::cout << "sp2->{ i:" << sp2->i << ", f:" << sp2->f << " }\n";
 
//     // shared_ptr to a value-initialized float[64]; overload (2):
//     std::shared_ptr<float[]> sp3 = std::make_shared<float[]>(64);
 
//     // shared_ptr to a value-initialized long[5][3][4]; overload (2):
//     std::shared_ptr<long[][3][4]> sp4 = std::make_shared<long[][3][4]>(5);
 
//     // shared_ptr to a value-initialized short[128]; overload (3):
//     std::shared_ptr<short[128]> sp5 = std::make_shared<short[128]>();
 
//     // shared_ptr to a value-initialized int[7][6][5]; overload (3):
//     std::shared_ptr<int[7][6][5]> sp6 = std::make_shared<int[7][6][5]>();
 
//     // shared_ptr to a double[256], where each element is 2.0; overload (4):
//     std::shared_ptr<double[]> sp7 = std::make_shared<double[]>(256, 2.0);
 
//     // shared_ptr to a double[7][2], where each double[2] element is {3.0, 4.0}; overload (4):
//     std::shared_ptr<double[][2]> sp8 = std::make_shared<double[][2]>(7, {3.0, 4.0});
 
//     // shared_ptr to a vector<int>[4], where each vector has contents {5, 6}; overload (4):
//     std::shared_ptr<std::vector<int>[]> sp9 = std::make_shared<std::vector<int>[]>(4, {5, 6});
 
//     // shared_ptr to a float[512], where each element is 1.0; overload (5):
//     std::shared_ptr<float[512]> spA = std::make_shared<float[512]>(1.0);
 
//     // shared_ptr to a double[6][2], where each double[2] element is {1.0, 2.0}; overload (5):
//     std::shared_ptr<double[6][2]> spB = std::make_shared<double[6][2]>({1.0, 2.0});
 
//     // shared_ptr to a vector<int>[4], where each vector has contents {5, 6}; overload (5):
//     std::shared_ptr<std::vector<int>[4]> spC = std::make_shared<std::vector<int>[4]>({5, 6});
// }