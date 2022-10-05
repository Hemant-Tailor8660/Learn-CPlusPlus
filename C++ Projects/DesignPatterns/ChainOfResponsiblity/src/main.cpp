#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Authentication
{
	public:
		virtual ~Authentication()=default;
		virtual Authentication* setNextAuthentication(Authentication*)=0;
		virtual bool authenticate()=0;
};

class AbstractAuthentication:public Authentication
{
	protected:
		Authentication* mnext;
	public:
		AbstractAuthentication():mnext(nullptr){}
		~AbstractAuthentication(){
			if(mnext){
				delete mnext;
				//mnext = nullptr;
			}
		}
		Authentication* setNextAuthentication(Authentication* auth) override{
			this->mnext=auth;
			return auth;// to work as chain
		}
	
		bool authenticate() override{
			if(mnext!=nullptr){
				cout<<"nxt authentication step"<<endl;
				this->mnext->authenticate();
			}
			return false;
		}
};

class UserNameAuth: public AbstractAuthentication
{
	private:
		string mname;
	public:
		~UserNameAuth(){}
		UserNameAuth(const string& name):mname(name){}
		bool isValidUserName(){
			return true;
		}
		bool authenticate() override{
			if(!isValidUserName()){
				cout<<"Incorrect User Name!!!"<<endl;
				return false;
			}
			else if(mnext!=nullptr){
				cout<<"User Name Matched"<<endl;
				return AbstractAuthentication::authenticate();
			}
			else{//All security checkins done so user is valid user
				cout<<"User Name Matched"<<endl;
				cout<<"All check done! User successfully loged in"<<endl;
				return true;
			}
		}
};

class PasswordAuth: public AbstractAuthentication
{
	private:
		string mpass;
	public:
		~PasswordAuth(){}
		PasswordAuth(const string& name):mpass(name){}
		bool isValidPassword(){
			return true;
		}
		bool authenticate() override{
			if(!isValidPassword()){
				cout<<"Incorrect Password!!!"<<endl;
				return false;
			}
			else if(mnext!=nullptr){
				cout<<"Pass Matched"<<endl;
				return AbstractAuthentication::authenticate();
			}
			else{ //all security checkins done so user is valid user
				cout<<"Pass Matched"<<endl;
				cout<<"All check done! User successfully loged in"<<endl;
				return true;
			}
		}
};


int main()
{	

//	UserNameAuth* username= new UserNameAuth("Hemant");
//	PasswordAuth* password= new PasswordAuth("hemant8508");
//	username->setNextAuthentication(password);
	Authentication* login= new UserNameAuth("Hemant");
	login->setNextAuthentication(new PasswordAuth("hemant8508"));	
	login->authenticate();
	
	delete login;

	std::cout << "Hello world!" << std::endl;
	return 0;
}