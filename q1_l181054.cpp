// lab4.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#include "cricketteam.h"
#include<fstream>



int main()
{
	string name;
	int score1;
	cricketTeam t5("file.txt");//constructor for file reading
	cout << "Enter name" << endl;
	cin >> name;
	t5.inputTeamMember(name);
	cout << "Enter score" << endl;
	cin >> score1;
	t5.inputScore(score1);
	t5.printLatest();
	t5.printInformation();
	string name1;

	return 0;
	system("Pause");
}


