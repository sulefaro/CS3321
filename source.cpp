/*
Team Members:
Suleman Farooqi

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//decides if user goes to non-admin/admin mode, or denies access
string loginAccessPath(string currentLoginLine, string usernameEntered, string passwordEntered);
//to get the correct line in student file that matches username 
string getStudentLine(string usernameEntered);
//to get student first name from their matched line in file
string getStudentFirstName(string currentStudentLine);
//to get student last name from their matched line in file
string getStudentLastName(string currentStudentLine);
//to get the correct line in student file that matches username
string getAdminLine(string usernameEntered);
//to get admin first name from their matched line in file
string getAdminFirstName(string currentAdminLine);
//to get admin last name from their matched line in file
string getAdminLastName(string currentAdminLine);



int main()
{
	string usernameEntered;
	string passwordEntered;
	string studentLine;
	string adminLine;
	string studentFirstName;
	string studentLastName;
	string adminFirstName;
	string adminLastName;
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
		studentFirstName = getStudentFirstName(studentLine);
		studentLastName = getStudentLastName(studentLine);
		
		cout << "Welcome to UHD's blackboard (Non-Admin Mode), " << studentFirstName << " " << studentLastName << endl;
		
	}
	//accesses admin mode.
	else if (accessPath == "1")
	{
		adminLine = getAdminLine(usernameEntered);
		adminFirstName = getAdminFirstName(adminLine);
		adminLastName = getAdminLastName(adminLine);
		
		cout << "Welcome to UHD's blackboard (Admin Mode), " << adminFirstName << " " << adminLastName << endl;
	}
	//denies access
	else if (accessPath == "2")
	{
		cout << "Sorry the username/password is invalid." << endl;
	}
	
	return 0;	
}


string loginAccessPath(string currentLoginLine, string usernameEntered, string passwordEntered)
{

	string delimiter = "	";
	string currentString;
	string username, password;
	string isAdmin;
	int accessPath;

	bool splitComplete = false;


	int pos;
	int tabCount = 0;

	while (splitComplete == false)
	{
		pos = currentLoginLine.find(delimiter);

		currentString = currentLoginLine.substr(0, pos);

		if (tabCount == 0)
		{
			username = currentString;
			tabCount += 1;
		}

		else if (tabCount == 1)
		{
			password = currentString;
			tabCount += 1;
		}

		else if (tabCount == 2)
		{
			isAdmin = currentString;

			splitComplete = true;
		}

		currentLoginLine.erase(0, pos + delimiter.length());

	}

	if (usernameEntered == username && passwordEntered == password && isAdmin == "0")
	{
		accessPath = 0;

	}
	else if(usernameEntered == username && passwordEntered == password && isAdmin == "1")
	{
		accessPath = 1;
	}
	else
	{
		accessPath = 2;
	}

	return accessPath;
}

//LOGIN DATABASE
int loginDatabase(string usernameEntered, string passwordEntered)
{
	string currentLoginLine;
	int accessPath = 2;

	ifstream loginFile;
	loginFile.open("login.txt");

	while (getline(loginFile, currentLoginLine) && accessPath == 2)
	{
		accessPath = loginAccessPath(currentLoginLine, usernameEntered, passwordEntered);
	}
	
	return accessPath;
}







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


string getStudentFirstName(string currentStudentLine)
{
	string delimiter = "	";
	string currentString;
	string studentFirstName;
	
	bool splitComplete = false;
	int pos;
	int tabCount = 0;

	
	while (splitComplete == false)
	{
		pos = currentStudentLine.find(delimiter);

		currentString = currentStudentLine.substr(0, pos);

		if (tabCount == 1)
		{
			studentFirstName = currentString;
			splitComplete = true;
		}

		currentStudentLine.erase(0, pos + delimiter.length());

		tabCount += 1;

	}

	return studentFirstName;
}

string getStudentLastName(string currentStudentLine)
{
	string delimiter = "	";
	string currentString;
	string studentLastName;

	bool splitComplete = false;
	int pos;
	int tabCount = 0;


	while (splitComplete == false)
	{
		pos = currentStudentLine.find(delimiter);

		currentString = currentStudentLine.substr(0, pos);

		if (tabCount == 2)
		{
			studentLastName = currentString;
			splitComplete = true;
		}

		currentStudentLine.erase(0, pos + delimiter.length());

		tabCount += 1;

	}

	return studentLastName;
}

string getAdminLine(string usernameEntered)
{
	string currentAdminLine;
	string currentUsernameInLine;
	string delimiter = "	";

	int pos;

	ifstream adminFile;
	adminFile.open("admin.txt");

	while (getline(adminFile, currentAdminLine))
	{
		pos = currentAdminLine.find(delimiter);

		currentUsernameInLine = currentAdminLine.substr(0, pos);

		if (usernameEntered == currentUsernameInLine)
		{
			break;
		}

	}

	adminFile.close();

	return currentAdminLine;

}

string getAdminFirstName(string currentAdminLine)
{
	string delimiter = "	";
	string currentString;
	string adminFirstName;

	bool splitComplete = false;
	int pos;
	int tabCount = 0;


	while (splitComplete == false)
	{
		pos = currentAdminLine.find(delimiter);

		currentString = currentAdminLine.substr(0, pos);

		if (tabCount == 1)
		{
			adminFirstName = currentString;
			splitComplete = true;
		}

		currentAdminLine.erase(0, pos + delimiter.length());

		tabCount += 1;

	}

	return adminFirstName;
}

string getAdminLastName(string currentAdminLine)
{
	string delimiter = "	";
	string currentString;
	string adminLastName;

	bool splitComplete = false;
	int pos;
	int tabCount = 0;


	while (splitComplete == false)
	{
		pos = currentAdminLine.find(delimiter);

		currentString = currentAdminLine.substr(0, pos);

		if (tabCount == 2)
		{
			adminLastName = currentString;
			splitComplete = true;
		}

		currentAdminLine.erase(0, pos + delimiter.length());

		tabCount += 1;

	}

	return adminLastName;
}
