#include <iostream>
#include<memory>
#define MAC
using namespace std;

//Product interface
class Widget
{
	public:
		virtual ~Widget(){}
		virtual void paint()=0;
};
//Concrete Product 1
class MacButton:public Widget
{
	public:
		void paint(){
			cout<<"Mac Button"<<endl;
		}
};
//Concrete Product 1
class WinButton:public Widget
{
	public:
		void paint(){
			cout<<"Win Button"<<endl;
		}
};

/*//Interface Product 2
class ScrollBar
{
	public:
		virtual ~ScrollBar(){}
		virtual void paint()=0;
};
*/
//Concrete Product 2
class MacScrollBar:public Widget
{
	public:
		void paint(){
			cout<<"Mac ScrollBar"<<endl;
		}
};

//Concrete Product 2
class WinScrollBar:public Widget
{
	public:
		void paint(){
			cout<<"Win ScrollBar"<<endl;
		}
};

//Interface for Factory
class guiFactory
{
	public:
		virtual ~guiFactory(){}
		virtual unique_ptr<Widget> buildButton()=0;
		virtual unique_ptr<Widget> buildScrollBar()=0;
};

//Concrete factory for Mac: It is responsible to create group of related object(i.e. Button and ScrollBar)
// for Mac
class MacFactory:public guiFactory
{
	public:
		unique_ptr<Widget> buildButton(){
			return make_unique<MacButton>();
		}

		unique_ptr<Widget> buildScrollBar(){
			return make_unique<MacScrollBar>();
		}
};

//Concrete factory for Windows: It is responsible to create group of related object(i.e. Button and ScrollBar)
//for Win
class WinFactory:public guiFactory
{
	public:
		unique_ptr<Widget> buildButton(){
			return make_unique<WinButton>();
		}

		unique_ptr<Widget> buildScrollBar(){
			return make_unique<WinScrollBar>();
		}
};

//Client
class client
{
	private:
		unique_ptr<guiFactory> mgui;
	public:
		client(unique_ptr<guiFactory>gui ): mgui(move(gui)){

		}
		void draw(){
			unique_ptr<Widget> wid[] = {mgui->buildButton(),mgui->buildScrollBar()};
			wid[0]->paint();
			wid[1]->paint();
		}
};
int main()
{

	unique_ptr<guiFactory> gui;
	
	#ifdef  MAC
	gui= make_unique<MacFactory>();
	#else //WINDOWS
	gui= make_unique<WinFactory>();
	#endif
	
	
	//Pass Factory to client
	unique_ptr<client> cli= make_unique<client>(move(gui));
	cli->draw();
	/*
	//################Mac Related Object#####################
	guiFactory *gui;
	unique_ptr<Widget> button;
	unique_ptr<Widget> scrollbar;
	gui = new MacFactory();
	button = gui->buildButton();
	button->paint();
	scrollbar = gui->buildScrollBar();
	scrollbar->paint();
	//#######################################################
	
	//################Win Related Object#####################
	gui = new MacFactory();
	button = gui->buildButton();
	scrollbar = gui->buildScrollBar();
	gui = new WinFactory();
	button = gui->buildButton();
	button->paint();
	scrollbar = gui->buildScrollBar();
	scrollbar->paint();
	//#######################################################
	*/
}