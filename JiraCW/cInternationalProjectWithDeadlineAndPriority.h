#pragma once
#include "cInternationalProject.h"
#include "cProjectWithDeadline.h"
#include "cProjectWithPriority.h"

class cInternationalProjectWithDeadlineAndPriority
	: virtual public cInternationalProject,
	virtual public cProjectWithDeadline,
	virtual public cProjectWithPriority
{
public:
	
	cInternationalProjectWithDeadlineAndPriority() {};
	cInternationalProjectWithDeadlineAndPriority(std::string projectName, std::string _countryName, std::string _start, std::string _end,
		int _priority, std::string _execFirstName, std::string _execLastName);
	cInternationalProjectWithDeadlineAndPriority(const cInternationalProjectWithDeadlineAndPriority& tempObject);
	~cInternationalProjectWithDeadlineAndPriority() {};



	std::string getEndDate() { return this->projectEndDate; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cInternationalProjectWithDeadlineAndPriority& tempObj);
	friend std::ostream& operator << (std::ostream& os, cInternationalProjectWithDeadlineAndPriority& tempObj);
};

