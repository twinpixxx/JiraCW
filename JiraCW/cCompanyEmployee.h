#pragma once
#include "cHuman.h"


class cCompanyEmployee :
	virtual public cHuman
{
protected:
	std::string companyName;
	std::string position;

public:
	cCompanyEmployee() {};
	cCompanyEmployee(std::string _firstName, std::string _lastName, cCountry _country, std::string _company, std::string _position);
	cCompanyEmployee(const cCompanyEmployee& tempObject);
	~cCompanyEmployee() {};

	std::string getCompanyName() { return this->companyName; };
	std::string getPosition() { return this->position; };


	void setCompanyName(std::string _company) { this->companyName = _company; };
	void setPosition(std::string _position) { this->position = _position; };


	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cCompanyEmployee& tempObject);
	friend std::ostream& operator << (std::ostream& os, cCompanyEmployee& tempObject);

	//	= operator overload
	void operator= (const cCompanyEmployee& tempObject) {
		this->companyName = tempObject.companyName;
		this->position = tempObject.position;
	}

};

