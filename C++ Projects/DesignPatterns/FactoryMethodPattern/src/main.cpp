#include <iostream>
#include<memory>
#include<algorithm>

///////////////////////////////////////////////////EX:2////////////////////////////////////////////////////////////////////////////


enum eVehicleType
{
	E_VT_FOUR_WHEELER,
	E_VT_THREE_WHEELER,
	E_VT_TWO_WHEELER,
};


class Vehicle
{
	public:
		virtual ~Vehicle()=default;
		virtual void printVehicleDetails()=0;
};

class ThreeWheeler : public Vehicle
{
	public:
		void printVehicleDetails()
		{
			std::cout<<"\nThree Wheeler\n";
		}
};

class FourWheeler : public Vehicle
{
	public:
		void printVehicleDetails()
		{
			std::cout<<"\nFour Wheeler\n";
		}
};

class TwoWheeler : public Vehicle
{
	public:
		void printVehicleDetails()
		{
			std::cout<<"\nTwo Wheeler\n";
		}
};


class VehicleFactory
{
	public:
		static Vehicle* createVehicleFactory(eVehicleType type)
		{
			Vehicle* vehicle = nullptr;
			switch(type)
			{
				case E_VT_FOUR_WHEELER:
				{
					vehicle = new FourWheeler();
					break;
				}
				case E_VT_THREE_WHEELER:
				{
					vehicle = new ThreeWheeler();
					break;
				}
				case E_VT_TWO_WHEELER:
				{
					vehicle = new TwoWheeler();
					break;
				}
				default:
				{
					vehicle = nullptr;
					break;
				}
			}
			return vehicle;
			//vehicle->printVehicleDetails();
			//delete vehicle;
		}
		
};

///////////////////////////////////////////////////////////////////EX:2 end////////////////////////////////////////////////////////////

class TransportMode
{
	public:
	virtual ~TransportMode()=default;
	virtual void delivery()=0;
	/*void notifyDeliveryDetails()
	{
		
	}
	*/
};
class TruckTransport: public TransportMode
{
	public:
	void delivery() override
	{
		std::cout<<"deliver by truck\n";
	}
};

class ShipTransport: public TransportMode
{
	public:
	void delivery() override
	{
		std::cout<<"deliver by ship\n";
	}
};

class Logistic
{
	public:
	virtual ~Logistic()=default;
	virtual TransportMode* createTransportFactory() = 0;
	void planDelivery()
	{
		TransportMode* transport = this->createTransportFactory();
		transport->delivery();
		delete transport;
	}
};

class RoadLogistic:public Logistic
{
	TransportMode* createTransportFactory()
	{
		return new TruckTransport();
	}
};
class SeaLogistic:public Logistic
{
	TransportMode* createTransportFactory()
	{
		return new ShipTransport();
	}
};

void client(Logistic* log)
{
	log->planDelivery();
}

int main(int argc, char *argv[])
{
	//Ex-2
	Logistic* roadLog = new RoadLogistic();
	client(roadLog);
	delete roadLog;
	
	//Ex-1
	eVehicleType type = E_VT_TWO_WHEELER;
	Vehicle* vehicle = VehicleFactory::createVehicleFactory(type); 
	vehicle->printVehicleDetails();
	delete vehicle;
	
}

