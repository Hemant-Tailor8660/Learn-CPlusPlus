#include <iostream>
#include<memory>
#include<string>
#define  LINKEDIN_CONTEXT 1  

using namespace std;

//Interface which abstract the operation
class ISocialMediaStrategy
{
	public:
		virtual ~ISocialMediaStrategy()=default;
		virtual void connect(const string&)=0;
};

//concrete strategy 1
class FacebookStrategy: public ISocialMediaStrategy{
	void connect(const string& frnd) override{
		cout<<"\nconnecting with "<<frnd<<" through Facebook"<<endl;
	}
};

//concrete strategy 2
class InstagramStrategy: public ISocialMediaStrategy{
	void connect(const string& frnd) override{
		cout<<"\nconnecting with "<<frnd<<" through Instagram"<<endl;
	}
};

//concrete strategy 3
class LinkedinStrategy: public ISocialMediaStrategy{
	void connect(const string& frnd) override{
		cout<<"\nconnecting with "<<frnd<<" through Linkedin"<<endl;
	}
};

//Context which determines the implementation
class SocialMediaContext
{
	private:
		unique_ptr<ISocialMediaStrategy> mstrategy;
		//ISocialMediaStrategy* mstrategy;
	public:
		SocialMediaContext():mstrategy(nullptr){}
		/*~SocialMediaContext(){ // used when we are not using smart ptr, to get rid off mem leak.
			if(mstrategy){
				delete mstrategy;
			}
		}*/
		void setSocialMediaStrategy(unique_ptr<ISocialMediaStrategy> st){
			mstrategy=move(st);
		}
		void connectTo(const string& frnd){
			mstrategy->connect(frnd);
		}
};

int main()
{
	unique_ptr<SocialMediaContext> context= make_unique<SocialMediaContext>();
	
	unique_ptr<ISocialMediaStrategy> strategy;
	#ifdef FB_CONTEXT
	strategy = make_unique<FacebookStrategy>(); 
	#elif LINKEDIN_CONTEXT
	strategy = make_unique<LinkedinStrategy>();
	#else
	strategy = make_unique<InstagramStrategy>();
	#endif
	context->setSocialMediaStrategy(move(strategy));
	context->connectTo(string("Pankaj"));
	//std::cout << "Hello world!" << std::endl;
}