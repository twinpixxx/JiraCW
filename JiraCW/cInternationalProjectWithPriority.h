#pragma once
#include "cInternationalProject.h"
#include "cProjectWithPriority.h"
class cInternationalProjectWithPriority 
	: virtual public cInternationalProject, virtual public cProjectWithPriority
{

public:
	cInternationalProjectWithPriority() {};
	cInternationalProjectWithPriority(std::string projectName, std::string _countryName, int _priority,
		std::string _execFirstName, std::string _execLastName);
	cInternationalProjectWithPriority(const cInternationalProjectWithPriority& tempObject);
	~cInternationalProjectWithPriority() {};


	std::string getCountryName() { return this->country.getCountryName(); };
	int getPriority() { return this->projectPriority; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cInternationalProjectWithPriority& tempObj);
	friend std::ostream& operator << (std::ostream& os, cInternationalProjectWithPriority& tempObj);
};

