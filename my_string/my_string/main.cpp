#include <iostream>
#include <fstream>
#include "mystring.h"

using namespace std;

const int ArSize = 10;
const int MaxLen = 80;
int main()
{
	{
	mystring name;
	ifstream fin;
	fin.open("test.txt");
	cout << "Hi, what's your name?\n";
	fin >> name;

	mystring sayings[ArSize];
	char temp[MaxLen];
	int i;
	for(i=0;i<ArSize;i++){
		fin.get(temp, MaxLen);
		while(fin && fin.get() != '\n')
			continue;
		if(!fin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}

	int total = i;

	if(total > 0){
		cout << "Here are your sayings:\n";
		for(i=0;i<total;i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;
		for(i=1;i<total;i++){
			if(sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if(sayings[i] < sayings[first])
				first = i;
		}
		cout << "Shortest saying:\n" << sayings[shortest] << endl;
		cout << "First saying:\n" << sayings[first] << endl;
		cout << "This program used " << mystring::howmany() << " string objects. Bye!" << endl;
	}else
		cout << "No input! Bye!" <<endl;
	}
}