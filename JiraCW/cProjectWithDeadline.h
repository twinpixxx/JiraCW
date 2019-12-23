#pragma once
#include "cProject.h"


class cProjectWithDeadline :
	virtual public cProject
{
protected:
	std::string projectStartDate;
	std::string projectEndDate;

public:

	cProjectWithDeadline() {};
	cProjectWithDeadline(std::string projectName, std::string _start, std::string _end, std::string _execFN, std::string _execLN);
	cProjectWithDeadline(const cProjectWithDeadline& tempObject);
	~cProjectWithDeadline() {};


	std::string getStartDate() { return this->projectStartDate; };
	std::string getEndtDate() { return this->projectEndDate; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProjectWithDeadline& tempObj);
	friend std::ostream& operator << (std::ostream& os, cProjectWithDeadline& tempObj);
};

