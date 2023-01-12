#ifndef _Bakery_h
#define _Bakery_h

#include "Date.h"
#include"Cake.h"
#include"BirthdayCake.h"
#include"MousseCake.h"

class Bakery
{
	char* bakeryName;
	Date estDate;
	int maxCakes;
	Cake** cakeArray;
public:
	Bakery(const char* _bakeryName, Date _estDate, int _maxCakes);
	Bakery(const Bakery& BakeryToCopy);
	const Bakery& operator=(const Bakery& BakeryToCopy);
	~Bakery();
	void chooseCake(const double maxPrice);
	void deleteCake(const int cakeIndex);
	void addCake(const Cake* cakeToAdd);
	void deleteExpired(const Date dateToDelete);
	friend ostream& operator<<(ostream& out, const Bakery& printBakery);
};

#endif
