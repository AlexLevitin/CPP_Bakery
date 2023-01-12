#include "MousseCake.h"

MousseCake::MousseCake(Date _expiryDate, const int _diameter, double _height, double _price, Storage _storage, bool _glutenFree, const char* _taste):Cake(_expiryDate, _diameter, _height, _price, _storage, _glutenFree)
{
	this->taste = _strdup(_taste);
	
	cout << "In Mousse Cake(expiryDate, diameter, height, price, storage, glutenFree, taste)" << endl;
}

MousseCake::MousseCake(const MousseCake& cakeToCopy):Cake(cakeToCopy)
{
	this->taste = NULL;
	*this = cakeToCopy;
}

MousseCake& MousseCake::operator=(const MousseCake& cakeToCopy)
{
	if (taste)
		delete[] taste;
	taste = _strdup(cakeToCopy.taste);
	return *this;
}

MousseCake::~MousseCake()
{
	delete[] taste;
	cout << "In ~ Mousse Cake" << endl;
}

void MousseCake::setTaste(const char* _taste)
{
	delete[] taste;
	taste = new char[strlen(_taste) + 1];
	strcpy(taste, _taste);
}

bool MousseCake::operator==(const MousseCake& checkCake) const
{
	if (!((*this).Cake::operator==(checkCake)))
		return false;
	const MousseCake* tempMcake = dynamic_cast <const MousseCake*> (&checkCake);
	return (tempMcake->taste == taste);
}

void MousseCake::operator+=(const double& priceAddition)
{
	price += priceAddition;
}

string MousseCake::showRecip()
{
	string link = "https://www.sugarhero.com/chocolate-raspberry-mousse-cake/";
	return link;
}

void MousseCake::print(ostream& out) const
{
	out << "Taste: " << taste << endl;
}
