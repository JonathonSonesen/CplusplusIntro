//Jonathon Sonesen
//Assignment 9
//Sources: None
// A text interface program with menus that will read a library file into to parallel arrays, one with tauthors and the other with titles. 


#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//Constant and arbitrary array size, initialize arrays at file scope
const int ARRAY_SIZE = 1000;
string bookTitle[ARRAY_SIZE];
string bookAuthor[ARRAY_SIZE];

//Function prototypes
int loadData(string pathname);
void showAll(int count);


int main() {
	string filePath;
	
	cout << "Welcome to Jonathon's Library Data Base" << endl;
	cout << "Please enter the pathname to our backup file: ";

	filePath = "C:/Users/PizzaWizard/Downloads/Library.txt";
		
	cout << endl << endl;

	loadData(filePath);

		showAll(loadData(filePath));

		//Pause and exit
		getchar();
		getchar();
		return 0;
}


int loadData(string pathname) {
	//Using algorithm count to find lines with out reading file multiple times
	int linecount = 0;
	ifstream file;

	file.open(pathname.c_str());

	while (!file) {

		cout << "Cannot open the input file." << endl;								//Tell them they failed
		cout << "Please enter the pathname to your encrypted file: ";				//Request the proper pathname
		cin >> pathname;															//Store it
		file.open(pathname.c_str());										//Open it

	}
	
	// Read contents into title array, and author array
	for (int i = 0; !file.eof(); i++)
	{
		getline(file, bookTitle[i]);
		getline(file, bookAuthor[i]);
		linecount++;
	}

	// Close file
	file.close();	
	return linecount;
}

void showAll(int count) {

	cout << "There were " << count << " records succesfully added!" << endl;

	for (int i = 0; i < count; i++) {
		
		cout << bookTitle[i] << " (" << bookAuthor[i] << ")" << endl;
	}

}
