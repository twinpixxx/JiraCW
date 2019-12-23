#pragma once
#include <string>
#include "cCompanyEmployee.h"

class cProject
{
protected:
	std::string projectTitle;
	std::string execFirstName;
	std::string execLastName;
public:
	cProject() {}; //	default constructor without params
	cProject(std::string _title, std::string _execFN, std::string _execLN); //	constructor w/ params
	cProject(const cProject& tempObject); //	copy constructor
	~cProject() {}; //	destructor

	std::string getProjectTitle() { return this->projectTitle; }; //	accessor for projectTitle
	//	accessors for project exec
	std::string getProjectExecFirstName() { return this->execFirstName; };
	std::string getProjectExecLastName() { return this->execLastName; };
	

	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProject& tempObject);
	friend std::ostream& operator << (std::ostream& os, cProject& tempObject);
};

