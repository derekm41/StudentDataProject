#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;

//defualt Roster class constructor
Roster::Roster() {
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];// this does not create students it only creates the classRosterArray.
	
}

// function defintions


void Roster::parseThenAdd(string studentRow) {
	if (lastIndex < capacity) {
		lastIndex++;
		

		// read student ID
		int rightSide = studentRow.find(",");
		string sID = studentRow.substr(0, rightSide);

		//read student first name
		int leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		string sFirstN = studentRow.substr(leftSide, rightSide - leftSide);

		//read student last name
		leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		string sLastN = studentRow.substr(leftSide, rightSide - leftSide);

		//read student email address
		leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		string sEAddress = studentRow.substr(leftSide, rightSide - leftSide);

		//read student age
		leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		int sAge = stoi(studentRow.substr(leftSide, rightSide - leftSide));

		//read days1 in course
		leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		int sDays1 = stoi(studentRow.substr(leftSide, rightSide - leftSide));

		//read days2 in course
		leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		int sDays2 = stoi(studentRow.substr(leftSide, rightSide - leftSide));

		//read days3 in course
		leftSide = rightSide + 1;
		rightSide = studentRow.find(",", leftSide);
		int sDays3 = stoi(studentRow.substr(leftSide, rightSide - leftSide));
		
		
		DegreeProgram degreeprogram;
		char degreeProg = studentRow.back();
		
		if (degreeProg == 'Y') {
			degreeprogram = DegreeProgram::SECURITY;
		}
		else if (degreeProg == 'K') {
			degreeprogram = DegreeProgram::NETWORK;
		}
		else if (degreeProg == 'E') {
			degreeprogram = DegreeProgram::SOFTWARE;
		} 
		else {
			cout << "did not work"; //debug
		}
		
		add(sID, sFirstN, sLastN, sEAddress, sAge, sDays1, sDays2, sDays3, degreeprogram);
	}
	
	else {
		cout << "Exceeding capacity" << endl;
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	// temp array to hold all 3 days in course.
	int daysInCourses[Student::daysInCourseSize];
	daysInCourses[0] = daysInCourse1;
	daysInCourses[1] = daysInCourse2;
	daysInCourses[2] = daysInCourse3;

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourses, degreeprogram);
}
// remove() function
void Roster::remove(string studentID) {
	int studentIDFound = 0;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) { //find the student id and test is equivelance to the parameter studentID
			studentIDFound = 1;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex-1];
			this->classRosterArray[i+1] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	} if (studentIDFound == 0) {
		cout << "The student with ID: A3 was not found." << endl;
	}
}
//printAll will iterate through all the students and run the Print() function on them. The Print() function in student.cpp is formated per assignment rubric. 
void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; ++i) {
		this->classRosterArray[i]->Print();
	}
}

//printAverageDaysInCourse() function
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= this->lastIndex; ++i) {
		string stuID = this->classRosterArray[i]->GetStudentID();
		if (stuID == studentID) {
			int* numD = classRosterArray[i]->GetNumDaysInCourse();//study this pointer
			cout << "Student ID: " << studentID << ", averages " << (numD[0] + numD[1] + numD[2]) / 3 << " days in a course." << endl;
		}
		
	}
}

// find and print invalid emails
void Roster::printInvalidEmails() {
	for (int i = 0; i <= this->lastIndex; ++i) {
		string email = this->classRosterArray[i]->GetEmailAddress();
		char period = '.';
		char at = '@';
		char space = ' ';
		size_t at1 = email.find(at);
		size_t period1 = email.find(period);
		size_t space1 = email.find(space);
		if (at1 == string::npos) {
			cout << email << " - missing an @ symbol." << endl;
		}
			if (period1 == string::npos) {
				cout << email << " - missing a period." << endl;
		}
			if (space1 != string::npos) {
				cout << email << " - no spaces allowed." << endl;
			}
		}
	}

void Roster::printByDegreeProgram(DegreeProgram degProgram) {

	for (int i = 0; i <= this->lastIndex; ++i) {
		if(this->classRosterArray[i]->GetDegreeProgram() == degProgram){
			this->classRosterArray[i]->Print();
		}
	}
}
Roster::~Roster() {
	for (int i = 0; i < this->lastIndex; ++i) {
		delete this->classRosterArray[i];
	} delete this;
}
