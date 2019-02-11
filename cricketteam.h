#include <iostream>
using namespace std;
#include<string>

class cricketTeam
{
	string* membernames;
	int no_of_members;
	char* teamName;
	int Scoreinlast10matches[10];
	int Rank;
	string captain;
	//constructors
public:
	cricketTeam();
	cricketTeam(string name, int no_of_members);
	cricketTeam(string filename);
	//functions
	//to get captain and set its value
	string getcaptain();
	void setcaptain(string name);
	//to get rank and set its value
	int getrank();
	void setrank(int ranking);
	//to get team name and set its value
	char getTeamName();
	void setTeamName(char* name);
	//to get no. of members and set its value
	int  getno_of_members();
	void setno_of_members(int num);
	//to check if space is available in array else discard it
	void inputTeamMember(string name);
	//to shift array to accomodate new score
	void inputScore(int score);
	//for average score of total 10 scores
	int averagescore(int arr[10]);
	//to print score in latest match and team and captain
	void printLatest();
	//to print info
	void printInformation();
	
	
	//destructor
	~cricketTeam();

};