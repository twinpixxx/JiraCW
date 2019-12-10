#include <string>
#include <string>

#pragma once

class cProjectModel
{
protected:
	std::string projectTittle;
public:
	// constructor and destructor of _base project class
	cProjectModel() { projectTittle = "Untitled"; }
	~cProjectModel() { }
	

	//some getters and setters for title string
	std::string getTitle() { return projectTittle; }
	void setTitle(std::string _title) { this->projectTittle = _title; }
};

