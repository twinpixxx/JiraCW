#pragma once
#include "cInternationalProject.h"
#include "cProjectWithDeadline.h"


class cInternationalProjectWithDeadline
	: virtual public cInternationalProject, virtual public cProjectWithDeadline
{
public:

	cInternationalProjectWithDeadline() {};
	cInternationalProjectWithDeadline(std::string projectName, std::string _countryName, std::string _start, std::string _end);
	cInternationalProjectWithDeadline(const cInternationalProjectWithDeadline& tempObject);
	~cInternationalProjectWithDeadline() {};


	std::string getCountryName() { return this->country.getCountryName(); };
	std::string getStartDate() { return this->projectStartDate; };
	std::string getEndtDate() { return this->projectEndDate; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cInternationalProjectWithDeadline& tempObj);
	friend std::ostream& operator << (std::ostream& os, cInternationalProjectWithDeadline& tempObj);
};

