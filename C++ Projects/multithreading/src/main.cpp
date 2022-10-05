#include <iostream>
#include <thread>
#include<mutex>
#include<condition_variable>
#include <semaphore.h>

using namespace std;

//Question1 : Print element at even index and odd index using 2 threads? 
//And replace element at even ind with 0, and element at odd ind with 1?
mutex m;
condition_variable cv;
int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
int i=0;

void evenFun(){
	while(i<15)	
	{
		unique_p
		unique_lock<mutex> l1(m);
		cv.wait(l1, []{ 
				return ((i&1)!=0);
				});
		if(i<15){
			cout<<"Even ind: "<<i<<" Element is :"<<arr[i]<<endl;
			arr[i]=0;
			++i;
		}
		l1.unlock();
		cv.notify_one();
	}

}

void oddFun(){
	while (i<15)
	{
		unique_lock<mutex> l2(m);
		cv.wait(l2, []{ 
			return (i&1);
			});
		if(i<15){
			cout<<"Odd ind: "<<i<<" Element is :"<<arr[i]<<endl;
			arr[i]=1;
			++i;
		}
		l2.unlock();
		cv.notify_one();
	}
			
}

int main()
{
	thread t1(evenFun);
	thread t2(oddFun);
	thera
	t1.join();
	t2.join();
	cout<<"\n\nIn Orginal array:\nEven index is replaced by: 0\nOdd is replaced by: 1\n";
	for(auto x: arr){
		cout<<x<<endl;
	}
	std::cout << "Hello world!" << std::endl;
	return 0;
}


//===================================================================================\

//std::counting_semaphore<5> obj(5);
