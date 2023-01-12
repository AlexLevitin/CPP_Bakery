#ifndef _BirthdayCake_h
#define _BirthdayCake_h
#include "Date.h"
#include "Cake.h"
#include <iostream>
using namespace std;

class BirthdayCake:public Cake
{
	char* text;
public:
	BirthdayCake(Date _expiryDate, const int _diameter, double _height, double _price, Storage _storage, bool _glutenFree, const char* _text);
	BirthdayCake(const BirthdayCake& cakeToCopy);
	BirthdayCake& operator=(const BirthdayCake& cakeToCopy);
	~BirthdayCake();
	void setText(const char* _text);
	char* getText()const { return text; };
	bool operator ==(const Cake& checkCake)const;
	void operator +=(const double& priceAddition);
	string showRecip();
	void print(ostream& out)const;
};
#endif;

