#include <iostream>
#include <string>
#include <memory>
//#define _NVIDIA
using namespace std;

class vmInstance
{
	private:
		string mOS, mRAM, mGraphics, mHDDType;
	public:
		void attachRAM(string ram){
			mRAM=ram;
		}
		void attachOS(string os){
			mOS=os;
		}
		void attachGraphics(string graphics){
			mGraphics=graphics;
		}
		void attachHDD(string hdd){
			mHDDType=hdd;
		}
		void startInstance() const
		{
			cout<<"\n\nVM Instance Created with Configuration:"<<endl<<endl;
			cout<<"OS      : "<<mOS<<endl;
			cout<<"HDD Type: "<<mHDDType<<endl;
			cout<<"RAM Size: "<<mRAM<<endl;
			cout<<"Graphics: "<<mGraphics<<endl;
		}
};

//VMBuilder Interface
class VMBuilder
{
	protected:
		unique_ptr<vmInstance> vmins;
		
	public:
		VMBuilder(){
			vmins = make_unique<vmInstance>();
		}

		virtual ~VMBuilder()=default;
		/*virtual ~VMBuilder(){
			if(vmins!=nullptr)
				delete vmins;
				vmins=nullptr;
		}*/

		vmInstance* getInstance(){
			return vmins.release();
		}
		virtual void buildRAM()=0;
		virtual void buildOS()=0;
		virtual void buildHDD()=0;
		virtual void buildGraphics()=0;
		
};
//concrete Builder for NVIDIA Instance
class NVIDIA: public VMBuilder
{
	public:
	~ NVIDIA() override= default;

	void buildRAM() override
	{
		vmins->attachRAM("16GB");
	}
	void buildOS() override
	{
		vmins->attachOS("UBUNTU");
	}
	void buildHDD() override
	{
		vmins->attachHDD("HDD");
	}
	void buildGraphics() override
	{
		vmins->attachGraphics("NVIDIA GTX980");
	}
};

//concrete Builder for AMD Instance
class AMD: public VMBuilder
{
	public:
	~ AMD() override= default;

	void buildRAM() override
	{
		vmins->attachRAM("32GB");
	}
	void buildOS() override
	{
		vmins->attachOS("WINDOWS 10");
	}
	void buildHDD() override
	{
		vmins->attachHDD("SSD");
	}
	void buildGraphics() override
	{
		vmins->attachGraphics("AMD RADEON");
	}
};

//Director: it controls the steps performed by Builder

class CloudAdmin
{
	private:
		unique_ptr<VMBuilder>m_vmbuilder;
	public:
		CloudAdmin(unique_ptr<VMBuilder>_vmb):m_vmbuilder(move(_vmb)){

		}
		/*
		~CloudAdmin(){
			if(m_vmbuilder!=nullptr){
				delete m_vmbuilder;
				m_vmbuilder=nullptr;
			}
		}*/
		void construct(){
			m_vmbuilder->buildOS();
			m_vmbuilder->buildRAM();
			m_vmbuilder->buildHDD();
			m_vmbuilder->buildGraphics();
		}
		void openInstance() const{
			return m_vmbuilder->getInstance()->startInstance();
			}

};
int main()
{	
	unique_ptr <VMBuilder> vmbuilder;
	#ifdef  _NVIDIA
	vmbuilder= make_unique<NVIDIA>();
	#else //AMD
	vmbuilder= make_unique<AMD>();
	#endif  //
	unique_ptr<CloudAdmin> cloudadmin= make_unique<CloudAdmin>(move(vmbuilder));
	cloudadmin->construct();
	cloudadmin->openInstance();

/*
	//############################NVIDIA Instance###################################
	VMBuilder* vmb= new NVIDIA();
	CloudAdmin* cadmin= new CloudAdmin(vmb);
	cadmin->construct();
	vmInstance* nvidiavm = vmb->getInstance(); //or vmInstance* vm = cadmin->getInstance();
	nvidiavm->startInstance();
	delete nvidiavm;
	//##############################################################################

	//############################AMD Instance######################################
	vmb= new AMD;
	cadmin= new CloudAdmin(vmb);
	cadmin->construct();
	vmInstance* amdvm= vmb->getInstance();
	amdvm->startInstance();
	//##############################################################################
*/	
	return 0;
}