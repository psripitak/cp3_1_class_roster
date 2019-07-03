/******************************************************************************
//// File:			Roster.cpp
//// Author:		Pete Sripitak

//// Description:	This file gives the full
////				implementation of the class Roster.
******************************************************************************/

#include "Roster.h"

// constructor, the parameter is the course name
// Create an empty roster, i.e. m_studentNum = 0 for
// a specific course
Roster::Roster(string courseName)
{
	m_courseName = courseName;
	m_studentNum = 0;
}	// End constructor


// This function reads student information from a file
// The parameter is a file name
// post-condition: 
//		m_students contains student information read from the file
//		m_studentNum is the number of students read from the file
void Roster::readStudentRecord(string fileName)
{
	ifstream inFile;		// Input file stream
	inFile.open(fileName);	// Open file
	assert(inFile);			// Check file
	
	int tempScore;			// Store a temporary score
	string tempLine;		// Store the temporary resorce file header
	string tempId;			// Store a temporary student ID

	// Get rid of the recorse file header
	getline(inFile, tempLine);

	// Read information for each student
	for (int i = 0; i < MAX_NUM; i++)
	{
		// Read and store student ID
		inFile >> tempId;
		m_students[i].setID(tempId);

		// if not end-of-file
		if (inFile.peek() != EOF)
			m_studentNum++;

		// Read and store student's scores

		inFile >> tempScore;
		m_students[i].changeScore(Student::CLA, tempScore);

		inFile >> tempScore;
		m_students[i].changeScore(Student::OLA, tempScore);

		inFile >> tempScore;
		m_students[i].changeScore(Student::QUIZ, tempScore);

		inFile >> tempScore;
		m_students[i].changeScore(Student::HOMEWORK, tempScore);

		inFile >> tempScore;
		m_students[i].changeScore(Student::EXAM, tempScore);

		inFile >> tempScore;
		m_students[i].changeScore(Student::BONUS, tempScore);
	}
}	// End readStudentRecord


// Description:	Display information of all students in the class.
// Precondition:	None.
// Postcondition:	m_id and m_score of all students are printed.
void Roster::printStudentRecord() const
{
	// Print information of each student
	for (int i = 0; i < m_studentNum; i++)
	{
		cout << "StudentID  ";
		cout << left << setw(9) << m_students[i].getID();
		cout << "CLA:";
		cout << left << setw(4) << m_students[i].getScore(Student::CLA);
		cout << "OLA:";
		cout << left << setw(4) << m_students[i].getScore(Student::OLA);
		cout << "Quiz:";
		cout << left << setw(4) << m_students[i].getScore(Student::QUIZ);
		cout << "Homework:";
		cout << left << setw(4) << m_students[i].getScore(Student::HOMEWORK);
		cout << "Exam:";
		cout << left << setw(4) << m_students[i].getScore(Student::EXAM);
		cout << "Bonus:";
		cout << left << setw(4) << m_students[i].getScore(Student::BONUS);
		cout << endl;
	}
}	// End printStudentRecord


// Description:	Display student information for a specified ID.
// Precondition:	The parameter is an ID string.
// Postcondition:	m_id and m_score of a specified student are printed.
void Roster::findStudentRecord(string rhs_id) const
{
	bool success = false;
	for (int i = 0; i < m_studentNum; i++)
	{
		if (m_students[i].getID() == rhs_id)
		{
			cout << "StudentID  ";
			cout << left << setw(9) << m_students[i].getID();
			cout << "CLA:";
			cout << left << setw(4) << m_students[i].getScore(Student::CLA);
			cout << "OLA:";
			cout << left << setw(4) << m_students[i].getScore(Student::OLA);
			cout << "Quiz:";
			cout << left << setw(4) << m_students[i].getScore(Student::QUIZ);
			cout << "Homework:";
			cout << left << setw(4) << m_students[i].getScore(Student::HOMEWORK);
			cout << "Exam:";
			cout << left << setw(4) << m_students[i].getScore(Student::EXAM);
			cout << "Bonus:";
			cout << left << setw(4) << m_students[i].getScore(Student::BONUS);
			cout << endl;
			success = true;
		}
	}

	// if the student ID is not found
	if (!success)
	{
		cout << "Cannot find the student with ID: " << rhs_id << endl;
	}
}	// End findStudentRecord

// End of implementation file
