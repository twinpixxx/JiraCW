#include <iostream>
using namespace std;

class cException {
protected:
	int errorCode;
	cException(int number) : errorCode(number) {}
public:
	cException() { };
	virtual void ErrorText() {};
};

class inputExceptions : public cException {
public:
	inputExceptions() {};
	inputExceptions(int number) : cException(number) {};
	int inputNumber(long int min, long int max) noexcept(false);
	string inputString();
	string inputDate();
	void ErrorText() override;
};

class listExceptions : public cException
{
public:
	listExceptions() {};
	listExceptions(int number) : cException(number) {};
	void ErrorText() override;
};
