#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
// variables to be used.
	const static int daysInCourseSize = 3;

private:
	string studentID;
	string firstName;
	string lastName; 
	string emailAddress;
	int age;
	int numDaysInCourse[daysInCourseSize];
	DegreeProgram degProgram;

public:
	Student(); //Empty constructor
	
	//student constructor
	Student(string ID, string fName, string lName, string eAddress, int age, int numDays[], DegreeProgram degProgram);//degree program will be found and added in in the roster class

	// Getters for each instance.
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetNumDaysInCourse(); // double check this pointer. I'm not sure how it works. 
	DegreeProgram GetDegreeProgram(); // Also double check this "virtual" not sure if i need it there or not. 
	 

	//Setters for each instance. Question: am I passing the same variable as the constuctor above??
	void SetStudentID(string ID);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmailAddress(string eAddress);
	void SetAge(int age);
	void SetNumDaysInCourse(int* numDays);
	void SetDegreeProgram(DegreeProgram degProgram);

	void Print();

	//a destructor
	~Student();


};