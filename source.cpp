#include <iostream>
#include <fstream> //includes Writing and Reading files
using namespace std;

int main()
{
	ofstream textFile;
	textFile.open("Login.txt");//Opens text file called Login.txt
	
	textFile << "Login Information. username and password seperated by tabspace\n"; //text file header
	textFile << "admin	adminpass\n"; //example of username and password
	
	textFile.close();//Closes the text file
	cout << "Program ran successfully, output written in text file..." << endl;
	return 0;
}
