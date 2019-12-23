#pragma once
#include "cList.h"

template <class X>
class File
{
public:
		File() {};
		~File() {};


		void saveInternationalProjectsFile(List<X> &tmp, const char *file);
		void openInternationalProjectsFile(List<X> &tmp, const char *file);

		void saveInternationalProjectsWithPriorityFile(List<X>& tmp, const char* file);
		void openInternationalProjectsWithPriorityFile(List<X>& tmp, const char* file);

		void saveInternationalProjectsWithDeadlineFile(List<X>& tmp, const char* file);
		void openInternationalProjectsWithDeadlineFile(List<X>& tmp, const char* file);

		void saveInternationalProjectsWithDeadlineAndPriorityFile(List<X>& tmp, const char* file);
		void openInternationalProjectsWithDeadlineAndPriorityFile(List<X>& tmp, const char* file);
};


template <class X>
void File<X>::openInternationalProjectsFile(List <X> &tmp, const char *file)
{
		ifstream in;
		in.open(file, ios::in);
		if (!in.is_open())
		{
			cout << "Невозможно открыть файл!" << endl;
			return;
		}
		while (true)
		{
			std::string EOFstring = "EOF";
			std::string _title, _topic, _startDate,
				_deadline, _execFirstName, _execLastName, _countryName;
			int _priority;
			cCompanyEmployee _exec;
			cCountry _country;
			if (typeid(X) == typeid(cInternationalProject)) {
				in >> _title >> _execFirstName >> _execLastName >>
					_countryName;
				if (_title == EOFstring || _execFirstName == EOFstring || _execLastName == EOFstring || _countryName == EOFstring) break;
				_country.setCountryName(_countryName);
				cInternationalProject tempObj(_title, _country, _execFirstName, _execLastName);
				tmp.pushToTAIL(tempObj);
			}
		}
		in.close();
}


template <class X>
void File<X>::saveInternationalProjectsFile(List <X> &tmp, const char *file)
{
		ofstream on;
		on.open(file, ios::in | ios_base::trunc);
		if (!on.is_open())
		{
				cout << "Невозможно открыть файл!" << endl;
				return;
		}
		for (int i = 0; i<tmp.size(); i++)
		{
			if (typeid(X) == typeid(cInternationalProject)) {
				on << tmp[i].getProjectTitle() << " " << tmp[i].getProjectExecFirstName() << " "
					<< tmp[i].getProjectExecLastName() << " " << tmp[i].getCountryName() << endl;
			}
		}
		on << "EOF";
		on.close();
}


template <class X>
void File<X>::openInternationalProjectsWithPriorityFile(List <X>& tmp, const char* file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		std::string EOFstring = "EOF";
		std::string _title, _topic, _startDate,
			_deadline, _execFirstName, _execLastName, _countryName;
		int _priority;
		if (typeid(X) == typeid(cInternationalProjectWithPriority)) {
			in >> _title >> _execFirstName >> _execLastName >>
				_countryName >> _priority;
			if (_title == EOFstring || _execFirstName == EOFstring || _execLastName == EOFstring || _countryName == EOFstring) break;

			cInternationalProjectWithPriority tempObj(_title, _countryName, _priority, _execFirstName, _execLastName);
			tmp.pushToTAIL(tempObj);
		}
	}
	in.close();
}


template <class X>
void File<X>::saveInternationalProjectsWithPriorityFile(List <X>& tmp, const char* file)
{
	ofstream on;
	on.open(file, ios::in | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{

		if (typeid(X) == typeid(cInternationalProjectWithPriority)) {
			on << tmp[i].getProjectTitle() << " " << tmp[i].getProjectExecFirstName() << " "
				<< tmp[i].getProjectExecLastName() << " " << tmp[i].getCountryName() 
				<< " " << tmp[i].getPriority() << endl;
		}
	}
	on << "EOF";
	on.close();
}



template <class X>
void File<X>::openInternationalProjectsWithDeadlineFile(List <X>& tmp, const char* file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		std::string EOFstring = "EOF";
		std::string _title, _topic, _startDate,
			_deadline, _execFirstName, _execLastName, _countryName;
		int _priority;
		if (typeid(X) == typeid(cInternationalProjectWithDeadline)) {
			in >> _title >> _execFirstName >> _execLastName >>
				_countryName >> _startDate >> _deadline;
			if (_title == EOFstring || _execFirstName == EOFstring || _execLastName == EOFstring || _countryName == EOFstring
				|| _startDate == EOFstring || _deadline == EOFstring) break;

			cInternationalProjectWithDeadline tempObj(_title, _countryName, _startDate, _deadline, _execFirstName, _execLastName);
			tmp.pushToTAIL(tempObj);
		}
	}
	in.close();
}


template <class X>
void File<X>::saveInternationalProjectsWithDeadlineFile(List <X>& tmp, const char* file)
{
	ofstream on;
	on.open(file, ios::in | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{

		if (typeid(X) == typeid(cInternationalProjectWithDeadline)) {
			on << tmp[i].getProjectTitle() << " " << tmp[i].getProjectExecFirstName() << " "
				<< tmp[i].getProjectExecLastName() << " " << tmp[i].getCountryName()
				<< " " << tmp[i].getStartDate() << " " << tmp[i].getEndDate() << endl;
		}
	}
	on << "EOF";
	on.close();
}



template <class X>
void File<X>::openInternationalProjectsWithDeadlineAndPriorityFile(List <X>& tmp, const char* file)
{
	ifstream in;
	in.open(file, ios::in);
	if (!in.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	while (true)
	{
		std::string EOFstring = "EOF";
		std::string _title, _topic, _startDate,
			_deadline, _execFirstName, _execLastName, _countryName;
		int _priority;

		if (typeid(X) == typeid(cInternationalProjectWithDeadlineAndPriority)) {
			in >> _title >> _execFirstName >> _execLastName >>
				_countryName >> _priority >> _startDate >> _deadline;
			if (_title == EOFstring || _execFirstName == EOFstring || _execLastName == EOFstring || _countryName == EOFstring
				|| _startDate == EOFstring || _deadline == EOFstring) break;

			cInternationalProjectWithDeadlineAndPriority tempObj(_title, _countryName,
				_startDate, _deadline, _priority, _execFirstName, _execLastName);
			tmp.pushToTAIL(tempObj);
		}
	}
	in.close();
}


template <class X>
void File<X>::saveInternationalProjectsWithDeadlineAndPriorityFile(List <X>& tmp, const char* file)
{
	ofstream on;
	on.open(file, ios::in | ios_base::trunc);
	if (!on.is_open())
	{
		cout << "Невозможно открыть файл!" << endl;
		return;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		if (typeid(X) == typeid(cInternationalProjectWithDeadlineAndPriority)) {
			on << tmp[i].getProjectTitle() << " " << tmp[i].getProjectExecFirstName() << " "
				<< tmp[i].getProjectExecLastName() << " " << tmp[i].getCountryName() << " " <<
				tmp[i].getPriority() << " " << tmp[i].getStartDate() << " " << tmp[i].getEndDate() << endl;
		}
	}
	on << "EOF";
	on.close();
}