#include <iostream>
#include <cstring>
#include<stdexcept>
#include<vector>
#define COPY_AND_SWAP_IDIOM 
using namespace std;

#if 0
class String
{
	public:
		~String()
		{
			if(mstr){
				delete mstr;
				mlen = 0;
				mstr = nullptr;
			}
		}

		String():mlen(0), mstr(nullptr)
		{

		}

		// String str = "Hello";
		String(const char* str) : mlen(str ? strlen(str) + 1 : 0), mstr(mlen ? new char[mlen]: nullptr) //mstr(str != nullptr ? new char[strlen(str)+1]: nullptr), mlen(str!=nullptr ? strlen(str) : 0)
		{
			std::cout<<"\nImplicit Constructor call\n";
			
			if(str!=nullptr)
			{
				std::copy(str, str + mlen, this->mstr);
			}

			// if(str==nullptr)
			// {
			// 	throw std::invalid_argument("Please pass correct arguments");
			// }
			// this->mstr = new char[strlen(str)+1];
			// this->mlen = strlen(str);
		}

		String(const String& object) : mlen(object.mlen), mstr(mlen ? new char[mlen] : nullptr) //: mstr(nullptr) , mlen(0)
		{
			std::cout<<"\nCopy const\n";
			//this->mstr = new char[strlen(object.mstr) + 1]; // new char[object.mlen + 1];
			if(mstr!=nullptr)
				std::copy(object.mstr, object.mstr + mlen/*object.mlen*/, this->mstr);
		}

		#ifndef COPY_AND_SWAP_IDIOM
			String(String&& object) noexcept : mlen(object.mlen), mstr(object.mstr)//mstr(nullptr) , mlen(0)
			{
				std::cout<<"\nMove const\n";
				//move 
				// this->mstr = object.mstr;//std::move(object.mstr);
				// this->mlen = object.mlen;

				// reset the rref object
				object.mstr = nullptr;
				object.mlen = 0; 
			}
			
			// String s1= nullptr;  mstr =nullptr, mlen = 0
			// String s2 = nullptr; mstr =nullptr, mlen=0
			//s2 = s1
			String& operator=(const String& object)
			{
				std::cout<<"\nCopy Assignment\n";
				if(this != &object)
				{
					//content present in old object should be deleted first 
					
					//if(this->mstr) no need of if check as it is safe and valid to delete a pointer initialized to nullptr  
					delete[] this->mstr;
					//allocate space for new content
					this->mstr = object.mlen ? new char[object.mlen] : nullptr;// new char[strlen(object.mstr) + 1];
					this->mlen = object.mlen;
					
					//copy content from passed object to old object
					if(this->mstr && object.mstr)
						std::copy(object.mstr, object.mstr + object.mlen, this->mstr);
					
				}
				return (*this);
			}

			

			String& operator=(String&& object) noexcept
			{
				std::cout<<"\nMOVE Assignment\n"<<&object;
				if(this != &object)
				{
					delete[] this->mstr;
					this->mstr = object.mstr;
					this->mlen = object.mlen;

					object.mstr = nullptr;
					object.mlen = 0;
				}
				return (*this);
			}
		#endif

		#ifdef COPY_AND_SWAP_IDIOM
			// swap function to be found via ADL	why friend function? bcz friend function found via ADL, if compiler find better match via ADL it will use that instead. o/w std::swap will be used
			friend void swap(String& object1, String& object2)
			{
				std::cout<<"\nUser defined swap\n";
				using std::swap;

				swap(object1.mlen, object2.mlen);
				swap(object1.mstr, object2.mstr);
			}
			// move constructor using constructor delegation and swap
			String(String&& object) noexcept : String()
			{
				std::cout<<"\nMove Constructor\n";
				swap(*this, object);
			}
			
			// assignment operator with strong exception guarantee and without code duplication
			String& operator=(String object)
			{
				swap(*this, object);
				//std::swap(*this, object); // not used bcz it uses both copy constructor and copy assignment
				return *this;
			}

		#endif

		void print()
		{
			if(this->mstr)
				std::cout<<"\n"<<this->mstr<<"\n";
		}

	

	private:
		//The order of below arguments is super important.
		size_t mlen;
		char* mstr;
		
};
String fun()
{
	String x ="Hi";
	std::cout<<"\n"<<&x<<"\n";
	return x;
}


int main(int argc, char *argv[])
{
	String s = "nullptr";
	String ss ="nullptrhi";
	std::cout<<"Data before swap :"<<std::endl;
	s.print();
	ss.print();

	swap(s,ss);
	
	std::cout<<"Data after swap :"<<std::endl;
	s.print();
	ss.print();
	
	//fun();
	// std::vector<String> vec;
	// vec.push_back(String(nullptr));

	// String ms(nullptr) ;
	// ms = fun();
	//ms.print();
	//ss = "Hi";
	//ss.print();
	//s.print();
	// try
	// {
	// 	String ss = nullptr;
	// 	ss = s;
	// 	//String s(ss, 3/*strlen(ss)*/);
	// }
	// catch (std::invalid_argument& e)
	// {
	// 	std::cout<<e.what();
	// }
}



// String(char* str, size_t len) : mstr(nullptr), mlen(len)  
		// 	//: mstr((str != nullptr && len > 0 && strlen(str) == len ) ? new char[len + 1] : nullptr)
		// 	//, mlen(len)
		// {
		// 	//this->mlen = len;
		// 	if(str == nullptr && len < 0 && strlen(str) != len) 
		// 	{
		// 		throw std::invalid_argument("Invalid Arguments!!!");
		// 	}
		// 	this->mstr = new char[len + 1]; // new char[len + 1];
		// 	std::copy(str, str + len, this->mstr); //strcpy(this->mstr, str); 
			
		// 	// if(str != nullptr && len > 0 && strlen(str) == len ) // order of condition(strlen(str) == len) should be after str != nullptr
		// 	// {
		// 	// 	this->mstr = new char[strlen(str) + 1]; // new char[len + 1];
		// 	// 	std::copy(str, str + len, this->mstr); //strcpy(this->mstr, str); 
		// 	// }
			
		// }

#endif


#if 0
#include<string>
class B{
	public:
	B(){std::cout<<"\nDefault constructor\n";}
	B(const B& ){std::cout<<"\nCopy constructor\n";}
};

std::vector<std::string> get_names()
{
	
	std::vector<std::string> temp = {"Hello", "Hi", "Honey", "Pooja"}; 
	return temp;
}

B fun()
{
	return B();
}
int main()
{
	B b = fun();
	std::vector<std::string> names = get_names();
}

#endif
// #include<memory>
// #include<thread>
// #include<mutex>

// class Lock
// {
// 	public:
// 		Lock(std::mutex* mp) : m(mp, ){}
// 	private:
// 		std::shared_ptr<std::mutex> m;

// };