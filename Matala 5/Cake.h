#ifndef _Cake_h
#define _Cake_h
#include "Date.h"
#include <iostream>
using namespace std;

enum Storage { fridge = 1, freezer = 2 };

class Cake
{
protected:
	Date expiryDate;
	const int diameter;
	double height;
	double price;
	Storage storage;
	bool glutenFree;

public:
	Cake(Date _expiryDate, const int _diameter, double _height, double _price, Storage _storage, bool _glutenFree);
	bool operator ==(const Cake& checkCake)const;
	void operator +=(const double& priceAddition);
	friend ostream& operator<<(ostream& out, const Cake& printCake);
	virtual string showRecip() = 0;
	virtual void print(ostream& out)const=0;
	friend class Bakery;
	virtual ~Cake() { cout << "In ~ Cake" << endl; }
	
};

#endif;
