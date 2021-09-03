#include <iostream>
#include "student.h"
using namespace std;

Student::Student() { //empty constructor for default values.
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	// for loop to set all values of numDaysInCourse array their array index.
	for (int i = 0; i < daysInCourseSize; ++i) {
		this->numDaysInCourse[i] = i;
	}
	this->degProgram = SECURITY;
}
Student::Student(string ID, string fName, string lName, string eAddress, int age, int numDays[], DegreeProgram degProgram)//The student constructor. Degree program will be found and added in roster class.
{
	//using all setters to create the object. 
	SetStudentID(ID);
	SetFirstName(fName);
	SetLastName(lName);
	SetEmailAddress(eAddress);
	SetAge(age);
	SetNumDaysInCourse(numDays);
	SetDegreeProgram(degProgram);
}
// my get function definitions
	
	string Student::GetStudentID() {
		return studentID;
	}
	string Student::GetFirstName() {
		return firstName;
	}
	string Student::GetLastName() {
		return lastName;
	}
	string Student::GetEmailAddress() {
		return emailAddress;
	}
	int Student::GetAge() {
		return age;
	}
	int* Student::GetNumDaysInCourse() {
		return numDaysInCourse;
	} 
	DegreeProgram Student::GetDegreeProgram() {
			return degProgram;
	}
	
	// my setter function definitions
	void Student::SetStudentID(string ID) {
		studentID = ID;
	}
	void Student::SetFirstName(string fName) {
		firstName = fName;
	}
	void Student::SetLastName(string lName) {
		lastName = lName;
	}
	void Student::SetEmailAddress(string eAddress) {
		emailAddress = eAddress;
	}
	void Student::SetAge(int age) {
		this->age = age;
	}
	void Student::SetNumDaysInCourse(int* numDays) {
		for (int i = 0; i < daysInCourseSize; ++i) {
			numDaysInCourse[i] = numDays[i];
		}
	}
	void Student::SetDegreeProgram(DegreeProgram degProgram)	
	{
		this->degProgram = degProgram;
	}
	
	//double check that the tab \t is working correctly.
	void Student::Print() {
		cout << GetStudentID()<< "\t";
		cout << "First Name: " << GetFirstName() << "\t";
		cout << "Last Name: " << GetLastName() << "\t";
		cout <<"Age: " << GetAge() << "\t";
		cout << "daysInCourse: " << "{ " << GetNumDaysInCourse()[0] << ", " << GetNumDaysInCourse()[1] << ", " << GetNumDaysInCourse()[2] << " } \t";
		cout << "Degree Program: " << degreeProgramStrings[GetDegreeProgram()] << endl;
		}
	// destructor for the Student Class

	Student::~Student() {

	}



