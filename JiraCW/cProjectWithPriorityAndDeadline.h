#pragma once
#include "cProjectWithPriority.h"
#include "cProjectWithDeadline.h"


class cProjectWithPriorityAndDeadline
	: virtual public cProjectWithPriority, virtual public cProjectWithDeadline
{


public:
	cProjectWithPriorityAndDeadline() {};
	cProjectWithPriorityAndDeadline(std::string projectName, int _priority, std::string _start, std::string _end);
	cProjectWithPriorityAndDeadline(const cProjectWithPriorityAndDeadline& tempObject);
	~cProjectWithPriorityAndDeadline() {};


	int getPriority() { return this->projectPriority; };
	std::string getStartDate() { return this->projectStartDate; };
	std::string getEndtDate() { return this->projectEndDate; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProjectWithPriorityAndDeadline& tempObj);
	friend std::ostream& operator << (std::ostream& os, cProjectWithPriorityAndDeadline& tempObj);
};

