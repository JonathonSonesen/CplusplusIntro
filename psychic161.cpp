//Jonathon Sonesen
//CS161
//Assignment 1: Jon's Crytal Ball
//Sources:Google, in order to remember the include string for getline
//This will ask you your name and what subject you are studying, then
//provide some insight as to your projected performance this semester

#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main() {
	//Declare strings, name for first question, subject for second
	string name, subject;

	//Greeting
	cout << "Welcome to Jonathon's Crystal Ball!" << endl;

	//First Question
	cout << "What is your name? ";

	//Get input from cin and store it in name
	getline(cin, name);

	//Greet them by name and ask what subject they are studying
	cout << "Hello, " << name << "." << " My name is Jonathon." << endl;
	cout << "What subject are you studying? ";

	//Get the name of their subject and store it in the subject variable	
	getline(cin, subject);

	//Address them by name again and print that they will excel in their subject fo choice	
	cout << "Well, " << name << ", Jonathon's Crystal Ball says you" << endl;
	cout << "will do very well in " << subject << "!" << endl;

	//pause & exit
	getchar();
	return 0;
}
//this was written in vim and compiled on g++ then put on my windows machine and ported for Visual Studio 2013
