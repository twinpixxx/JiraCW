#pragma once
#include "cProject.h"
#include "cCountry.h"


class cInternationalProject :
	virtual public cProject
{
protected:
	cCountry country;
public:

	cInternationalProject() {};
	cInternationalProject(std::string projectName, cCountry _country, cCompanyEmployee _exec);
	cInternationalProject(const cInternationalProject& tempObject);
	~cInternationalProject() {};


	std::string getCountryName() { return this->country.getCountryName(); };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cInternationalProject& tempObj);
	friend std::ostream& operator << (std::ostream& os, cInternationalProject& tempObj);
};

