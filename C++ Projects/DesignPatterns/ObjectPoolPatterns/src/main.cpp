#include <iostream>
#include <memory>
#include<list>
#include<string>
#include<thread>
#include<mutex>

class Resource
{
	private:
		int m_iValue;
		std::string m_sDetail;
	
	public:
		//Resource()=default; //ambiguous
		Resource(int value = 0 ,  const std::string& detail = "") : m_iValue(value), m_sDetail(detail)
		{
			std::cout<<"\nResource constructor\n";
		}
		~Resource()
		{
			std::cout<<"\nResource Destructor\n";
		}

		int getValue() const
		{
			return this->m_iValue;
		}
		Resource& setValue(const int& val)
		{
			this->m_iValue = val;
			return *this;
		}
		std::string getDetail() const
		{
			return this->m_sDetail;
		}
		Resource& setDetail(const std::string& detail)
		{
			this->m_sDetail = detail;
			return *this;
		}

		void reset()
		{
			m_iValue = 0;
			m_sDetail = "";
		}
		
};

template<typename T>
class ObjectPool
{
	private:
		std::list<T*> m_listReusables;
		static ObjectPool *m_poolInstance; 
		ObjectPool()=default;
		static std::mutex mut;	
	public:
		
		ObjectPool(const ObjectPool&) = delete;		
		ObjectPool& operator =(const ObjectPool&) = delete;
		
		static ObjectPool* getInstance()
		{
			
			if(m_poolInstance == nullptr)
			{
				std::lock_guard<std::mutex> lg(mut);
				if(m_poolInstance == nullptr)
                {
					m_poolInstance = new ObjectPool();
				}
			}
			return m_poolInstance;
		}

		T* acquireReusable()
		{
			std::lock_guard<std::mutex> lg(mut);
			T* acquire = nullptr;
			if(! m_listReusables.empty())
			{
				acquire = m_listReusables.front();
				m_listReusables.pop_front();
			}
			else
			{
				acquire = new T();
			}
			std::cout<<"Reusable Pool Size: "<<m_listReusables.size()<<std::endl;
			return acquire;
		}
		
		void returnToReusablePool(T* resource)
		{
			std::lock_guard<std::mutex> lg(mut);
			if(resource!=nullptr)
			{
				resource->reset();	
				m_listReusables.push_back(resource);
				std::cout<<"Reusable Pool Size: "<<m_listReusables.size()<<std::endl;
			}
		}

		// bool releaseReusable(T* resource)
		// {
		// 	auto itr = std::find(m_listReusables.begin(), m_listReusables.end(), resource);
		// 	if (itr != m_listReusables.end())
		// 	{
		// 		m_listReusables.erase(itr);
		// 		return true;
		// 	}
		// 	return false;
		// }
 		~ObjectPool()
		{
			//cleanup activity
			std::cout<<"\nDestructor\n"<<m_listReusables.size();
			while(m_listReusables.size())
   			{
				Resource *obj = m_listReusables.front();
				m_listReusables.pop_front();
				delete obj;
				obj = nullptr;
				std::cout<<"\nDestructor\n";
    		}
		}
};
template<typename T>
ObjectPool<T>* ObjectPool<T>::m_poolInstance = nullptr;
template<typename T>
std::mutex ObjectPool<T>::mut;


int main(int argc, char *argv[])
{
	//ObjectPool<Resource> *poolInstance = ObjectPool<Resource>::getInstance();
	Resource *one, *two;
	//get a resource from resource ObjectPool
	one = ObjectPool<Resource>::getInstance()->acquireReusable();
	one->setDetail("I am a heavy resource").setValue(100);
	std::cout<<"Location: "<<one<<", Hevay Resource Data:\n"<<one->getDetail()<<std::endl<<one->getValue()<<std::endl;
	//return resource back to resource ObjectPool
	ObjectPool<Resource>::getInstance()->returnToReusablePool(std::move(one));
	//one = nullptr;


	//get a resource from resource ObjectPool
	two = ObjectPool<Resource>::getInstance()->acquireReusable();
	two->setDetail("Heavy Resource From Resource Pool").setValue(200);
	std::cout<<"Location: "<<two<<", Hevay Resource Data:\n"<<two->getDetail()<<std::endl<<two->getValue()<<std::endl;
	//ObjectPool<Resource>::getInstance()->returnToReusablePool(two);
	delete two;
	//two =nullptr;
	//delete one;
	//auto releaseStatus = ObjectPool<Resource>::getInstance()->releaseReusable(two);
	// if(two!=nullptr)
	// {
	// 	std::cout<<"\nNot Released successful\n   "<<two;
	// }
	delete ObjectPool<Resource>::getInstance();
	if(two!=nullptr)
	{
		std::cout<<"\nNot Released successful\n   "<<two;
	}
}