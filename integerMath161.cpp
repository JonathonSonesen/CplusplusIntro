//Jonathon Sonesen
//Lab 8 Program 2 Sum of 100 space seperated integers
//Sources: Kelly Briles
//This program will return the sum of up to 100 space seperated integers

#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main() {
	//Variables to store sum, int 1 and int 2
	int input[100] = {};
	int sum = 0;
	int i = 0;

	//Prompt user for input
	cout << "Welcome to the integer adder please enter up to " << endl << " 100 integers seperated by a space and hit enter do add em up!" << endl;

	//read the next 100 integers into input break when enter is pressed
	while ( cin.peek() != '\n' && i < 100) {
		
		//Store in next array element
		cin >> input[i];
		
		//This increments i to avoid storing more than array allows
		i++;
	}
	//Ignore additional integers if user went over 100
	cin.ignore(100, '\n');
	
	//cycle through the array adding each element to the sum
	for (int i = 0; i < 100; i++) {
		
		sum += input[i];
	}
	
	//Print sum
	cout << sum;
	
	//Pause and exit
	getchar();
	getchar();
	return 0;
}