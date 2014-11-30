//Jonathon Sonesen
//Assignment 7 
//Sources: None
//A program that checks if strings are palindromes but ignores punctuation and spaces


#include<iostream>
#include<string>
#include<stdio.h>
#include<ctype.h>


using namespace std;

//Prototype
bool isPalindrome(string str);
void newString(string& str1);

int main() {
	//Variable for value parameter
	string check;

	//Pompt user for input
	cout << "Welcome to Jonathons Fancy Pants Palindrome Checker" << endl;
	cout << "Please enter a string: ";
	getline(cin, check);


	newString(check);

	//Procerss bool return
	if (isPalindrome(check) != false) {

		cout << "That string is a palindrome give yourself a cookie!";

	}
	else {
		cout << "That string is not a palindrome booooo";

	}




	//Pause and exit
	getchar();
	getchar();
	return 0;



}


bool isPalindrome(string str) {

	//Find length of user string
	int length = str.length();



	//if the first and last arent the same it is false otherwise we keep checking moving in from the outside characters
	for (int i = 0; i < length / 2; i++)

		if (str[i] != str[length - 1 - i]) {
		return false;
		}

	return true;
}

void newString(string& str1){
	int length = str1.length();

	//Convert characters to lower case
	for (int i = 0; i <= length; i++){

		if (isupper(str1[i])) {
			str1[i] = tolower(str1[i]);
		}
		else if (str1[i] = ' ' || !isalnum(i) || ispunct(i)){
			str1.erase(i, 0);

		}
	}

	//Code orignally used from algorithm header file

	/*//Erase anycharacters that are spaces
	str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());

	//Erase anycharacter that is punctiation
	str1.erase(remove_if(str1.begin(), str1.end(), [](char x){return ispunct(x); }), str1.end());
	*/
	return;
}