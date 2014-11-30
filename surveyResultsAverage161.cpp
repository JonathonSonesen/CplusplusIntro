//Jonathon Sonesen
//Assignment5
//Sources:None
//A program that takes the results of a survey and processes the averages  to prompt the user to enter the full pathname to the data file on disk. If the file does not exist in
//the specified location, your program should exit with a suitable error message. output to the screen a copy of the data read in from the disk file.Average score for subjects under 18 who have not seen the ad.
//Average score for subjects under 18 who have seen the ad.
//Average score for subjects 18 and over who have not seen the ad.
//Average score for subjects 18 and over who have seen the ad.
//Displayresults to two places of decimals, and automatically list  four calculated 
//averages one to a line, along with a suitable label for each result.
//calculate and display to two places of decimals the overall average score for all of the
//subjects surveyed..

#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;


int main() {
	//Variables
	string filePath, fileOut;
	ifstream results;
	int total = 0, age = 0, score = 0, participants = 0;
	char seenAd;

	//Set to show two decimal places
	cout << fixed << setprecision(2);

	//Prompt user for file path
	cout << "Please enter the *absolute* pathname to your file: ";

	//Store the path name
	cin >> filePath;



	//Open the file
	results.open(filePath.c_str());

	//exit if pathname fails

	if (!results) {

		cout << "Invalid path name";

		//exit program
		getchar();
		getchar();
		return 0;
	}



	//Grab line and print to screen for all the results
	while (!results.eof()){

		getline(results, fileOut);

		cout << fileOut << endl;

	}

	//Clear the iostream, reset cursor
	results.clear();
	results.seekg(0);


	//Average for age < 18 and  seenAd N
	while (!results.eof()) {

		//Grab lines, store in variables to process
		results.ignore(15) >> seenAd;

		results >> age;

		results >> score;




		//If they havent seen the ad and are under 18 add them to average variables
		if (seenAd == 'N' && age < 18) {

			participants++;

			total += score;
		}
	}

	//Calculate and print the average
	cout << "The average among those who are under 18 and di not see the ad are: " << (float)total / participants << endl;

	//Clear IO stream reset cusror to line 0
	results.clear();
	results.seekg(0);

	//Reinitialize variables for next average
	total = 0;
	participants = 0;

	// re read file to average for age < 18 seenAd Y
	while (!results.eof()) {

		results.ignore(15) >> seenAd;

		results >> age;

		results >> score;

		//If they have seen the add and are under 18 at them to average variables to calcuate
		if (seenAd == 'Y' && age < 18) {

			participants++;

			total += score;
		}
	}

	//Calculate and output average
	cout << " The average among those who are under 18 and have seen the ad: " << (float)total / participants << endl;

	//Clear IO reset cursor
	results.clear();
	results.seekg(0);

	//Set to 0
	total = 0;
	participants = 0;


	//reread to get verage for age >= 18 seenAd N
	while (!results.eof()) {

		results.ignore(15) >> seenAd;

		results >> age;

		results >> score;




		//Add to average variable when >= 18 and havent seen ad
		if (seenAd == 'N' && age >= 18) {

			participants++;

			total += score;
		}
	}

	//Calculate and output average
	cout << "The average among those who are over 18 and have not seen the ad is: " << (float)total / participants << endl;

	//clear io set cursor to 0
	results.clear();
	results.seekg(0);

	//Set vars to 0
	total = 0;
	participants = 0;


	//Average for age >= 18 seenAd Y
	while (!results.eof()) {

		results.ignore(15) >> seenAd;

		results >> age;

		results >> score;

		//Average for people who are over 18 and have seen ad
		if (seenAd == 'Y' && age >= 18) {

			participants++;

			total += score;
		}
	}

	//Calucalte and print average
	cout << "The average among those who are 18 or over and have seen the ad is: " << (float)total / participants << endl;

	//clear IO set cursor to 0
	results.clear();
	results.seekg(0);

	//set vars to 0
	total = 0;
	participants = 0;


	//Average fotr everyone
	while (!results.eof()) {

		results.ignore(15) >> seenAd;

		results >> age;

		results >> score;

		participants++;

		total += score;

	}


	cout << "The average average among all the participants is: " << (float)total / participants << endl;

	//clear IO close file
	results.clear();
	results.seekg(0);
	results.close();



	//pause and exit
	getchar();
	getchar();
	return 0;


}