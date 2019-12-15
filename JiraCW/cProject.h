#pragma once
#include "cProjectModel.h"
class cProject :
	public cProjectModel
{
protected:
	//	basic project fiedls
	std::string projectTopic;
	std::string projectStartDate;
	std::string projectDeadlineDate;
	std::string projectDescription;
	std::string projectExecutor;
public:

	cProject() {};
	cProject(std::string _title, std::string _topic, std::string _startDate, std::string _deadline,
		std::string _description, std::string _exec, int _priority);
	cProject(const cProject& tempObj);
	~cProject() {};


	//	the most relevant getters
	std::string getProjectTopic() {
		return this->projectTopic;
	};
	std::string getProjectExecutor() {
		return this->projectExecutor;
	};
	std::string getProjectStartDate() {
		return this->projectStartDate;
	};
	std::string getProjectDeadlineDate() {
		return this->projectDeadlineDate;
	};
	std::string getProjectDescription() {
		return this->projectDescription;
	};



	//	input/output operators overload
	friend std::istream& operator >> (std::istream& is, cProject& tempObj);
	friend std::ostream& operator << (std::ostream& os, cProject& tempObj);
};

