#pragma once
#include <string>
#include "cException.h"
#include "cCountry.h"


class cHuman
{
protected:
	std::string firstName;
	std::string lastName;
	cCountry country;

public:
	cHuman() {};
	cHuman(std::string _firstName, std::string _lastName, cCountry _country);
	cHuman(const cHuman& tempObject);
	~cHuman() {};

	std::string getFirstName() { return this->firstName; };
	std::string getLastName() { return this->lastName; };
	std::string getCountryName() { return this->country.getCountryName(); };

	void setFirstName(std::string _firstName) { this->firstName = _firstName; };
	void setLastName(std::string _lastName) { this->lastName = _lastName; };
	void setCountryName(std::string _countryName) { this->country.setCountryName(_countryName); };



	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cHuman& tempObject);
	friend std::ostream& operator << (std::ostream& os, cHuman& tempObject);

	//	= operator overload
	void operator= (const cHuman& tempObject) {
		this->firstName = tempObject.firstName;
		this->lastName = tempObject.lastName;
		this->country = tempObject.country;
	}

};

