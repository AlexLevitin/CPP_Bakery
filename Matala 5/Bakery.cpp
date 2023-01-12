#include "Bakery.h"
#include "Date.h"
#include"Cake.h"
#include"BirthdayCake.h"
#include"MousseCake.h"


Bakery::Bakery(const char* _bakeryName, Date _estDate, int _maxCakes): maxCakes(_maxCakes), estDate(_estDate)
{
	this->bakeryName = new char[strlen(_bakeryName)+1];
	strcpy(this->bakeryName, _bakeryName);
	this->cakeArray = new Cake* [_maxCakes];
	for (int i = 0; i < _maxCakes; i++)
		this->cakeArray[i] = NULL;
	cout << "In Bakery(name, startdate, maxcakes)" << endl;
}

Bakery::Bakery(const Bakery& BakeryToCopy) :Bakery(BakeryToCopy.bakeryName, BakeryToCopy.estDate, BakeryToCopy.maxCakes)
{
	*this = BakeryToCopy;
}

const Bakery& Bakery::operator=( const Bakery& BakeryToCopy)
{
	if (this != &BakeryToCopy)
	{
		for (int i = 0; i < maxCakes; i++)
		{
			if(cakeArray[i]!=NULL)
				delete[] cakeArray[i];
			cakeArray[i] = NULL;
			if(BakeryToCopy.cakeArray[i] != NULL)
				this->addCake(BakeryToCopy.cakeArray[i]);
		}
	}
	return *this;
}

Bakery::~Bakery()
{
	delete[] bakeryName;
	for (int i = 0; i < maxCakes; i++)
		delete[] cakeArray[i];
	delete[] cakeArray;
	cout << "In ~Bakery" << endl;
}

void Bakery::chooseCake(const double maxPrice)
{
	bool flag = 0;
	for (int i = 0; i < maxCakes; i++)
	{
		if (cakeArray[i]->price <= maxPrice)
		{
			cout << *cakeArray[i];
			flag = 1;
		}
	}
	if (!flag)
		cout << "there aren't any cakes for you budget" << endl;
}

void Bakery::deleteCake(const int cakeIndex)
{
	if (cakeIndex > maxCakes)
	{
		cout << "WARNING, index higher than max array size" << endl;
		return;
	}
	if (cakeArray[cakeIndex])
	{
		delete[] cakeArray[cakeIndex];
		cakeArray[cakeIndex] = NULL;
		cout << " Cake was deleted successfully" << endl;
	}
	else
		cout << "Cake wasn't found" << endl;
}

void Bakery::addCake(const Cake* cakeToAdd)
{
	if (cakeToAdd == NULL)
		return;
	for (int i = 0; i < maxCakes; i++)
	{
		if (cakeArray[i] == NULL)
		{
			if (!strcmp(typeid(MousseCake).name(), typeid(*cakeToAdd).name()))
				cakeArray[i] = new MousseCake((MousseCake&)*cakeToAdd);
		
			else
				cakeArray[i] = new BirthdayCake((BirthdayCake&)*cakeToAdd);
			cout << "Cake was added successfully!" << endl<< *cakeArray[i];
            return;
		}
		
	}
	cout << "There wasnt enough room for another cake" << endl;
}

void Bakery::deleteExpired(const Date dateToDelete)
{
	for (int i = 0; i < maxCakes; i++)
		if ( cakeArray[i] != NULL  &&  dateToDelete < cakeArray[i]->expiryDate )
			deleteCake(i);
}

ostream& operator<<(ostream& out, const Bakery& printBakery)
{
	out << "Bakery Name: " << printBakery.bakeryName << endl << "Establishment Date: " << printBakery.estDate << endl << "Max cakes: " << printBakery.maxCakes << endl;
	for (int i = 0; i < printBakery.maxCakes; i++)
	{
		if (printBakery.cakeArray[i])
			out << *(printBakery.cakeArray[i]) << endl;
	}
	
	return out;
}
