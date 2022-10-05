#include <iostream>
template <typename T>
T data = T(5);

// variadic template
void print()
{
	std::cout<<"\nBase Case\n";
}
template<typename T, typename... Args>
void print(T x, Args... args)
{
	std::cout<<x<<" ";
	print(args...);
}
int main()
{
	print("Hem", 1, 3.50, 'a');
    
	std::cout<< data<double>;
	//std::cout << "Hello world!" << std::endl;
}