#include "Cake.h"
#include <iostream>
using namespace std;

Cake::Cake(Date _expiryDate, const int _diameter, double _height, double _price,Storage _storage, bool _glutenFree):expiryDate(Date(_expiryDate)), diameter(_diameter), height(_height), price(_price), storage(_storage), glutenFree(_glutenFree)
{
	cout << "In Cake(expiryDate, diameter, height, price, storage, glutenFree)" << endl;
}

bool Cake::operator==(const Cake& checkCake) const
{
	if (expiryDate == checkCake.expiryDate && diameter == checkCake.diameter && height == checkCake.height && price == checkCake.price && storage == checkCake.storage && glutenFree == checkCake.glutenFree)
		return true;
	else
		return false;
}

void Cake::operator+=(const double& priceAddition) 
{
	price += priceAddition;
}

ostream& operator<<(ostream& out, const Cake& printCake)
{
	out << "Cake:" << endl << "Diameter: " << printCake.diameter << endl << "Height: " << printCake.height << endl << "Price: " << printCake.price << endl << "Expiry Date: " << printCake.expiryDate << endl << "Storage : ";
	if (printCake.glutenFree == 1)
		out << "Fridge" << endl;
	else
		out << "Freezer" << endl; 
	out << "Gluten Free: ";
	if (printCake.glutenFree == 1)
		out << "Yes" << endl;
	else
		out << "No" << endl;
	printCake.print(out);
	return out;
}
