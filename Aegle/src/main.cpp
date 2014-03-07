/**
@file main.cpp

Created February 27th 2014
*/

#include <iostream>

using namespace std;

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
}