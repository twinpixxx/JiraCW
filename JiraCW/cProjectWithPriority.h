#pragma once
#include "cProject.h"
class cProjectWithPriority :
	virtual public cProject
{
protected:
	int projectPriority;
	//	project priority:
	//	(0-without priority)
	//	(1-low priority)
	//	(2-middle priority)
	//	(2-high priority)
public:

	cProjectWithPriority() {};
	cProjectWithPriority(std::string projectName, int _priority, std::string _execFN, std::string _execLN);
	cProjectWithPriority(const cProjectWithPriority& tempObject);
	~cProjectWithPriority() {};


	int getPriority() { return this->projectPriority; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProjectWithPriority& tempObj);
	friend std::ostream& operator << (std::ostream& os, cProjectWithPriority& tempObj);
};

