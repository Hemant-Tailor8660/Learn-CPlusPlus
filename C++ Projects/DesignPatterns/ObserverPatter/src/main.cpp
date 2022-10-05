#include <iostream>
#include<vector>
#include<algorithm>
#include <memory>
//using namespace std;
/*
////////////////////////////////////////////////Example-1/////////////////////////////////////////////////////
//Forward declaration
class Subject;
//Interface for Observers
class Observer
{
	public:
		virtual ~Observer()=default;
		virtual void Update(int runs, int wickets, float overs)=0;
};

//Interface for Subject/Observable
class Subject
{
	public:
		virtual void Subscribe( Observer * Obs)=0;
		virtual void UnSubscribe( Observer * Obs)=0;
		virtual void Notify() =0;
		virtual ~Subject()=default;
	
};

//Concrete Subject i.e CricketData
class CricketData: public Subject
{
	public:
		void Subscribe( Observer* Obs){
			mobs.push_back(Obs);
		}

		void UnSubscribe( Observer* Obs){
			auto itr = std::find(mobs.begin(), mobs.end(), Obs);
			if(itr != mobs.end()) 
			{
				mobs.erase(itr) ;
			} 
		}

		void Notify() {
			for(auto x: mobs){
				x->Update(runs, wickets, overs);
			} 
		}

		int getLatestRuns(){
			return 82;
		}

		int getLatestWickets(){
			return 2;
		}

		float getLatestOvers(){
			return (float)10.2;
		}

		void DataChanged(){
			runs=getLatestRuns();
			wickets=getLatestWickets();
			overs=getLatestOvers();
			Notify();
		}
	private:
		int runs, wickets;
		float overs;
		std::vector<Observer*> mobs;
};

//Concrete Observer 1 i.e. CurrentScore
class CurrentScore: public Observer
{
	private:
		int runs, wickets;
		float overs;
		std::shared_ptr<Subject> _sub;//Subject* _sub; 
	public:
		CurrentScore(std::shared_ptr<Subject> sub): _sub(sub){
			_sub->Subscribe(this);
		}

		~CurrentScore(){
			_sub->UnSubscribe(this);
			//_sub=nullptr;
		}

		void Display(){
			float runRate= runs/overs;
			std::cout<<"\n\nCurrent Score Details:"<<std::endl<<"Score:"<<runs<<std::endl<<"Wickets:"<<wickets<<std::endl<<"Overs:"<<overs;
		}

		void Update(int runs, int wickets, float overs) {
			this->runs= runs;
			this->wickets= wickets;
			this->overs= overs;
			Display();
		}
};

class AverageScore: public Observer
{
	private:
		float runRate;
		int predScore;
		std::shared_ptr<Subject> _sub;//Subject* _sub;
	public:
		
		AverageScore(std::shared_ptr<Subject> sub): _sub(sub){//AverageScore(Subject* sub): _sub(sub){
			_sub->Subscribe(this);
		}
		~AverageScore(){
			_sub->UnSubscribe(this);
			//_sub=nullptr;
		}
		void Display(){
			std::cout<<"\n\nAverage Score Details:"<<std::endl<<"Predcted Score:"<<predScore<<std::endl<<"RunRate:"<<runRate<<std::endl;
		}
		void Update(int runs, int wickets, float overs){
			runRate = runs/overs;
			predScore = runRate * 50;
			Display();
		}
		

};
int main(int argc, char *argv[])
{	
	std::shared_ptr<CricketData> cricketdata = std::make_shared<CricketData>();//CricketData * cricketdata = new CricketData();
	std::unique_ptr<CurrentScore> currentscore = std::make_unique<CurrentScore>(cricketdata);//CurrentScore * currentscore = new CurrentScore(cricketdata);
	std::unique_ptr<AverageScore> averagescore = std::make_unique<AverageScore>(cricketdata);//AverageScore * averagescore = new AverageScore(cricketdata);
	cricketdata->DataChanged();
	cricketdata->UnSubscribe(averagescore.get());
	cricketdata->DataChanged();
	averagescore->Display();
	
	
	//delete currentscore;
	//delete averagescore;
	// delete cricketdata;
	return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////Example-2////////////////////////////////////////////////////////
class Observer
{
	public:
		virtual ~Observer(){
			std::cout<<"\nObserver Destructor\n";
		}//=default;
		virtual void update(std::string product) = 0;
		//virtual const std::string& getProductDetails() = 0;
	
};

class Subject
{
	public:
		virtual ~Subject()=default;
		virtual void Subscribe(Observer* observer) = 0;
		virtual void UnSubscribe(Observer* observer) = 0;
		virtual void Notify() = 0;
		
};


class Amazon : public Subject
{
	
	public:
		void Subscribe(Observer* observer) override
		{
			mobs.push_back(observer);
		}
		
		void UnSubscribe(Observer* observer) override
		{
			auto itrToDelete = std::find(mobs.begin(), mobs.end(), observer);
			// C++20 feature std::erase(vecobj, elem_val_to_deleted); erase and remove idiom
			// if(itrToDelete)
			//{ 
			//	delete *itrToDelete; 
			//	*itrToDelete =nullptr;
			//  std::erase(mobs, observer);
			//}
			
			if(itrToDelete != mobs.end())
			{
				
				std::erase(mobs, observer);
				std::cout<<"\nDelete\n"<<*itrToDelete<<"    "<< observer<<'\n';
				// delete *itrToDelete;
				*itrToDelete = nullptr;				
				// mobs.erase(itrToDelete);
			}
		}
		void Notify() override
		{
			for(auto observer : mobs)
			{
				observer->update(mproduct);
			}
		}
		
		void setProductAvailablity(std::string product)
		{
			this->mproduct = product;
			//Once the product is available in store, notify all the subscriber who set alert for availability
			Notify();
		}
		
		const std::string& getProductDetails()
		{
			return this->mproduct;
		}
		private:
		std::vector<Observer*> mobs;
		std::string mproduct;
		
};


class IphoneCustomers : public Observer
{
	public:
		
		IphoneCustomers(std::shared_ptr<Subject> sub) : m_amazon (sub)
		{
			sub->Subscribe(this);
		}
		~IphoneCustomers()
		{
			m_amazon->UnSubscribe(this);
			//delete m_amazon;
			//m_amazon = nullptr;			
		}
		
		void update(std::string product) override
		{
			// /* std::shared_ptr<Amazon> */ auto amazon =  std::dynamic_pointer_cast<Amazon>(m_amazon);
			// this->mproduct = amazon->getProductDetails();
			this->mproduct = product; 
			std::cout<<mproduct<<std::endl;
		}
		
		
	private:
		std::shared_ptr<Subject> m_amazon; 
		std::string mproduct;	
};

int main()
{
	std::string product = "Iphone - 13";
	std::shared_ptr<Amazon> amazon = std::make_shared<Amazon>();
	std::unique_ptr<IphoneCustomers> iphoneCustomer = std::make_unique<IphoneCustomers>(amazon);
	amazon->setProductAvailablity(product);	
	amazon->UnSubscribe(iphoneCustomer.get());
	amazon->setProductAvailablity(product);	
}
