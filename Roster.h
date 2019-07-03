/*
 * File:	Roster.h
 * Author:	Pete Sripitak
 
 * This file gives the full definition 
 * of the class Roster.
 */

#ifndef __CSCI2170_ROSTER__
#define __CSCI2170_ROSTER__

#include <stdexcept>
#include "Student.h"

class Roster
{
	public:
		// constructor, the parameter is the course name
		// Create an empty roster, i.e. m_studentNum = 0 for
		// a specific course
		Roster(std::string courseName);

		// This function reads student information from a file
		// The parameter is a file name
		// post-condition: 
		//		m_students contains student information read from the file
		//		m_studentNum is the number of students read from the file	
		void readStudentRecord( std::string );

		// Description:	Display information of all students in the class.
		// Precondition:	None.
		// Postcondition:	m_id and m_score of all students are printed.
		void printStudentRecord() const;

		// Description:	Display student information for a specified ID.
		// Precondition:	The parameter is an ID string.
		// Postcondition:	m_id and m_score of a specified student are printed.
		void findStudentRecord(string rhs_id) const;

	private:
		static const int	MAX_NUM = 25;	// The maximum # of students of a class
											// Class constant. All objects share the same copy
		std::string			m_courseName;	// THe name of the course
		int					m_studentNum;	// Actual Student #
		Student				m_students[MAX_NUM]; // The array of student objects
};
#endif
