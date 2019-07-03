/******************************************************************************
//// File:			Student.cpp
//// Author:		Pete Sripitak

//// Description:	This file gives the full
////				implementation of the class Student.
******************************************************************************/

#include "Student.h"

// default constructor. This is necessary since we define an array 
// of students in the class Roster
Student::Student()
{
	// Initialize empty string
	m_id = "";
	
	// Initialize all the scores
	for (int i = 0; i < CATEGORY_NUM; i++)
	{
		m_score[i] = 0;
	}
}	// End default constructor


//Accessor & mutator of m_id
string Student::getID() const
{
	return m_id;
}	// End getID


//Accessor & mutator of m_id
void Student::setID(string rhs_id)
{
	m_id = rhs_id;
}	// End setID


//Accessor and mutator of m_score
//ScoreType indicates which score you want to access
void Student::changeScore(const ScoreType scoreType, const int rhs_score)
{
	m_score[scoreType] = rhs_score;
}	// End changeScore


//Accessor and mutator of m_score
//ScoreType indicates which score you want to access
int Student::getScore(const ScoreType scoreType) const
{
	return m_score[scoreType];
}	// End getScore

// End of implementation file
