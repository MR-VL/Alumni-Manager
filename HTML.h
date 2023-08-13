#pragma once
#include "main.h"
#include "userInfo.h"

/*HTML class that prints the data to html file*/
class HTMLTable
{
private:
	vector<string> headers;
	vector<vector<string>> rows;
	// Helper method for writing an HTML row in a table
	void writeRow(ostream& out, string tag, vector<string> row);
public:
	// Set headers for the table columns
	void setHeaders(vector<string>& headers)
	{
		this->headers = headers;
	}
	// Add rows to the table
	void addRow(const vector<string>& row)
	{
		rows.push_back(row);
	}
	// Write the table into HTML form onto an output stream
	friend ostream& operator << (ostream& out, HTMLTable htmlTable);
};

/*HTML class function prototypes*/
void printRaports(int fileSize, vector <userInfo> s, vector <string> headers);
void printRaports(int found, string tableadd[500][9], vector<string> headers);
