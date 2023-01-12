#ifndef _MousseCake_h
#define _MousseCake_h
#include "Date.h"
#include "Cake.h"
#include <iostream>
using namespace std;

class MousseCake:public Cake
{
	char* taste;
public:
	MousseCake(Date _expiryDate, const int _diameter, double _height, double _price, Storage _storage, bool _glutenFree, const char* _taste);
	MousseCake(const MousseCake& cakeToCopy);
	MousseCake& operator=(const MousseCake& cakeToCopy);
	~MousseCake();
	void setTaste(const char* _taste);
	char* getTaste()const { return taste; };
	bool operator ==(const MousseCake& checkCake)const;
	void operator +=(const double& priceAddition);
	string showRecip();
	void print(ostream& out)const;
	

};
#endif;

