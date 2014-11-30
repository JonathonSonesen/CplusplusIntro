//Jonathon Sonesen
//Assignment 2 Magic Square Checker
//Source:
//Prompt a user for a 4x4 square and check if it's magic, this is achieved by 
//adding up all of the rows in the square and then checking them for equality
//as the program determines if the rows are equal or not a bool will then
//be used to either add 1 or 0 to the tally var, once the operation is done if the
//tally adds up to 9 comparisons that show equality, meaning all rows eaqual one another
//it will tell you you have a magic square, if not it will say you dont

#include<stdio.h>
#include<iostream> 
#include<string>

using namespace std;

int main() {
	//Declare variable for 4x4 square
	int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;

	//Declare variables for adding vertical column
	int vert1, vert2, vert3, vert4;

	//Declare variables for adding horizontal column
	int hor1, hor2, hor3, hor4;

	//Declare cross columns
	int crossLeft, crossRight;

	//Tally variable
	int isMagic = 0;

	//Boolean will check equality
	bool mag;



	//Prompt user for magic square
	cout << "Welcome to Jonathon's Magic Square Checker!";
	cout << endl;

	cout << "Please enter you Magic Square:";
	cout << endl;

	//Extract input to the 16 variables
	cin >> m1 >> m2 >> m3 >> m4 >> m5 >> m6 >> m7 >> m8;
	cin >> m9 >> m10 >> m11 >> m12 >> m13 >> m14 >> m15 >> m16;

	//Add up horizontal columns
	hor1 = m1 + m2 + m3 + m4;

	hor2 = m5 + m6 + m7 + m8;

	hor3 = m9 + m10 + m11 + m12;

	hor4 = m13 + m14 + m15 + m16;

	//Add up vertical columns
	vert1 = m1 + m5 + m9 + m13;

	vert2 = m2 + m6 + m10 + m14;

	vert3 = m3 + m7 + m11 + m15;

	vert4 = m4 + m8 + m12 + m16;

	//Add up cross columns
	crossLeft = m1 + m6 + m11 + m16;

	crossRight = m4 + m7 + m10 + m13;

	//Test each row for equality and add value of mag to isMagic tally
	mag = vert1 == vert2;          isMagic += mag;

	mag = vert2 == vert3;          isMagic += mag;

	mag = vert3 == vert4;          isMagic += mag;

	mag = vert4 == hor1;           isMagic += mag;

	mag = hor1 == hor2;            isMagic += mag;

	mag = hor2 == hor3;            isMagic += mag;

	mag = hor3 == hor4;            isMagic += mag;

	mag = hor4 == crossLeft;       isMagic += mag;

	mag = crossLeft == crossRight; isMagic += mag;

	//cout << isMagic << endl;

	//If all the rows are equal isMagic should be 8 if so
	//Print out that the square is magic if not
	//say it isnt magic
	if (isMagic == 9){

		cout << "That square is magic!";

	}
	else {

		cout << "That square is not magic!";

	}

	//pause and exit
	getchar();
	getchar();
	return 0;

}