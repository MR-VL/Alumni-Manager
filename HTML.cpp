#include "main.h"
#include "HTML.h"
#include "userInfo.h"
/************************************
printRaports
Overloaded print raports function
used for the third report, 
it sends the data to be printed
**********************************/
void printRaports(int found, string tableadd[500][9], vector<string> headers) {
	HTMLTable hTable;
	int x = 0;
	//sends headers to be printed
	hTable.setHeaders(headers);
	//small vector used to send data to be printed
	vector <string> tablee;
	while (x < found) {

		//creates a vector with the information of one record
		tablee.push_back(tableadd[x][0]);
		tablee.push_back(tableadd[x][1]);
		tablee.push_back(tableadd[x][2]);
		tablee.push_back(tableadd[x][3]);
		tablee.push_back(tableadd[x][4]);
		tablee.push_back(tableadd[x][5]);
		tablee.push_back(tableadd[x][6]);
		tablee.push_back(tableadd[x][7]);
		tablee.push_back(tableadd[x][8]);

		//prints the vector line of data
		hTable.addRow(tablee);
		//clears the vector
		tablee.clear();
		//goes to next data value
		x++;
	}//end print loop



	//gets the name that user wants and makes the file

	string outputFileName;
	cout << "What would you like the output file to be named : ";
	cin >> outputFileName;
	//ands the html to the file.
	outputFileName.append(".html");

	//sends the html table to be printed
	ofstream outFilee(outputFileName);
	outFilee << hTable;
	//close file
	outFilee.close();
	//tells the user that file has been created and where it is locateed
	cout << "\n\nOutput file: \" " << outputFileName << "\" Successfully created.\nThe newly created file should be in the same folder as this program\n\n\n\n";
}//end print raports

/************************************
printRaports
sends the data to be created
into an html table
**********************************/
void printRaports(int fileSize, vector <userInfo> s, vector <string> headers) {

	HTMLTable hTable;
	int x = 0;
	//set headers
	hTable.setHeaders(headers);
	while (x < fileSize) {
		//create vecotr that will be sent to the html table print
		vector <string> tableadd{ s[x].lastName, s[x].firstName, s[x].companyName, s[x].address, s[x].city, s[x].state,s[x].zipCode, s[x].phone, s[x].emailAddress };
		hTable.addRow(tableadd);
		//clear vector
		tableadd.clear();
		//goes to next value
		x++;
	}


	//creates and prints the html table to the file named of user choosing
	//for more info see overloaded printreports located above

	string outputFileName;
	cout << "What would you like the output file to be named (Do not use spaces in name) : ";
	cin >> outputFileName;
	outputFileName.append(".html");

	//prints file
	ofstream outFilee(outputFileName);
	outFilee << hTable;
	outFilee.close();


	//tells user file has been made and where it is located
	cout << "\n\nOutput file: \" " << outputFileName << "\" Successfully created.\nThe newly created file should be in the same folder as this program\n\n\n\n";

}//end print reports


//************************************************************
// Writes a row of the table, using the given tag for the    *
// table data. The tag may be td for table data or th for    *
// table header.                                             *
//************************************************************
void HTMLTable::writeRow(ostream& out, string tag, vector<string> row)
{

	out << "<tr>\n";
	for (unsigned int k = 0; k < headers.size(); k++)
	{
		out << "<" << tag << "> "
			<< row[k] << " </" << tag << "> ";
	}
	out << "\n</tr>\n";
}

//******************************************************
// Overloaded stream output operator <<                *
ostream& operator << (ostream& out, HTMLTable htmlTable)
{
	out << "<table border = \"1\">\n";

	// Write the headers
	htmlTable.writeRow(out, "th", htmlTable.headers);

	// Write the rows of the table
	for (unsigned int r = 0; r < htmlTable.rows.size(); r++)
	{
		htmlTable.writeRow(out, "td", htmlTable.rows[r]);
	}
	// Write end tag for table
	out << "</table>\n";
	return out;
}
