

//Question1 : Print element at even index and odd index using 2 threads? 
//And replace element at even ind with 0, and element at odd ind with 1?
//And return sum of elements at even index and sum of element at odd index from thread?



// #include <iostream>
// #include <thread>
// #include<mutex>
// #include<condition_variable>
// #include <semaphore.h>
// #include <future>
// #include <atomic>
// #include<functional>
// //using namespace std;



// std::mutex m;
// std::condition_variable cv;
// int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
// std::atomic<int> ind = 0;//std::atomic<int> ind=0;

// int evenFun(const size_t& arrSize){
// 	int evSum=0;
// 	while(ind<arrSize-1)	
// 	{
// 		/*std::cout<<"\nevenfun\n";*/

// 		std::unique_lock<std::mutex> l1(m);
// 		cv.wait(l1, []{ 
// 				return ((ind&1)==0);
// 				});
// 		//if(ind<15){
// 		std::cout<<"Even ind: "<<ind<<" Element is :"<<arr[ind]<<std::endl;
// 		evSum+=arr[ind];
// 		arr[ind]=0;
// 		++ind;
// 		//}
		
// 		l1.unlock();
// 		cv.notify_one();
// 	}
// 	return evSum;

// }

// int oddFun(const size_t& arrSize){
// 	int oddSum=0;
// 	while (ind<arrSize-1)
// 	{
// 		//std::cout<<"\noddfun\n";
// 		std::unique_lock<std::mutex> l2(m);
// 		cv.wait(l2, []{ 
// 			return (ind&1);
// 			});
// 		//if(ind<15){
// 		std::cout<<"Odd ind: "<<ind<<" Element is :"<<arr[ind]<<std::endl;
// 		oddSum+=arr[ind];
// 		arr[ind]=1;
// 		++ind;
// 		//}
		
// 		l2.unlock();
// 		cv.notify_one();
// 	}
// 	return oddSum;
			
// }

// int main()
// {
// 	//thread t1(evenFun);
// 	//thread t2(oddFun);
// 	//if(t1.joinable()) t1.join(); 
// 	//if(t2.joinable()) t2.join();

// 	size_t arrSize = sizeof arr / sizeof arr[0]; 
// 	std::future<int> evFut = std::async(std::launch::async|std::launch::deferred, evenFun, std::ref(arrSize));
// 	std::future<int> oddFut = std::async(std::launch::async|std::launch::deferred, oddFun, std::ref(arrSize)); 
// 	int ev = evFut.get();
// 	int od = oddFut.get();
// 	std::cout<<"\nSum of Even indexed elements: "<<ev<<std::endl;
// 	std::cout<<"\nSum of Odd indexed elements: "<<od<<std::endl;
// 	std::cout<<"\n\nIn Orginal array:\nEven indexed element is replaced by: 0\nOdd indexed element\
// is replaced by: 1\nFinal updated array: ";
// 	for(auto x: arr){
// 		std::cout<<x<<" ";
// 	}
// 	std::cout<<"\n\n";
// 	return 0;
// }


//===================================================================================\

//std::counting_semaphore<5> obj(5);




// #include <iostream>
// //#include <thread>
// #include<functional>

// #include <vector>
// #include<algorithm>
// void th_func(int& i)
// {
// 	i=100;
// 	std::cout<<"\nvalue of i, chnged by thread is: "<<i<<"\n";
// }
// int main(int argc, char *argv[])
// {
// 	int i=10;
// 	std::vector<int> v{1,2,2,3,4,5,6};
// 	std::fill_n(v.begin(), 2, 20);
// 	for(auto d : v){std::cout<<std::endl<<d;}
// 	// std::thread ob(th_func, std::ref(i));
// 	// ob.join();
// 	// std::cout<<"\nThread obj changed the value of i: "<<i<<std::endl;
// 	//std::cout << "Hello world!" << std::endl;

// }




#include <iostream>
#include<thread>
using namespace std;

enum Status{E_TimerActive, E_TimerInActive};

class Timer
{	private:
		bool timerStatus = E_TimerInActive;
	public:
	   ///*---------------C++20---------------------------
		void stop();
		void setTimeout(auto function, int delay);
		void setInterval(auto function, int interval);
	    //-----------------------------------------------*/

	   /*---------------C++17---------------------------
	    *void stop();
	    *template<typename T>
	    *void setTimeout(T function, int delay);
	    *template<typename T>
	    *void setInterval(T function, int interval);
	    *-----------------------------------------------*/
};
//template<typename T>
void Timer::setTimeout(/*T*/auto function, int delay){
	this->timerStatus = E_TimerInActive;
	thread t([=,this](){
		if(this->timerStatus == E_TimerActive)
			return;
		
		this_thread::sleep_for(std::chrono::milliseconds(delay));
		
		if(this->timerStatus == E_TimerActive)
			return;
		
		function();
	});
	t.detach();
}

//template<typename T>
void Timer::setInterval(/*T*/auto function, int interval){
	this->timerStatus=E_TimerInActive;
	thread t([=,this](){
		while(true)
		{
			if(this->timerStatus == E_TimerActive)
				return;
			this_thread::sleep_for(chrono::milliseconds(interval));
			if(this->timerStatus == E_TimerActive)
				return;
			function();
		}
	});
	t.detach();
}

void Timer::stop(){
	this->timerStatus=E_TimerActive;
}

void fun(){
	std::cout<<"Hello hemant"<<std::endl;
}

int main()
{
	Timer obj;
	cout<<"Call back fuction called from main after 5 seconds"<<endl;
	//obj.setTimeout(fun,5000);
	obj.setInterval(fun, 1000);
	//std::cout << "Hello world!" << std::endl;
	this_thread::sleep_for(chrono::milliseconds(6000));
	obj.stop();
	return 0;
}