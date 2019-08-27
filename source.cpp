#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream textWrite;
	textWrite.open("Write.txt");
	
	//textWrite << "Test Writing.\n";
	
	textWrite.close();
	//cout << "Program ran successfully, output written in text file..." << endl;
	int q;
	cin >> q;
	return 0;
}
