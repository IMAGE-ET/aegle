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

	std::cout << "Hello Welcome to Aegle!\n\nWhat would you like to run?" << std::endl;
	std::cout << "1. Sarah's Sandbox\n" << std::endl << std::endl;
	std::cin >> in;

	std::cout << std::endl;

	switch(in) {
	case 1:
		sarahSandbox();
		break;
	default:
		std::cout << in << " is not a valid option\n";
		break;
	}

	std::cin >> in;
}

void sarahSandbox() 
{
	std::cout << "Hello Welcome to Sarah's Sandbox!" << std::endl;

	std::string fileName;
	DICOM d;
	DICOMParser dp;

	std::cout << "Please enter the location of a Dicom file" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, fileName);
	std::cout << "Attemping to parse: " << fileName << std::endl;

	dp.parse(fileName, &d);
}