// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// #include<array>
// #include<set>
// #include <list>
// namespace stl
// {
// 	class VecEx
// 	{
// 	private:
// 	public:
// 		VecEx();
// 		~VecEx();
// 	};
	
// 	VecEx::VecEx()
// 	{
// 	}
	
// 	VecEx::~VecEx()
// 	{
// 	}
// 	template<typename T>
// 	void Print(T x)
// 	{
// 		auto itr = x.begin();
// 		while(itr!=x.end())
// 		{

// 			std::cout<<*itr<<" ";
// 		}
// 		std::cout<<"\n";
// 	}
// } // namespace stl
// template<typename T>
// void Print(T& x)
// {
// 	auto itr = x.begin();
// 	while(itr != x.end())
// 	{

// 		std::cout<<*itr<<" ";
// 		++itr;
// 	}
// 	std::cout<<"\n";
// }

// int main(int argc, char *argv[])
// {
// 	std::cout<<std::endl<<std::endl;

// 	int c_arr[] = {1,2,3,4,5};
// 	std::array<int, 5> arr{1,2,3,4,5};
// 	std::vector<int> v;
// 	//v.push_pack(1);
// 	std::cout<<"\nEmptyVector(Capacity):"<<v.capacity()<<", "<<"Size: "<<v.size()<<std::endl;
// 	std::vector<int> obj(std::begin(c_arr), std::end(c_arr));
// 	//obj(c_arr, c_arr+sizeof(c_arr)/sizeof(c_arr[0]));
// 	//obj(std::begin(arr), std::end(arr)); 
// 	Print(obj);
	
// 	//std::cout << "Hello world!" << std::endl;



// 	// std::list<int> l1({1,2,3,4,5,3,1,6,8});
// 	// Print(l1);
// 	// l1.remove(3);
// 	// l1.remove(9);
// 	// Print(l1);
// 	std::list<int> l1({1,5,2,6,8,7});
// 	std::list<int> l2{3,2};
// 	//l1.merge(l2);
// 	Print(l1); Print(l2);
// 	l1.sort();Print(l1);
// 	//std::sort(l1.begin(), l1.end());Print(l1); //not applicable to the list
// 	 std::vector<int> v1 = {1,5,2,4,3};
// 	// std::sort(v1.begin(), v1.end());Print(v1);
// 	v1.resize(2);
// 	std::cout<<"v1.size(): "<< v1.size()<<", v1.capacity(): "<<v1.capacity()<<"\n"; Print(v1);
	
// }


//Algorithms


// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// void printArr(int* arr, size_t size)
// {

// 	for(int i=0; i< size; ++i)
// 	{

// 		std::cout<<arr[i]<<" ";
// 	}
// 	std::cout<<"\n";
// }
// bool compare_string_by_length (string i,string j)
// {
//     return (i.size() == j.size());
// }
// int main()
// {
//     int a[] = {9,8,7,6,5,4,3,2,1};
    
//     partial_sort(a, a+4, a+9); 
//     /* now a is 1,2,3,4,9,8,7,6,5  */ 
    
//     int b[] = {1,5,6,2,4,8,9,3,7};
    
//     /* sorts b such that first 4 elements are the greatest elements
//     in the array and are in descending order */
//     //partial_sort(b, b+4, b+9);
	
// 	//printArr(b, 9);
//     /* now b is  9,8,7,6,1,2,4,3,5 */
// 	std::sort(std::begin(b), std::end(b));
// 	std::cout<<std::binary_search(b, b+9, 10);
// 	std::string s[] = { "test" , "abcdf" , "efghijkl" , "pop" };
    
//     cout<<"\n"<<binary_search(s, s+4, "nicktfffffhhhhh" , compare_string_by_length);
// }

#if 0
// C++ program to demonstrate the use of std::equal_range
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<list>
using namespace std;
#include <numeric>
#include <array>
template<typename T>
void Print(T& x)
{
	auto itr = x.begin();
	while(itr != x.end())
	{

		std::cout<<*itr<<" ";
		++itr;
	}
	std::cout<<"\n";
}


// Defining the BinaryFunction
bool comp(int a, int b)
{
    return (a < b);
}


int pred(int& a)
{
	return a+2;
}

int binaryop(int&a , int&b)
{

	return a+b;
}
int main()
{
	vector<int> v = { 10, 10, 30, 30, 30, 100, 10,
					300, 300, 70, 70, 80 };

	// Declaring an iterator to store the
	// return value of std::equal_range
	std::pair<std::vector<int>::iterator,
			std::vector<int>::iterator> ip;

	// Sorting the vector v
	sort(v.begin(), v.end());
	// v becomes 10 10 10 30 30 30 70 70 80 100 300 300
	Print(v);
	// Using std::equal_range and comparing the elements
	// with 30
	ip = std::equal_range(v.begin(), v.begin() + 12, 30);

	// Displaying the subrange bounds
	std::cout << "30 is present in the sorted vector from index "<<*(ip.first)<<", "<<*(ip.second)<<std::endl
		 << (ip.first - v.begin()) << " till "
		 << (ip.second - v.begin())<<std::endl;
	Print(v);

	ip = std::equal_range(v.begin(), v.begin() + 12, 10, comp);
	 /// Displaying the subrange bounds
	std::cout << "10 is present in the sorted vector "<<*(ip.first)<<", "<<*(ip.second)<<std::endl
		 << (ip.first - v.begin()) << " till "
		 << (ip.second - v.begin())<<std::endl;
	Print(v);
	std::vector<int> vec = {1,5,3,4,8,2};
	std::sort(std::begin(vec), std::end(vec));
	//cout<<*(std::upper_bound(vec.begin(), vec.end(), 6));
	
	
	std::string str1 = "Hemant Tailor";
	std::string str2 = "Tailor";
	auto itr = std::search(std::begin(str1), std::end(str1), std::begin(str2), std::end(str2));
	while(itr!=str1.end())
		{
			std::cout<<*itr; ++itr;
		}
	std::vector<int> ob1{1,2,3,4,5,6};
	std::vector<int> ob2{4,5,6};
	std::cout<<std::equal(std::begin(ob1)+3, std::end(ob1), std::begin(ob2));


	std::vector<int>ob_1 = {1,2,3,4} , ob_2={8,9};
	ob_2.resize(10);
	std::copy(ob_1.begin(), ob_1.end(), ob_2.begin()+1);
	
	std::cout<<"\n";Print(ob_2);
	std::vector<int> a= {1,2,3,4};
	std::vector<int> b= {5,6,7};
	std::vector<int> res(a.size());
	//auto it = res.begin();
	std::transform(a.begin(), a.end()-1, b.begin(), res.begin(), binaryop);
	Print(res);
	std::cout<<"\n";
	a={10,20,30,40};
	std::iota(a.begin(),a.end(),100);
	Print(a);
	//std::initializer_list l ={1,5,3,2,10}; 
	std::minmax({1,2,3,8,100});
	return 0;
}
#endif 



#if 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<list>
using namespace std;
#include <numeric>
#include <array>
#include<memory>
class A
{
	public:
		A(){std::cout<<"\nA's Constructor\n";}
		~A(){std::cout<<"\nA's Destructor\n";}
		void print(){std::cout<<"\nA's print\n";}
};
template<typename T>
struct vector_deleter
{
	void operator()(T * p)
	{
		delete p;
		p = nullptr;
	}
};

void deleter(const A* p)
{
	delete p; 
	//p=nullptr;
}

int main()
{
	std::vector<A*> vec = {new A(), new A(), new A(), new A()};
	//vec.erase(vec.begin(), vec.end());
	// vec.erase(vec.begin(), vec.end());
	//std::for_each(vec.begin(), vec.end(), /*std::default_delete<A>()*/ deleter /*vector_deleter<A>()*/);
	size_t i =0;
	// for(auto itr = vec.begin(); itr!=vec.end();++itr)
	// {
		
	// 	delete *itr;///vec[i];
	// 	//vec[i++]=nullptr;
	// 	*itr =nullptr;
	// 	//vec.erase(itr);
	// 	//itr--;
	// }
	//vec.erase(std::remove(vec.begin(), vec.end(), nullptr),vec.end());
	//std::erase(vec.begin(), vec.end());
	
	for(int i=0; i<vec.size();++i)
	{
		delete vec[i];
		vec[i]=nullptr;

	}
	vec.erase(std::remove(vec.begin(), vec.end(), nullptr), vec.end());

	//vec.clear();
	//vec.shrink_to_fit();
	if(vec[0]!=nullptr)
		vec[0]->print();
	std::cout<<vec.size()<<'\n'<<vec.capacity()<<'\n';
	
				#if 0
				A* my = new A();
				delete my;
				my = nullptr;
				//undefined behaviour here 
				my->print();
				#endif
	// for(auto itr = vec.begin(); itr!=vec.end(); itr++)
	// {
	// 	std::cout<<vec.size()<<'\n'<<vec.capacity()<<'\n';//<<vec.front()<<'\n';
	// 	delete *itr;
	// 	//it returns an iterator, and it points to the element that is followed/next by the last erased element.
	// 	vec.erase(itr--);
		
	// }
	// delete vec.back();
	// vec.erase(vec.begin(), vec.end());
	// std::cout<<vec.size()<<'\n'<<vec.capacity()<<'\n';
	// vec.shrink_to_fit();
	// std::cout<<vec.size()<<'\n'<<vec.capacity()<<'\n';

	// std::vector<int> vec1(5,1);
	// std::cout<<vec1.size()<<'\n'<<vec1.capacity()<<'\n'<<&vec1<<'\n';
	// for(auto& i : vec1)
	// {std::cout<<'\n'<<i<<'\n'<<&i<<'\n';}

	// vec1.reserve(3);

	// std::cout<<vec1.size()<<'\n'<<vec1.capacity()<<'\n';
	// for(auto& i : vec1)
	// {std::cout<<'\n'<<i<<'\n'<<&i<<'\n';}

}


#endif



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<list>
using namespace std;
#include <numeric>
#include <array>
#include<memory>
#include<functional>
class comparator;
class A
{
	private:
	int mage;
	public:
		A(int age_):mage(age_){std::cout<<"\nA's Parameterized Constructor\n";}
		A(){std::cout<<"\nA's Constructor\n";}
		~A(){std::cout<<"\nA's Destructor\n";}
		A(A&& object)
		{
			std::cout<<"\nA's Move Constructor\n";
			mage=object.mage;
			object.mage=0;
		}
		A(const A& object)
		{
			std::cout<<"\nA's Copy Constructor\n";
			mage=object.mage;
		}
		A& operator=(A object){
			swap(*this, object);
			return *this;
		}
		friend void swap(A& object1, A& object2)
		{
			std::cout<<"\nA's Swap\n";
			using std::swap;
			swap(object1.mage , object2.mage);
		}






		// to directly enable std::less<A>() in sort
		// friend bool operator<(const A& obj1, const A& obj2)
		// {
		// 	return obj1.mage < obj2.mage;
		// }

		// friend bool operator>( const A& obj1, const A& obj2)
		// {
		// 	return obj1.mage > obj2.mage;
		// }

		bool operator< (const A& obj) const
		{
			return mage < obj.mage;
		}
		bool operator> (const A& obj) const 
		{
			return mage > obj.mage;
		}
		
		friend class comparator;
		friend bool comparator_func_ascending(A& obj1, A& obj2);
		friend bool comparator_func_descending(A& obj1, A& obj2);
		
		friend bool unary_predicate(A* object);
		void print() const {std::cout<<"\nA's print:"<<mage<<'\n';}

		
};
bool comparator_func_ascending(A& obj1, A& obj2)
{
	return obj1.mage > obj2.mage;
}
bool comparator_func_descending(A& obj1, A& obj2)
{
	return obj1.mage < obj2.mage;
}

class comparator
{
	public:
		bool operator()(const A& obj1, const A& obj2)
		{
			return obj1.mage > obj2.mage;
		}
};

bool unary_predicate(A* object)
{
	//std::cout<<object<<'\n';
	if(object->mage >= 20)
	{ 
		std::cout<<object<<std::endl;
		object->print();
		delete object;
		object = nullptr;
		return true;
	}
	return false;
}

template<typename T>
void print(T& contain)
{
	for(auto& x : contain)
	{
		
		std::cout<<x<<'\n';
	}
	std::cout<<std::endl;
	
}
template<>
void print<std::vector<A>>(std::vector<A>& obj)
{
	for(auto& x : obj)
	{
		x.print();
	}
}

int main()
{
	//A obj;
	// A *p1 =  new A(18), *p2 = new A(20), *p3=new A(22), *p4 = new A(14);

	// std::vector<A*> vec = {p1, p2, p3, p4}; //{new A(18), new A(20), new A(22) , new A(14)};
	
	// std::cout<<vec.size()<<"   "<<vec.capacity()<<"   \n";
	
	// for(int i=0; i<vec.size();++i) 
	// {
	// 	if(p1 == vec[i] || p2 == vec[i] || p3 == vec[i] || p4 == vec[i])
	// 		std::cout<<i<<"   "<<vec[i]<<'\n';
	// }
	// auto itr= std::remove_if(vec.begin(), vec.end(), unary_predicate);
	
	// for(auto& x: vec)
	// {
	// 	x->print();
	// }

	// std::cout<<"\n================================================\n";
	// vec.erase(itr, vec.end());
	// std::cout<<vec.size()<<"   "<<vec.capacity()<<'\n';
	// for(itr=vec.begin(); itr!=vec.end(); itr++)
	// {
	//  	*itr ? (*itr)->print() : (void)0;
	// }
	// p2= new A(30);
	// p3= new A(40);
	// p1= new A(30);
	// p4= new A(30);
	// std::vector<A*> vec2 = {p1,p2,p3,p4};
	
	// delete vec2[1];
	// vec2[1]=nullptr;
	// std::cout<<vec2.size()<<" vec2   "<<vec2.capacity()<<'\n';
	// std::erase(vec2, p2);
	// std::cout<<vec2.size()<<" vec2  "<<vec2.capacity()<<'\n';
	// if(vec2[1]==nullptr){
	// 	std::cout<<"\nProper deletion\n";
	
	// }
	std::vector<int> v1 ={1,2,3,4,5,6,7};
	std::vector<int> v2 ={5,6,7};
	std::cout<<std::equal(v1.begin()+4, v1.end(), v2.begin(), v2.end());// true
	A ob1{30}, ob2{10};
	std::vector<A> vect = {ob1, ob2}; 
	// //std::sort(vect.begin(), vect.end());
	// //std::sort(vect.begin(), vect.end(), std::less<A>());
	// //std::sort(vect.begin(), vect.end(), comparator());
	// std::sort(vect.begin(), vect.end(), comparator_func_ascending);
	// print(vect);
	auto val = std::min_element(vect.begin(), vect.end(), std::less<A>());
	//val.first->print();
	//val.second->print();


}