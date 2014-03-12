/**
@file main.cpp

Created February 27th 2014
*/

#include <iostream>
#include <string>

#include "dicom\DICOM.h"

void sarahSandbox();

/**
 * This is where the magic all starts
 */
int main()
{
	int in;

	cout << "Hello Welcome to Aegle!\n\nWhat would you like to run?" << endl;
	cout << "1. Sarah's Sandbox\n" << endl << endl;
	cin >> in;

	cout << endl;

	switch(in) {
	case 1:
		sarahSandbox();
		break;
	default:
		cout << in << " is not a valid option\n";
		break;
	}

	cin >> in;
}

void sarahSandbox() 
{
	cout << "Hello Welcome to Sarah's Sandbox!" << endl;

	string fileName;
	DICOM d;

	cout << "Please enter the location of a Dicom file" << endl;
	cin.ignore();
	getline(cin, fileName);
	cout << "Attemping to parse: " << fileName << endl;

	d.parseFromFile(fileName);
}