#pragma once
#include "cProject.h"
class cInternationalProject :
	public cProject
{
protected:
	std::string projectCountry;
public:

	cInternationalProject() {};
	cInternationalProject(std::string _title, std::string _topic, std::string _startDate, std::string _deadline,
		std::string _description, std::string _exec, int _priority, std::string _country);
	cInternationalProject(const cInternationalProject& tempObj);
	~cInternationalProject() {};


	//	the most relevant getters
	std::string getProjectCountry() {
		return this->projectCountry;
	}



	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cInternationalProject& tempProjectObj);
	friend std::ostream& operator << (std::ostream& os, cInternationalProject& tempProjectObj);

};