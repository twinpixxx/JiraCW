#pragma once
#include <string>
#include "cCompanyEmployee.h"

class cProject
{
protected:
	std::string projectTitle;
	cCompanyEmployee executor;
public:
	cProject() {}; //	default constructor without params
	cProject(std::string _title, cCompanyEmployee _exec); //	constructor w/ params
	cProject(const cProject& tempObject); //	copy constructor
	~cProject() {}; //	destructor

	std::string getProjectTitle() { return this->projectTitle; }; //	accessor for projectTitle
	std::string getProjectExecutor() { return this->executor.getFirstName(); }; //	accessor for projectTitle

	

	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProject& tempObject);
	friend std::ostream& operator << (std::ostream& os, cProject& tempObject);
};

