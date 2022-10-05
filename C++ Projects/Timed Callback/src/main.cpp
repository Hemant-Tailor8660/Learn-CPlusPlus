#include <iostream>
#include<thread>

//using namespace std;

class Timer
{	private:
		bool mTimerStopped; //if false timer is running, if true timer is stopped;
	public:
	   //---------------C++20---------------------------
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

	   Timer():mTimerStopped(false)
		{			
		}
		
		~Timer()
		{
			mTimerStopped = false;
		}
};
//template<typename T>
void Timer::setTimeout(/*T*/auto function, int delay){
	this->mTimerStopped=false;
	std::thread t([=,this](){
		// Check if timer is stopped(i.e. true) by some other function or still running.
		if(this->mTimerStopped){
			return;
		}
		
		//If timer is still active thread wait for indicated delay. 
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));

		// Sometime OS will take little bit more time to hand back the execution to thread, 
		// so again check if timer is stopped(i.e. true) by some other function or still running.
		if(this->mTimerStopped){
			return;
		}
		
		// If timer is active execute the function.
		function();
	});

	// Detach this thread from main thread so the main thread doesn't dependent on this thread to finish.
	t.detach();
}

//template<typename T>
void Timer::setInterval(/*T*/auto function, int interval){
	this->mTimerStopped=false;
	std::thread t([=,this](){
		while(true)
		{
			if(this->mTimerStopped){
				return;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if(this->mTimerStopped){
				return;
			}
			function();
		}
	});
	t.detach();
}

void Timer::stop(){
	this->mTimerStopped=true;
}

void fun(){

	std::cout<<"Hello hemant"<<std::endl;
	//timer.stop();
}
int main()
{
	Timer timer;
	std::cout<<"Call back fuction called from main after 5 seconds"<<std::endl;
	timer.setTimeout(fun,5000);
	//timer.setInterval(fun, 1000);
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
	std::cout<<"EXIT_MAIN\n";
	return 0;
}