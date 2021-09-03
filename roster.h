#include "student.h"
#include <string>
using namespace std;
// Roster Class

class Roster {
public: 
	int lastIndex;//index of last book in repository. How many are currently there
	int capacity;//maximum size of the Roster.
	Student** classRosterArray;//Array of pointers.

//Constructors empty and reg.
	Roster();
	Roster(int capacity);
		
	//functions per assignment
	//define these in correct order
	//string StudID();
	//int GetClassRosterArray();
	void parseThenAdd(string studentRow);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degProgam);
	//destructor
	~Roster();
};


