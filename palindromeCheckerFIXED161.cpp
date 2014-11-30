//Jonathon Sonesen
//Assignment 7 
//Sources: None
//A program that checks if strings are palindromes but ignores punctuation and spaces


#include<iostream>
#include<string>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>			//Use this for remove and remove if functions to shorten the newString funct


using namespace std;

//Prototype
bool isPalindrome(string str);					//Checks for palindrome-ness
void newString(string& str1);					//formats the string to ignore space, punctuation and capitilazation

int main() {
	//Variable for value parameter
	string check;

	//Pompt user for input
	cout << "Welcome to Jonathons Fancy Pants Palindrome Checker" << endl;	//Wlcome message
	cout << "Please enter a string: ";
	
	//Store input
	getline(cin, check);

	//Make a formatted string
	newString(check);

	//Check for palindrome-ness
	if (isPalindrome(check) != false) {

		//Winning
		cout << "That string is a palindrome give yourself a cookie!";

	}
	else {		//If it didnt return true it has to return false

		//Losing
		cout << "That string is not a palindrome booooo";

	}




	//Pause and exit
	getchar();
	getchar();
	return 0;



}


bool isPalindrome(string str) {

	//Find length of strinf for iteration
	int length = str.length();



	//if the first and last arent the same it is false otherwise we keep checking moving in from the outside characters
	for (int i = 0; i < length / 2; i++)

		if (str[i] != str[length - 1 - i]) {			//Return false condition iterating from outside in
		
		return false;									//Lose
		}


	return true;										//Win
}

void newString(string& str1) {

	//Find length for iteration through string 
	int length = str1.length();

	//Iterate through string and convert characters to lower case
	for (int i = 0; i < length; i++){
	
		str1[i] = tolower(str1[i]);			//conversion to lower for format
	}
	
	//Erase anycharacters that are spaces
	str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());

	//Erase any character that is punctiation
	str1.erase(remove_if(str1.begin(), str1.end(), [](char i){return ispunct(i); }), str1.end());
}