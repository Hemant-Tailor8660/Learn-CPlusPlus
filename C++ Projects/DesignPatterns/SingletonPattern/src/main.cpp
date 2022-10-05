#include <iostream>
#include<memory>
#include<thread>
#include<mutex>
#include<string>
#include<atomic>
using namespace std;
//#define logging 
class Singleton final
{
	public:
		
		~Singleton()//=default;
		{
			std::cout<<"Destructor perform cleanup activity...!\n";
		}
		
		
		//copy assignment and copy constructo
		Singleton(const Singleton&)=delete;
		Singleton& operator =(const Singleton&)=delete;
		
		
		/*-------------------------------------------------------------------------------------
		 *move assignment and move constructor
		 *there is no need to delete the latter. once an instance has been provided to a client,
		 *the client can do whatever he wants with it, including transferring the instance.
		 *-------------------------------------------------------------------------------------*/
		Singleton(Singleton&&) noexcept =default;
		Singleton& operator =(Singleton&&) noexcept =default;


		static Singleton& getInstance()
		{
			/*----------------------------------------------------------------------------------
			 *C++11 mandates that the initializer for a local static variable is only run once,
			 *even in the presence of concurrency. so, assuming you’ve got a modern C++ compiler,
			 *this code is thread-safe .
			 *---------------------------------------------------------------------------------*/

			// Meyer's singleton
			// static Singleton singleton;
			// return singleton;

			// C++11 thread-safe
			// Why 2 times nullptr check?(
			// Suppose 2-threads enter into below if(singleton==nullptr) condition
			// one thread will lock the mutex, and create singleton object on heap.
			// now once thread unlock the mutex, the waiting thread acquire mutex and 
			// create new singleton object on heap, due to this we have to again check for nullptr. 
			if(singleton == nullptr)
			{
				std::lock_guard<std::mutex> lock(m);
				if(singleton==nullptr)
				{
					singleton = new Singleton();
				}
			}
			incRefCount();
			return *singleton;
		}
		static void releaseInstance()
		{
			decRefCount();
			#ifdef logging
				std::cout<<"release call\n";
			#endif

			if(refCount == 0 && singleton!=nullptr )
			{
				std::cout<<"delete instance as refCount reaches: "<<refCount.load()<<std::endl;
				delete singleton;
				singleton=nullptr;
			}
		}
		
		//bussiness logic
		void print(std::string&& s){

			std::cout<<s<<", Bussiness logic performed"<<std::endl;
		}

	private:
		static Singleton *singleton; //old style of singleton
		static std::atomic<int> refCount;
		static std::mutex m;
		
		Singleton()//=default;
		{
			std::cout<<"Constructed once\n";
		}
		static void incRefCount()
		{
			++refCount;
			#ifdef logging
				std::cout<<"ref count: "<<refCount.load()<<"\n";
			#endif
		}
		static void decRefCount()
		{
			--refCount;
			#ifdef logging
				std::cout<<"ref count: "<<refCount.load()<<"\n";
			#endif
		}
};

Singleton* Singleton::singleton = nullptr;// old style of singleton
std::atomic<int> Singleton::refCount = 0;
std::mutex Singleton::m;


//Threads
void ThreadOne()
{
	// Thread One
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton::getInstance().print("Thread ONE is executing");
	Singleton::releaseInstance();
}
 
void ThreadTwo()
{
	// Thread Two
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	Singleton::getInstance().print("Thread TWO is executing");
	Singleton::releaseInstance();
}


int main()
{
	/*
	// Singleton& singleton_ = Singleton::getInstance();
	// singleton_.print("Main");

	// Singleton& sin = Singleton::getInstance();
	// sin.print("Main");
	// cout<<&singleton_<<endl<<&sin<<endl;
	
	// singleton_.releaseInstance();
	// sin.releaseInstance();
	//delete &singleton_;
	//singleton.print();
	*/

	std::thread t1(ThreadOne);
	std::thread t2(ThreadTwo);
	//waiting
	Singleton::getInstance().print("Parent process is Waiting for threads");

	t1.join();
	t2.join();
	Singleton::releaseInstance();
	return 0;
}