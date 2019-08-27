/*
Team Members:
Suleman Farooqi

*/

#include <iostream>
#include <fstream> //includes Writing and Reading files
using namespace std;

int main()
{
	//Section 1: Reading login information
	ofstream loginFile;
	loginFile.open("login.txt");//Opens text file called Login.txt
	loginFile << "Login Information. username and password seperated by tabspace\n"; //text file header
	loginFile << "admin	adminpass\n"; //example of username and password
	loginFile.close();//Closes the text file
	
	//Section 2: Reading and Writing database systems
	ofstream dataFile;
	dataFile.open("database.txt");
	dataFile.close();
	
	
	cout << "Program ran successfully, output written in text file..." << endl;
	return 0;
}
