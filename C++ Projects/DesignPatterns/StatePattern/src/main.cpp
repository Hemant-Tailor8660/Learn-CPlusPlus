#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Gate;
class GateState{
	protected:
		Gate *mgate;
	public:
		virtual ~GateState()=default;
		virtual void enter()=0;
		virtual void payOK()=0;
		virtual void payFailed()=0;
		//virtual void enter()=0;
    void set_Gate(Gate *gate){
        this->mgate=gate;
    }
};
class Gate{
	private:
		GateState* mstate;
	public:
		//in constructor we are setting initial state of gate 
		Gate(GateState *state):mstate(nullptr){
      		cout<<"Initial Gate state: "<<typeid(*state).name()<<endl;
      		this->changeState(state);
		}

		~Gate(){
			if(mstate)
				delete mstate;
		}

    void changeState(GateState *state){
      cout<<"Gate state change to state: "<<typeid(*state).name()<<endl;
        if(mstate!=nullptr){
            delete mstate;
        }
        mstate=state;
        mstate->set_Gate(this);
    }
		
		void enter(){
			mstate->enter();
		}
		void payOK(){
			mstate->payOK();
		}
		void payFailed(){
			mstate->payFailed();
		}
		

}; 
class OpenGateState:public GateState{
		
	//Gate* mgate;
	public:
		void enter() override;
		void payFailed() override;
    void payOK() override{
			cout<<"during open state, payOK event occurs"<<endl;
			mgate->changeState(new OpenGateState);
		}
};

class ClosedGateState:public GateState
{	
	public:
		void enter() override{
			cout<<"during closed state, enter event occurs"<<endl;
			mgate->changeState(new ClosedGateState);
		}
		void payOK() override{
			cout<<"during closed state, payOK event occurs"<<endl;
			this->mgate->changeState(new OpenGateState);
		}
		void payFailed() override{
			cout<<"during closed state, payFailed event occurs"<<endl;
			mgate->changeState(new ClosedGateState);
		}
};

void OpenGateState:: enter(){
	cout<<"during open state, enter event occurs"<<endl;
	mgate->changeState(new ClosedGateState);

}
void OpenGateState::payFailed(){
	cout<<"during open state, payFailed event occurs"<<endl;
	mgate->changeState(new ClosedGateState);
}


int main(){ 
	Gate* gate= new Gate(new ClosedGateState);
	gate->payOK();
	delete gate;
	std::cout << "Hello world!" << std::endl;
	return 0;
}