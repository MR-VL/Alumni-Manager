#include "main.h"

int main()
{
	string sFileLine;				 // a string to read in each line of the file
	vector<string> sParsedLine;      // array to hold the parsed line from file
	vector<userInfo> users;    // Create an array of structures
	//gets the number of rows in program, will be use all throughout the program
	int filesize = 0;
	//used to keep program running
	int keepgoing = 5;

	// Open input file
	ifstream fin;


	ifstream file("members.csv");
	string line;
	//counts file contents
	while (getline(file, line))
		filesize++;
	if (filesize != 500)
		filesize = 500;
	file.close();

	//open the file
	OpenFiles(fin);

	//reads data in
	for (int i = 0; i < filesize; i++) {
		// Read a line from the file and push onto end ofusers object array
		users.push_back(readFile(sFileLine, sParsedLine, fin));
	}
	// Definition for table column headers   
	vector<string> headers{ "Last Name", "First Name", "Company" , "Address", "City", "State", "Zip", "Phone" , "Email" };

	//used to keep program running untill user wants to exit
	while (keepgoing == 5) {

		//gives info for reports
		reportInfo();

		//the option choice for what the report the user wants to generate
		int option = 0;
		//gets the user report option
		cout << "\n\nPlease select report you wish to be run from the menu above (0-3):";
		cin >> option;

		//validation
		while (option < 0 || option > 3)
		{
			cout << "ERROR! Invalid menu choice\n";
			cout << "\n\nPlease select report you wish to be run from the menu above (0-3):";
			cin >> option;
		}

		//Selects which option the user chose and performs the required action
		 if (option == 0)
		{
			
			 keepgoing = 0;
		}
		else if (option == 1)
		{
			 reportOne(users, filesize, headers);
		}

		else if (option == 2)
		{
			 reportTwo(users, filesize, headers);
		}

		else if (option == 3)
		{
			reportThree(users, filesize, headers);
		}

	
	}//END OF KEEPGOING LOOP

	cout << "\n\nThe program has successfully ended!\n";


}

/*************************************************************
reportInfo
Displays the different menu options and what each menu
option does.
********************************************************/
void reportInfo() {
	cout << "\n	Cow Town College Alumni Reports Menu" << endl;
	cout << "------------------------------------------------------"<< endl;
	cout << "------------------------------------------------------" << endl;

	cout << "\n1: All Members by Natural Order of Input File." << endl;
	cout << "2: All Members Sorted Ascending by Last Name." << endl;
	cout << "3: Members in One State Only, sorted Ascending by City." << endl;
	cout << "0: Exit the program. " << endl;
}

/************************************************************
reportOne
prints the report with data in original order of input file
*************************************************************/
void reportOne(vector <userInfo> s, int fileSize, vector <string> headers) {
	cout << "\nYou have selected Option 1:\n";
	
	printRaports(fileSize, s, headers);

}//end raport one


/*******************************************************
roportTwo
creates and prints the 2nd report with the data
sorted by last name in ascending order
****************************************************/
void reportTwo(vector <userInfo> s, int fileSize, vector <string> headers){
	cout << "\nYou have selected Option 2:\n";

	//swaps data 
	userInfo temp; 
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < fileSize - 1; count++)
		{
			if (s[count].lastName > s[count + 1].lastName)
			{
				temp = s[count];
				s[count] = s[count + 1];
				s[count + 1] = temp;
				swap = true;
		
				
			}
			
		}
	
		
	} while (swap);
	
	//prints the report
	printRaports(fileSize, s, headers);

}//end report two

/*****************************************
* reportThree
* sorts the data ascending by city, 
* then asks user for what state they want
* to create report for
* 
* sorts the states and creates a
* report of the state with the data in 
* ascending order by city
*******************************************/
void reportThree(vector <userInfo> s, int fileSize, vector <string> headers) {
	cout << "You have selected option 3" << endl;
	string keepGoing = "y";

	//if user entered state wrong they can try again
	while (keepGoing == "y") {
		int x = 0; //used as a subscript to search array
		int counter = 0;
		
		//state user wants
		string state;
		cout << "Enter the abbreviation of a state to search for (ex. TX): " << endl;
		cin >> state;
		//capitalizes the state to prevent erros due ti lowercase / uppercase
		transform(state.begin(), state.end(), state.begin(), ::toupper);
		int found = 0;
		//holds the states and data corresponding with an entry
		string tableadd[500][9];
		

		//sorts the cities into ascending order
		userInfo temp;
		bool swap;

		do
		{
			swap = false;
			for (int count = 0; count < fileSize - 1; count++)
			{
				if (s[count].city > s[count + 1].city)
				{
					temp = s[count];
					s[count] = s[count + 1];
					s[count + 1] = temp;
					swap = true;


				}

			}


		} while (swap);



		// searches the sorted data, and determines if the state
		//of entry matches the user state, if so adds it to the 
		//array to be printed later
		while (x < fileSize)
		{

			if (s[x].state == state)
			{
				
				//adds the data to the array 
				tableadd[found][0] = s[x].lastName;
				tableadd[found][1] = s[x].firstName;
				tableadd[found][2] = s[x].companyName;
				tableadd[found][3] = s[x].address;
				tableadd[found][4] = s[x].city;
				tableadd[found][5] = s[x].state;
				tableadd[found][6] = s[x].zipCode;
				tableadd[found][7] = s[x].phone;
				tableadd[found][8] = s[x].emailAddress;
				
				//increments the number of values held in the tableadd array
				found++;
			}

			x++;	//goes to next value
		}

		//If state is not found
		if (found == 0) {
			cout << "Error State entered does not exist or has no values!" << endl;
			cout << "Would you like to try again? (y/n)";
			string tryAgain;
			cin >> tryAgain;
			//does user want to try again
			while (tryAgain != "y" && tryAgain != "n")
			{
				cout << "Error invalid response." << endl;
				cout << "Would you like to try again? (y/n)";
				cin >> tryAgain;
			}
			//try again
			if (tryAgain == "y") {
				keepGoing = "y";
			}
			//exit report 3
			else { keepGoing = "n"; }
		}

		//used as a filesize indicator when printing reports
		int actualFound = found - 1;

		//prints the report
		printRaports(actualFound, tableadd, headers);


		//if state is found, automatically exit
	 keepGoing = "n"; 

	}//end keepgoing loop

}//end report 3

