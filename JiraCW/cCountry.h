#pragma once
#include <string>


class cCountry
{
protected:
	std::string countryName;
public:
	cCountry() {};
	cCountry(std::string _name);
	cCountry(const cCountry& tempObj);
	~cCountry() {};


	//	the most relevant getters
	std::string getCountryName() {
		return this->countryName;
	};
	void setCountryName(std::string _name) {
		this->countryName = _name;
	}

	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cCountry& tempObj);
	friend std::ostream& operator << (std::ostream& os, cCountry& tempObj);

	//	= operator overload
	void operator= (const cCountry& tempObj) {
		this->countryName = tempObj.countryName;
	}
};

