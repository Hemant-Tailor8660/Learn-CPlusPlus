#include <iostream>
#include<memory>
#include <string>
#include<array>

#if 0
// Double Dispatch not possible by below code.
namespace my{
	class Dog;
	class Cat;
	class Animal
	{
		public:
		virtual ~Animal()=default;
		virtual void makeSound(Dog* )=0;
		virtual void makeSound(Cat* )=0;
		virtual void makeSound(Animal* animal)=0; 
	};

	class Dog: public Animal
	{
		public:
			~Dog()=default;
			void makeSound(Dog* dog) override
			{
				std::cout<<"\nDog interacting with dog.\n";
			}
			void makeSound(Cat* cat) override
			{
				std::cout<<"\nDog interacting with cat.\n";
			}
			
			void makeSound(Animal* animal) 
			{
				std::cout<<"\nAnimal interacting with dog.\n";
			}
			
	};
	class Cat: public Animal
	{
		public:
			~Cat()=default;
			void makeSound(Dog* dog) override
			{
				std::cout<<"\nCat interacting with dog.\n";
			}
			void makeSound(Cat* cat) override
			{
				std::cout<<"\nCat interacting with cat.\n";
			}
			void makeSound(Animal* animal) 
			{
				std::cout<<"\nAnimal interacting with cat.\n";
			}
			
	};
}


int main(){
	my::Animal* dog = new my::Dog();
	my::Animal* cat = new my::Cat();
	dog->makeSound(cat);
	dog->makeSound(dog);
	delete dog;
	delete cat;
}


class BronzeCreditCard;
class SilverCreditCard;
class IOfferVisitor;
class ICreditCard
{
	public:
		virtual ~ICreditCard()=default;
		virtual void accept(std::shared_ptr<IOfferVisitor> ) = 0;
		virtual std::string getCreditCardName() = 0;
};

class IOfferVisitor
{
	public:
		virtual ~IOfferVisitor()=default;
		virtual void visit(BronzeCreditCard* card) = 0;
		virtual void visit(SilverCreditCard* card) = 0;
};

class BronzeCreditCard : public ICreditCard
{
	public:
		void accept(std::shared_ptr<IOfferVisitor> v)
		{
			v->visit(this);
		}
		std::string getCreditCardName()
		{
			return "Bronze Credit Card";
		}
};

class SilverCreditCard : public ICreditCard
{
	public:
		void accept(std::shared_ptr<IOfferVisitor> v)
		{
			v->visit(this);
		}
		std::string getCreditCardName()
		{
			return "Silver Credit Card";
		}
};



class HotelOfferVisitor : public IOfferVisitor
{	
	public:
		void visit(BronzeCreditCard* card) override
		{
			std::cout<<"\n"<<card->getCreditCardName()<<"Have 10% off on booking hotel\n";
		}


		void visit(SilverCreditCard* card) override
		{
			std::cout<<"\n"<<card->getCreditCardName()<<"Have 15% off on booking hotel\n";
		}

};


class FlightOfferVisitor : public IOfferVisitor
{	
	public:
		void visit(BronzeCreditCard* card) override
		{
			std::cout<<"\n"<<card->getCreditCardName()<<"Have 10% off on flight booking on wednesday\n";
		}


		void visit(SilverCreditCard* card) override
		{
			std::cout<<"\n"<<card->getCreditCardName()<<"Have 15% off on flight booking on wednesday\n";
		}

};



void clientCode(std::array<std::shared_ptr<ICreditCard> , 2>& cards, std::shared_ptr<IOfferVisitor> visitor)
{
	for(auto card : cards)
	{
		card->accept(visitor);
	}

}

int main()
{
	std::array<std::shared_ptr<ICreditCard> , 2> cards = \
	{std::make_shared<BronzeCreditCard>(), std::make_shared<SilverCreditCard>()};

	std::shared_ptr<HotelOfferVisitor> hvisitor = std::make_shared< HotelOfferVisitor>();
	clientCode(cards, hvisitor); 

	std::shared_ptr<FlightOfferVisitor>fvisitor = std::make_shared<FlightOfferVisitor>();
	clientCode(cards, fvisitor);
}