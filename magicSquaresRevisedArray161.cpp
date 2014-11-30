//Jonathon Sonesen
//Lab 8 Magic Squares with arrays
//Sources: None
//This will check a 4x4 square to see if it is mathmagical using arrays

#include<iostream>
#include<string>

using namespace std;

//Prototype
bool isMagic(int square[][4]);

int main() {
	int magics[4][4] = {};

	//Prompt for user inpt
	cout << "Welcome to Jonathon's Magic Square Checker, please enter a 4x4 square of numbers" << endl;

	//Traverse rows and columns, while storing input to x,y values
	for (int x = 0; x < 4; x++) {

		for (int y = 0; y < 4; y++) {

			cin >> magics[x][y];
		}
	}

	//Check for truthyness of isMagic, respond accordingly
	if (isMagic(magics)) {

		//Truth response
		cout << "You entered a mathmagical square yaaay!";
	}
	else {


		//Non magic false response
		cout << "That square is not magic man";
	}

	//pause and exit
	getchar();
	getchar();
	return 0;
}

bool isMagic(int square[][4]) {

	//magicSum to find what they all; must add to and dummy for comparison
	int magicSum = 0;
	int dummy = 0;

	//Traerse first row and store its sum
	for (int y = 0; y < 4; y++) {

		magicSum += square[0][y];
	}


	//Check for magic sums
	for (int x = 0; x < 4; x++) {

		//Add up rows and columns
		for (int y = 0; y < 4; y++) {

			//Add elements of current row
			dummy += square[x][y];

		}

		//Check if its magic at the end of each row
		if (dummy != magicSum) {

			return false;
		}
		//Reinitialize for the nest row
		dummy = 0;

	}

	//Add top left to bottom right and check
	for (int xy = 0; xy < 4; xy++) {

		//Checking diagnol from top left to bottom is like [3][3], [2][2] etc hence the xy name
		dummy += square[xy][xy];

	}

	//Reinitialize for next cross check
	dummy = 0;


	//Add bottom left to top right
	for (int x = 3; x >= 0; x--) {

		for (int y = 0; y < 4; y++) {

			//Adds current point ten breaks to skip to next one
			dummy += square[x][y];
			break;
		}
	}

	//Check if it's still magic
	if (dummy != magicSum) {

		return false;
	}

	//If it makes it to the end it must be magic!
	return true;
}
