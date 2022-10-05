// #include <iostream>

// using std::cout;

// template <typename T>
// void PrintArray(T& a) {
//     const size_t rows = sizeof(a) / sizeof(a[0]);
//     const size_t cols = sizeof(a[0]) / sizeof(a[0][0]);
//     cout << "Array has " << rows << " rows and " << cols << " columns.\n\n";
//     for (size_t i = 0; i < rows; i++) {
//         for (size_t j = 0; j < cols; j++) {
//             cout << a[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

// int main()
// {
//     size_t a[5][8]={{}}; // you can change the type and size of the 2D array
//     PrintArray(a);
//     return 0;
// }


// 

// #include<iostream>
// #include <cstring>
// #include <climits>
// int	main(int argc, char **argv)
// {	
// 	char str[] = "Hemant";
// 	//int i,j=strlen(str)-1;
// 	for(int i=0,j=strlen(str)-1; i<j ; ++i,--j)
// 	{
// 		//std::swap(str[i], str[j]);
// 		str[i] = str[i]+str[j] - (str[j]=str[i]);
// 	}
// 	//str[strlen(str)+1]=NULL;
// 	std::cout<<str<<std::endl;


// 	//system("pause");
// 	return 0;
// }

// #include<iostream>
// #include<sstream>
// #include<string>
// #include<vector>
// #include<algorithm>
// int main(){
// 	std::string str = "Hemant is a good boy.";
// 	std::stringstream obj(str);
// 	std::string tok;
// 	std::vector<std::string> tokens;
// 	while(std::getline(obj , tok,' '))
// 	{
// 		tokens.push_back(tok);

// 	}
// 	std::sort(tokens.begin(), tokens.end());

// 	for(auto x : tokens)
// 	{
// 		std::cout<<x<<std::endl;
// 	}

// }


//#include <cctype>
// #include <iostream>
// using namespace std;

// int main() {
//  	unsigned char c1 = 'A', c2 = 'b', c3 = '9';

// 	cout << (char) tolower(c1) << endl;
// 	cout << (char) tolower(c2) << endl;
// 	cout << (char) tolower(c3);

// 	return 0;
// }

// namespace work
// {
// 	class my
// 	{
// 			public:
// 			static int x;
// 			my()=default;
// 			~my()=default;
// 	};
// 	int my::x =0;
// } // namespace work

// int main(){

// 	work::my::x =10;

// }



// #include <typeinfo>
// #include <iostream>

// using namespace std;

// class A {
// public:
//     virtual ~A() = default; // We're not polymorphic unless we
//                             // have a virtual function.
// };
// class B : public A { } ;
// class C : public A { } ;

// int
// main(int argc, char* argv[])
// {
//     B b;
//     A& a = b;
// 	int k =10;
// 	cout << "a is B: " << boolalpha << (typeid(k) == typeid(float)) << endl;
//     cout << "a is B: " << boolalpha << (typeid(a) == typeid(B)) << endl;
//     cout << "a is C: " << boolalpha << (typeid(a) == typeid(C)) << endl;
//     cout << "b is B: " << boolalpha << (typeid(b) == typeid(B)) << endl;
//     cout << "b is A: " << boolalpha << (typeid(b) == typeid(A)) << endl;
//     cout << "b is C: " << boolalpha << (typeid(b) == typeid(C)) << endl;
// }


#include<iostream>
#include<cxxabi.h>
#include<cstring>
using namespace std;

class Vehicles
{
    public:
    string make;
    string model;
    string year;
};

class Aircraft
{
    public:
    string make;
    string model;
    string year;
};

int main()
{
    int x;
    float y;
    bool b;

    Vehicles car;
    Aircraft helicopter;
	// //char* i = abi::__cxa_demangle(typeid(x).name(), nullptr, nullptr, nullptr);
    // cout << "The type of the variable x " << " is " << strcmp(abi::__cxa_demangle(typeid(x).name(), nullptr, nullptr, nullptr), i)  << endl;
    // cout << "The type of the variable y " << " is " << abi::__cxa_demangle(typeid(y).name(), nullptr, nullptr, nullptr)  << endl;
    // cout << "The type of the variable b " << " is " << abi::__cxa_demangle(typeid(b).name(), nullptr, nullptr, nullptr)  << endl;
    // cout << "The type of the object car " << " is " << abi::__cxa_demangle(typeid(car).name(), nullptr, nullptr, nullptr) << endl;
    // cout << "The type of the object helicopter " << " is " << abi::__cxa_demangle(typeid(helicopter).name(), nullptr, nullptr, nullptr)  << endl;
	std::cout<<std::boolalpha <<(typeid(x) == typeid(int)); 
}