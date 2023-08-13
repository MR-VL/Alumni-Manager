#pragma once
#include "main.h"
#include "HTML.h"

/*user info class that holds all the data*/
struct userInfo
{
	string firstName;
	string lastName;
	string companyName;
	string address;
	string city;
	string state;
	string zipCode;
	string phone;
	string emailAddress;

};

//userInfo class prototypes
void OpenFiles(ifstream& in);
userInfo readFile(string& sLine, vector<string>& sParsed, ifstream& fin);