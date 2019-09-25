/*
Team Members:
Suleman Farooqi

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


string loginAccessPath(string currentLoginLine, string usernameEntered, string passwordEntered);
string getStudentLine(string usernameEntered);
string getStudentFirstName(string currentStudentLine);


int main()
{
	string usernameEntered;
	string passwordEntered;
	string studentLine;
	string userFirstName;
	string accessPath = "2";
	
	//types login info
	cout << "Username: " << endl;
	cin >> usernameEntered;
	cout << "Password: " << endl;
	cin >> passwordEntered;

	ifstream loginFile;
	loginFile.open("login.txt");

	string currentLoginLine;
	
	//goes through login file to match username entered
	while (getline(loginFile, currentLoginLine) && accessPath == "2")
	{
		accessPath = loginAccessPath(currentLoginLine, usernameEntered, passwordEntered);
	}

	loginFile.close();

	//gives non-admin mode.
	if (accessPath == "0")
	{
		
		studentLine = getStudentLine(usernameEntered);
		userFirstName = getStudentFirstName(studentLine);
		
	}
	//accesses admin mode.
	else if (accessPath == "1")
	{
		
		cout << "You are admin, " << usernameEntered << endl;
	}
	//denies access
	else if (accessPath == "2")
	{
		cout << "Sorry the username/password is invalid." << endl;
	}
	
	cout << "Welcome to UHD's blackboard, " << userFirstName << endl;

	cout << "Student line: " << studentLine << endl;
	cout << "User's first name: " << userFirstName << endl;
	cout << "Accessd path: " << accessPath << endl;

	return 0;
	
}

//decides if user goes to non-admin/admin mode, or denies access
string loginAccessPath(string currentLoginLine, string usernameEntered, string passwordEntered)
{
	
	string delimiter = "	";
	string currentString;
	string username, password;
	string isAdmin;
	string accessPath;

	bool splitComplete = false;
	
	
	int pos;
	int count = 0;

	while (splitComplete == false)
	{
		pos = currentLoginLine.find(delimiter);

		currentString = currentLoginLine.substr(0, pos);

		if (count == 0)
		{
			username = currentString;
			count += 1;
		}

		else if (count == 1)
		{
			password = currentString;
			count += 1;
		}

		else if (count == 2)
		{
			isAdmin = currentString;

			splitComplete = true;
		}

		currentLoginLine.erase(0, pos + delimiter.length());

	}

	if (usernameEntered == username && passwordEntered == password)
	{
		accessPath = isAdmin;
		
	}
	else
	{
		accessPath = "2";
	}

	return accessPath;
}

//to get the correct line in student file matching username 
string getStudentLine(string usernameEntered)
{
	string currentStudentLine;
	string currentUsernameInLine;
	string delimiter = "	";
	
	int pos;

	ifstream studentFile;
	studentFile.open("student.txt");

	while (getline(studentFile, currentStudentLine) )
	{
		pos = currentStudentLine.find(delimiter);

		currentUsernameInLine = currentStudentLine.substr(0, pos);

		if (usernameEntered == currentUsernameInLine)
		{
			break;
		}

	}

	studentFile.close();

	return currentStudentLine;

}

//to get student first name from their matched line in file
string getStudentFirstName(string currentStudentLine)
{
	string delimiter = "	";
	string currentString;
	string studentFirstName;
	
	bool splitComplete = false;
	int pos;
	int count = 0;

	
	while (splitComplete == false)
	{
		pos = currentStudentLine.find(delimiter);

		currentString = currentStudentLine.substr(0, pos);

		if (count == 1)
		{
			studentFirstName = currentString;
			splitComplete = true;
		}

		currentStudentLine.erase(0, pos + delimiter.length());

		count += 1;

	}

	return studentFirstName;
}
