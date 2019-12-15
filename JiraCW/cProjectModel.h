#include <string>
#include <string>

#pragma once

class cProjectModel
{
protected:
	std::string projectTittle;
	//	project priority:
	//	(0-without priority)
	//	(1-low priority)
	//	(2-middle priority)
	//	(2-high priority)
	int projectPriority;
public:
	// constructors and destructor of _base project class
	cProjectModel()
	{
		projectTittle = "Untitled";
		projectPriority = 0;
	};
	cProjectModel(std::string _title, int _priority);
	cProjectModel(const cProjectModel& tempObj);  //	copy constructor
	~cProjectModel() { };
	

	//some getters and setters for title string
	std::string getTitle() { return this->projectTittle; };
	void setTitle(std::string _title) { this->projectTittle = _title; };
	int getPriority() { return this->projectPriority; };
	void setPriority(int _priority) { this->projectPriority = _priority; };




	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProjectModel& tempObj);
	friend std::ostream& operator << (std::ostream& os, cProjectModel& tempObj);
};

