
// A text interface program with menus that will read a library file into to parallel arrays, one with authors and the other with titles. 

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Constant and arbitrary array size, initialize arrays at file scope
const int ARRAY_SIZE = 1000;
string bookTitle[ARRAY_SIZE];
string bookAuthor[ARRAY_SIZE];

// Function prototypes
int loadData(string pathname);
void showAll(int count);
int showBooksByAuthor(int count, string name);
int showBooksByTitle(int count, string title);

int main() {
	//Initialize Variables
	int count = 0;
	char ch = '\0';

	string filePath;
	string name = "\0";
	string title = "\0";
	
	//Prompt user for filename input
	cout << "Welcome to Jonathon's Library Data Base." << endl;
	cout << "Please enter the pathname to our backup file: ";

	cin >> filePath;								//Grab pathname
	cout << endl << endl;							//Make it look pretty
	count = loadData(filePath);						//loadData returns the line line count
	showAll(count);									//Print all the books on record

	//While the user has not entered the quit command 
	//(Prefered nested while loops to automatically return to menu after search is performed)
	while (ch == '\0' && ch != 'Q' && ch != 'q') {

		cout << "Enter Q to (Q)uit, Search (A)uthor, Search (T)itle, (S)how All: ";					//Display options and prompt user
		cin >> ch;																					//Store input
		ch = toupper(ch);																			//Format input

		//Author selection handling
		while (ch == 'A') {

			cout << "Please enter the name of the author you want to search by: ";					//Prompt for author name
			cin >> name;																			//Store name input
			showBooksByAuthor(count, name);															//Run Author search function
			ch = '\0';																				//Go back to menu
		}
		
		//Title response handling
		while (ch == 'T') {

			cout << "Please enter the name of the title you want to search by: ";					//Prompt for title name
			cin >> title;																			//Store title input
			showBooksByTitle(count, title);															//Run title search function
			ch = '\0';																				//Go back to menu
		}

		//Show all response handling
		while (ch == 'S') {

			showAll(count);																			//Redo the showall function
			ch = '\0';																				//Go back to menu
		}
	}
	ch = '\0';

	//Pause and exit
	getchar();
	getchar();
	return 0;
}


int loadData(string pathname) {
	//line count
	int linecount = 0;
	ifstream file;

	file.open(pathname.c_str());

	while (!file) {

		cout << "Cannot open the input file." << endl;								//Tell them they failed
		cout << "Please enter the pathname to your database file: ";				//Request the proper pathname
		cin >> pathname;															//Store it
		file.open(pathname.c_str());												//Open it
	}

	// Read contents into title array, and author array
	for (int i = 0; !file.eof(); i++) {
		getline(file, bookTitle[i]);												//Load title
		getline(file, bookAuthor[i]);												//Load author
		linecount++;																//increment count
	}

	// Close file
	file.close();
	return linecount;
}

void showAll(int count) {
	int found = 0;

	cout << "There were " << count << " records succesfully added!" << endl;		//return number found

	//Print out formatted author and itle info
	for (int i = 0; i < count; i++) {

		cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;				//cout info
		found++;
	}
	
	cout << found << " Records found." << endl;										//tell how many records
}

int showBooksByAuthor(int count, string name) {
	//Incrementing variable and found variable
	int found = 0;
	int i;

	//Iterate through listings
	for (i = 0; i < count; i++) {

		//If the input is found in the string cout the book and author
		if (bookAuthor[i].find(name) != string::npos) {

			cout << bookTitle[i] << " ";										//Cout name of the corresponding author
			cout << " (" << bookAuthor[i] << ")" << endl;						//Cout formatted author name
			found++;															//Increment found var
		}
	}
	
	cout << found << " Records found." << endl;									//tell how many found
	return found;
}

int showBooksByTitle(int count, string title) {
	//Incrementing variable and found variable
	int found = 0;;
	int i;

	//If the input is found in the string cout the book and title
	for (i = 0; i < count; i++) {

		if (bookTitle[i].find(title) != string::npos) {

			cout << bookTitle[i] << " ";										//Cout name of the corresponding title
			cout << " (" << bookTitle[i] << ")" << endl;						//Cout formatted title name
			found++;															//Increment found var
		}
	}
	
	cout << found << " Records found." << endl;									//tell how many found
	return found;
}
