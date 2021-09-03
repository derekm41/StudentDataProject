#include <string>
#include "student.h"
#include "roster.h"

//include both header files
using namespace std;


int main() {
	//Course info function call.
	cout << "C867 - Scripting & Programming Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000769889" << endl;
	cout << "Name: Derek Mclaws" << endl;
	cout << endl;

	const int studentDataSize = 5;

	// Student Table Data
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Derek,Mclaws,dmclaws@wgu.edu,29,100,10,50,SOFTWARE"
	};
	//create roster instance
	Roster* classRoster = new Roster(studentDataSize);

	//parse through studentData and add a student object
	for (int i = 0; i < studentDataSize; ++i) {
		classRoster->parseThenAdd(studentData[i]);
	}
	cout << "DONE." << endl;

	//Print all the students.
	cout << "Displaying all students:" << endl << endl;
	classRoster->printAll();
	cout << endl;

	//print invalid emails.
	cout << "Displaying invalid emails." << endl << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	//Print the average days in the course by student ID
	for (int i = 0; i < studentDataSize; ++i) {
		string ID = classRoster->classRosterArray[i]->GetStudentID();
		classRoster->printAverageDaysInCourse(ID);
	}
	//print students by degree program
	cout << endl;
	cout << "Displaying students in degree program: SOFTWARE" << endl << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << endl;//line
	//Remove a student.
	cout << "Removing student by id: A3" << endl;
	classRoster->remove("A3");
	cout << endl;
	classRoster->printAll();
	cout << endl;
	cout << "Removing A3 again." << endl << endl;
	classRoster->remove("A3");


	cout << "DONE.";
	return 0;
}