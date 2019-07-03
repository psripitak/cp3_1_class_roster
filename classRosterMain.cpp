/******************************************************************************
//// File:			classRosterMain.cpp
//// Author:		Pete Sripitak

//// Description: This file provides a way to manage class roster (search only).
******************************************************************************/

#include "Roster.h"

int main()
{
	Roster roster("CSCI3110");	// Roster class object
	char userCommand;			// User's command flag
	string userInputId;			// User's input student ID

	roster.readStudentRecord("point.dat");	// Read file

	// Display User Interface
	cout << "**************************************************************\n"
		 << "* Command       Description                                  *\n"
		 << "* I             Display a student information by an ID       *\n"
		 << "* L             List the entire class                        *\n"
		 << "* Q             Quit the main menu                           *\n"
		 << "**************************************************************\n";
	
	// Read user's input
	cout << "Please enter your command <I, L, Q>: ";
	cin >> userCommand;

	// Loop until the user wants to quit
	while (userCommand != 'q' && userCommand != 'Q')
	{
		// Perform action according to the user's input
		switch (userCommand)
		{
			// Find the specified student record
			case 'i' :
				cout << endl;
				cout << "Please enter the student ID: ";
				cin >> userInputId;
				roster.findStudentRecord(userInputId);
				break;
			case 'I' :
				cout << endl;
				cout << "Please enter the student ID: ";
				cin >> userInputId;
				roster.findStudentRecord(userInputId);
				break;
			// Print the whole roster
			case 'l' :
				cout << endl;
				roster.printStudentRecord();
				break;
			case 'L' :
				cout << endl;
				roster.printStudentRecord();
				break;
		}

		// Prompt message to continue
		cout << endl << endl;
		cout << "Press Enter to continue . . . ";
		cin.sync();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// Read user's input
		cout << endl << "Please enter your command <I, L, Q>: ";
		cin >> userCommand;
	}

	return 0;
}	// End main

// End of client file
