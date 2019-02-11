#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
#include"cricketteam.h";
#include<string>
#include<fstream>

//default construtors
cricketTeam::cricketTeam()
{
	membernames = new string;
	membernames = nullptr;
	no_of_members = -1;
	teamName = new char;
	teamName = NULL;
	Scoreinlast10matches[10] = NULL;
	Rank = -1;
	captain = " ";
}
cricketTeam::cricketTeam(string name, int no_of_members)
{

	char *y = new char[name.length() + 1];
	strcpy(y, name.c_str());
	teamName = y;
	string a;
	membernames = new string[no_of_members + 1];


	for (int j = 0; j < 10; j++)
	{
		Scoreinlast10matches[j]=0;
	}
	Rank = -1;
	cin >> Rank;
	captain = " ";
	cin >> captain;
	cout << captain;
}
cricketTeam::cricketTeam(string filename)
{
	ifstream infile;//to read file
	infile.open("file.txt");
	if (!infile)
	{
		cout << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}
	string temp;
	getline(infile, temp, ':');
	string a;
	infile >> a;
	char *teamName = new char[a.length() + 1];
	strcpy(teamName, a.c_str());

	getline(infile, temp, ':');
	infile >> no_of_members;

	membernames = new string[no_of_members + 1];
	for (int i = 0; i < no_of_members + 1; i++)
	{
		getline(infile, a);
		membernames[i] = a;

	}
	getline(infile, a, ':');
	infile >> Rank;

	getline(infile, temp, ':');
	getline(infile, captain);

	getline(infile, temp, ':');
	char b;
	for (int k = 0; k < 10; k++)
	{
		infile >> Scoreinlast10matches[k];
		infile >> b;
	}

	setTeamName(teamName);
	setcaptain(captain);
	setrank(Rank);
	setno_of_members(no_of_members);
	averagescore(Scoreinlast10matches);
}
//getter setter functions
void cricketTeam::setTeamName(char* name)
{
	teamName = name;
}
char cricketTeam::getTeamName()
{
	return *teamName;
}
void cricketTeam::setcaptain(string name)
{
	captain = name;

}
string cricketTeam::getcaptain()
{
	return captain;
}
void cricketTeam::setrank(int ranking)
{
	Rank = ranking;
}
int cricketTeam::getrank()
{
	return Rank;
}
void  cricketTeam::setno_of_members(int num)
{
	no_of_members = num;
}
int cricketTeam::getno_of_members()
{
	return no_of_members;
}
//input functions
void cricketTeam::inputTeamMember(string name)
{
	if (membernames[no_of_members] != " ")
	{
		cout << "this location is already full and has this name on it :" << " ";
		cout << membernames[no_of_members] << endl;
	}



}
void  cricketTeam::inputScore(int score)
{
	if (Scoreinlast10matches[9] != 0)
	{
		for (int i = 0; i < 10; i++)
		{
			Scoreinlast10matches[i] = Scoreinlast10matches[i + 1];
		}
	}
	Scoreinlast10matches[9] = score;
	for (int h = 0; h < 10; h++)
	{
		cout << Scoreinlast10matches[h] << " ";
	}
	cout << endl;
}
//print functions
int cricketTeam::averagescore(int arr[10])
{
	int avg = 0;
	int sum = 0;
	for (int j = 0; j < 10; j++)
	{
		sum = arr[j] + sum;
	}
	avg = sum / 10;
	cout << "Average score is:" << " " << avg << endl;
	return avg;
}
void cricketTeam::printLatest()
{
	cout << "Latest score of team" << " " << teamName << " " << "is" << " " << Scoreinlast10matches[9] << " " << "in captaincy of" << " " << captain << endl;
}
void cricketTeam::printInformation()
{
	cout << "Name of team:" << " " << teamName << endl;
	cout << "Total team members" << " " << no_of_members << endl;
	for (int i = 0; i < no_of_members + 1; i++)
	{
		cout << membernames[i] << endl;
	}
	cout << "Rank of Team:" << " " << Rank << endl;
	cout << "Name of captain:" << " " << captain << endl;
	cout << "Scores in laast 10 matches with updates" << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << Scoreinlast10matches[k] << " ";

	}

}
cricketTeam::~cricketTeam()
{
	for (int i = 0; i < no_of_members; i++)
	{
		delete[i]membernames;
	}

	delete[]teamName;

}