//-------------------------------------------------------------------------------------------------------
//
// Name: Smith, Tellon
//
// Course: CS 1063 - Data Structures & ADT, Spring 15, Dr. Stringfellow
//
// Program Assignment : #4 - Problem 1
//
// Due Date: Friday, Mar. 27, 2015, 9AM
//
// Purpose: This program computes the value of f(n) iteratively and recursively and also computes the
//          value of g(n) recursively
//
//-------------------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//Purpose: open streams
//Requires: an output stream
//Returns: an opened output stream
void openFiles(ofstream & outfile);

//Purpose: gets the number of calculations to be performed from the user
//Requires: the user input (numberofCalculations)
//Returns: the number of calculations
void getNumberofCalculations(int & numberofCalulations);

//Purpose: computes f(n) recursively
//Requires: n (the value to compute for), n > 0
//Returns: the result of f(n)
int computeFRecursive(int n);

//Purpose: computes f(n) iteratively
//Requires:  n (the value to compute for), n > 0
//Returns:  the result of f(n)
int computeFIterative(int n);

//Purpose: computes g(n) recursively
//Requires: n (the value to compute for), n >= 0
//Returns:  the result of g(n)
int computeGRecursive(int n);
//
//Purpose: prints the results of the calculations performed 
//Requires: an opened output stream, number of calculations, the values of n, the result of f(n) 
//          recursively, the result of f(n) iteratively, and result of g(n) recursively 
//Returns: console and output file appended with results
void printResults(ofstream & outfile, int numberofCalulations, int n, int fNRec, int fNloop, int gNRec);

//Purpose: prints heading info to outfile
//Requires: an opened output stream
//Returns: output stream with the heading appended to it
void printHeadings(ofstream & outfile);

//Purpose: prints welcome message
//Requires: an opened output stream
//Returns: output stream with the welcome message appended to it
void printWelcomeMessage(ofstream & outfile);

//Purpose: prints exit message
//Requires: an opened output stream 
//Returns: output stream with the exit message appended to it
void printExitMessage(ofstream & outfile);

int main()
{
	ofstream outfile;

	//open streams
	openFiles(outfile);

	printHeadings(outfile);
	printWelcomeMessage(outfile);
	
	int numberofCalulations;
	int fNRec;
	int fNloop;
	int gNRec;

	getNumberofCalculations(numberofCalulations);

	//calculates the values of n and prints the results
	for (int n = 1; n <= numberofCalulations; n++)
	{
		fNRec = computeFRecursive(n);
		fNloop = computeFIterative(n);
		gNRec = computeGRecursive(n-1);
		printResults(outfile, numberofCalulations, n, fNRec, fNloop, gNRec);
	}//end of loop

	printExitMessage(outfile);

	//close files 
	outfile.close();

	system("pause");
	return 0;
}

void openFiles(ofstream & outfile)
{
	char outFileName[40];

	//open output stream
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

void getNumberofCalculations(int & numberofCalulations)
{
	cout << "\nPlease enter the amount of calculations to be performed:" << endl;
	cin >> numberofCalulations;
	
	//ensures the number of calculations is greater than zero
	while (numberofCalulations <= 0)
	{
		cout << "number must be greater than zero..."<< endl;
		cout << "\nPlease enter the amount of calculations to be performed:" << endl;
		cin >> numberofCalulations;
	}
}

int computeFRecursive(int n)
{
	int result = 0;
	
	//base case
	if (n == 1)
	{
		return 1;
	}
	else
	{
		//recursive function call to calculate result
		result = pow(2, (n - 1)) + computeFRecursive(n - 1);
	}
	return result;
}

int computeFIterative(int n)
{
	int temp = 0;
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		temp = pow(2, i);
		result += temp;
	}
	return result;
}

int computeGRecursive(int n)
{
	int result = 0;

	//base case
	if (n == 0)
	{
		return 1;
	}
	else
	{
		//recursive function call to calculate result
		result = (2 * computeGRecursive(n - 1)) + 1;
	}
	return result;
}

void printResults(ofstream & outfile, int numberofCalulations, int n, int fNRec, int fNloop, int gNRec)
{
	//prints column heading once
	if (n == 1)
	{
		cout << "\nResults of calculations form 1 to " << numberofCalulations << endl;
		cout << "n       f(n) rec       f(n) loop       g(n-1)" << endl;
		cout << "---------------------------------------------" << endl;
		//print to outfile
		outfile << "\nResults of calculations form 1 to " << numberofCalulations << endl;
		outfile << "n       f(n) rec       f(n) loop       g(n-1)" << endl;
		outfile << "---------------------------------------------" << endl;
	}

	cout << left << setw(8) << n << setw(15) << fNRec << setw(16) << fNloop << gNRec << endl;
	//print to outfile
	outfile << left << setw(8) << n << setw(15) << fNRec << setw(16) << fNloop << gNRec << endl;
}

void printHeadings(ofstream & outfile)
{
	outfile << "\nName: Tellon Smith" << endl;
	outfile << "Course: CS 1063 - Data Structures & ADT, Spring 15, Dr. Stringfellow" << endl;
	outfile << "Program Assignment: #4 - Problem 1" << endl;
	outfile << "Due Date: Friday, Mar. 27, 2015, 9AM" << endl;
	outfile << "Purpose: This program computes the value of f(n) iteratively and " << endl;
	outfile << "         recursively and also computes the value of g(n) recursively" << endl;
}


void printWelcomeMessage(ofstream & outfile)
{
	cout << "\nWelcome to the Recursive Functions Program!" << endl;
	outfile << "\nWelcome to the Recursive Functions Program!" << endl;
}

void printExitMessage(ofstream & outfile)
{
	cout << "\nThank you for using the Recursive Functions Program... Goodbye!" << endl;
	outfile << "\nThank you for using the Recursive Functions Program... Goodbye!" << endl;
}
