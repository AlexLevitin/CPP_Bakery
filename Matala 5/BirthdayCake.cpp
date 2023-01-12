#include "BirthdayCake.h"

BirthdayCake::BirthdayCake(Date _expiryDate, const int _diameter, double _height, double _price, Storage _storage, bool _glutenFree, const char* _text):Cake(_expiryDate, _diameter, _height, _price, _storage, _glutenFree)
{
	this->text = _strdup(_text);

	cout << "In Birthday Cake(expiryDate, diameter, height, price, storage, glutenFree, text)" << endl;
}

BirthdayCake::BirthdayCake(const BirthdayCake& cakeToCopy):Cake(cakeToCopy)
{
	this->text = NULL;
	*this = cakeToCopy;
}

BirthdayCake& BirthdayCake::operator=(const BirthdayCake& cakeToCopy)
{
	if (text)
		delete[] text;
	text = _strdup(cakeToCopy.text);
	return *this;
}

BirthdayCake::~BirthdayCake()
{
	delete[] text;
	cout << "In ~ Birthday Cake" << endl;

}

void BirthdayCake::setText(const char* _text)
{
	delete[] text;
	text = new char[strlen(_text) + 1];
	strcpy(text, _text);
}

bool BirthdayCake::operator==(const Cake& checkCake) const
{
	if (!((*this).Cake::operator==(checkCake)))
		return false;
	const BirthdayCake* tempBcake = dynamic_cast <const BirthdayCake*> (&checkCake);
	return (tempBcake->text == text);
}

void BirthdayCake::operator+=(const double& priceAddition)
{
	price += priceAddition;
}

string BirthdayCake::showRecip()
{
	string link = "https://www.recipetineats.com/my-very-best-vanilla-cake/";
	return link;
}

void BirthdayCake::print(ostream& out) const
{
	out<< "Text: " << text << endl;
}
