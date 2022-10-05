#include <iostream>
#include <tuple>
#include<string>

int main(int argc, char *argv[])
{
	std::tuple<int, char, std::string> obj1;
	obj1 = std::make_tuple(30, 'm', "hemant");
	int age;
	char gender;
	std::string name;

	std::tie(age, gender, name) = obj1;//auto& [age, gender, name] = obj1;
	size_t size = std::tuple_size<decltype(obj1)>::value;
	std::cout<<"Tuple args size: "<<size<<", "<<"Age: "<<age<<", "<<"Gender: "<<gender<<", "<<"Name: "<<name<<'\n';
	// t1.swap(t2);
	// auto t3 = tuple_cat(t1,t2);
}