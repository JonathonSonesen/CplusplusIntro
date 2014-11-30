//Jonathon Sonesen
//Assignment 8 Ceasar Cypher Decrypter
//Sources: Kelly Briles
//This program will decrypt a input file that is encrypted using the caesar cypher method. 

#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>

using namespace std;

//Prototypes
void characterCount(ifstream& encryptedIn, char& ch, int list[]);
void findMCLshift(int list[], char& maxChar, int& shift);
void copyDecryptedtext(ifstream& encryptedIn, char& ch, int list[], int shiftAmount);
void doShift(char& ch, int shiftAmount);

int main() {
	//Initialize variables
	int letterCount[26] = {};
	int toShift = 0;
	char MCL = '\0';
	char ch;
	string filepath;
	ifstream encryptedIn;

	cout << "Please enter the pathname to your encrypted file: ";					//Prompt for file path
	cin >> filepath;																//Store	
	encryptedIn.open(filepath.c_str());												//Open file 

	//Error handling
	while (!encryptedIn) {

		cout << "Canot open the input file." << endl;								//Tell them they failed
		cout << "Please enter the pathname to your encrypted file: ";				//Request the proper pathname
		cin >> filepath;															//Store it
		encryptedIn.open(filepath.c_str());											//Open it

	}

	//Read through whole file, counting letters
	while (!encryptedIn.eof()) {

		characterCount(encryptedIn, ch, letterCount);								//Tally character
		encryptedIn.get(ch);														//Grab new line
	}

	//Find the most common letter and calculate it's shift
	findMCLshift(letterCount, MCL, toShift);

	encryptedIn.clear();															//Clear IO stream 
	encryptedIn.seekg(0);															//Set cursor to 0 line
	encryptedIn.get(ch);															//get the first character of the file

	//Read file again
	while (!encryptedIn.eof()) {

		//This time decrypt and print to screen
		copyDecryptedtext(encryptedIn, ch, letterCount, toShift);
		encryptedIn.get(ch);														//Grab newline
	}

	encryptedIn.close();															//Close the file

	//Pause and exit
	getchar();
	getchar();
	return 0;

}

void characterCount(ifstream& encryptedIn, char& ch, int list[]) {

	//Read the whole line
	while (ch != '\n') {
		int index;																	//Variable for letter comparison via array elements
		ch = toupper(ch);															//convert to upper case

		index = static_cast<int>(ch)-static_cast<int>('A');							//find index array  element for corresponding letter

		//if it's a valid index(not a non alphabetical character) 
		if (0 <= index && index < 26) {

			list[index]++;															//add it to list count under its corresponding element
		}

		encryptedIn.get(ch);														//Get the next character
	}
}//end function

void findMCLshift(int list[], char& maxChar, int& shift) {
	//Int max to find the MCL
	int max = 0;

	//Cycle through letter array elements checking for most common letter-ness
	for (int i = 0; i < 26; i++) {

		//Check if MCL
		if (list[i] > max) {

			max = list[i];													//If it is the MCL store the amount of times it occurs in max
			maxChar = static_cast<char>(i + static_cast<int>('A')); 		//Set maxchar to MCL
		}
	}


	cout << endl << "The most common letter in this file is " << maxChar;	//Print out data related to MCL in ase there is a tie for MCLS
	shift = static_cast<int>(maxChar - 'E');								//Calculate shift


	cout << " Which is " << shift << " letters from the letter E";			//Print out shift data so people think you are smart
	cout << endl << endl;
}//end function

void copyDecryptedtext(ifstream& encryptedIn, char& ch, int list[], int shiftAmount) {

	//Process the whole line
	while (ch != '\n') {

		doShift(ch, shiftAmount);										//call doShift
		cout << ch;															//output shifted char
		encryptedIn.get(ch);												//read next char
	}

	cout << ch;																//output the newline char
}//end function

void doShift(char& ch, int shift) {
	//Used to keep track of alphabetical characters
	int index;

	//shift upper case letters
	if (isupper(ch)) {

		index = static_cast<int>(ch - 'A');									//find index array for corresponding letter

		//if it's a valid index(not a non alphabetical character) add it to list count
		if (0 <= index && index < 26) {

			//Cycle through shifts one by one
			for (int i = 0; i < shift; i++) {

				//If incrementing down 1 letter causes a non valid char wrap around to Z
				if (index - 1 < 0) {

					ch = 'Z';											//Set current char to Z					
					i++;												//Compensate for shift
					i = i + index;										//Calculate remaining shifts
					index = static_cast<int>(ch - 'A');					//Reset the index for if statement
				}
				
				ch = static_cast<int>(ch - 1);							//Shift down 1 per i
				index = static_cast<int>(ch - 'A');						//Update index for check
			}
		}
	}  
	
	//If the letter was not upper case then if it's a letter it has to be lower case
	index = static_cast<int>(ch)-static_cast<int>('a');					//Update index for current letter

	//if it's a valid index(not a non alphabetical character) do the shift
	if (0 <= index && index < 26) {

		//Cycle through shift one by one
		for (int i = 0; i < shift; i++) {

			//If incrementing down 1 letter causes a non valid char wrap around to z
			if (index - 1 < 0) {

				ch = 'z';												//Set current char to Z		
				i++;													//Compensate for shift
				i = i + index;											//Calculate remaining shifts
				index = static_cast<int>(ch - 'a');						//Reset the index for if statement
			}

			ch = static_cast<int>(ch - 1);								//Shift down 1 per i
			index = static_cast<int>(ch - 'a');							//Update index for check
		}
	}
}//end function
