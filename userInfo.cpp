#include "main.h"
#include "HTML.h"
#include "userInfo.h"

/********************************************
* OpenFiles
* opens the file and if file doesnt open
* error will be thrown
**********************************************/
void OpenFiles(ifstream& in)  // must be passed in by reference
{
	in.open("cosc1337_members.csv");
	if (!in)
	{
		cout << "Input file did not open. Program will exit." << endl;

	}


}


/**************************************************
readFile
reads the data into the class
*****************************************************/
userInfo readFile(string& sLine,           // Pass in by reference to change string in main()
	vector<string>& sParsed, // Pass in by reference to change array in main()
	ifstream& fin)           // Also pass in the input file buffer by ref to read from
{
	getline(fin, sLine);
	stringstream lineStream(sLine);    // A special string class for pre-output formatting
	string field;
	sParsed.clear();                  // Empty the Parsed Line for reuse

	while (getline(lineStream, field, ','))  // While there are fields between the ,
	{
		sParsed.push_back(field);        // Push them onto the string array vector
	}


	//  Fill the data elements of a temporary struct of type Donation 
	//     from the values in the sParsed line
	userInfo tempScholar = { sParsed[0], sParsed[1], sParsed[2],
								sParsed[3], sParsed[4], sParsed[5], sParsed[6], sParsed[7], sParsed[8]
	};

	// Return a copy of the filled tempScholar struct
	return tempScholar;
}