#pragma once
#include "cList.h"

template <class X>
class File
{
public:
		File() {};
		~File() {};


		void saveFile(List<X> &tmp, const char *file);
		void openFile(List<X> &tmp, const char *file);
};


template <class X>
void File<X>::openFile(List <X> &tmp, const char *file)
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
				_deadline, _description, _exec, _country;
			int _priority;
			in >> _title >> _priority >> _topic
				>> _startDate >> _deadline >> _description
				>> _exec >> _country;
			if (_title == EOFstring) break;
			cInternationalProject tempObj(_title, _topic,
				_startDate, _deadline, _description, _exec, _priority, _country);
			tmp.push_tail(tempObj);
		}
		in.close();
}


template <class X>
void File<X>::saveFile(List <X> &tmp, const char *file)
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
				on << tmp[i].getTitle() << " " << tmp[i].getPriority() << " " << tmp[i].getProjectTopic() << " "
					<< tmp[i].getProjectExecutor() << " " << tmp[i].getProjectStartDate() << " " << tmp[i].getProjectDeadlineDate() << " "
					<< tmp[i].getProjectDescription() << " " << tmp[i].getProjectCountry() << endl;
		}
		on << "EOF";
		on.close();
}