//Jonathon Sonesen
//Assignment 4 BC Ferries
//Sources: None
//A Program that will have a basic dialogue with you and then based on your answers to the dialogue will respond with the total due
//Additionally, it will print the results in the form of a table that as a receipt (i hope)

#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>

using namespace std;

int main() {

	//variables for cost calculator
	double adults = 0, children = 0, price = 0, surcharge = 0, vehLength = 0;

	char vehicle, isTall;

	//variable for table receipt
	double change, finalprice = 0, amountGiven;
	int twenties, tens, fives, ones, quarters, dimes, nickels, pennies;

	//set precision to 2 decimal places
	cout << fixed << setprecision(2) << showpoint;

	//prompt user with script 
	cout << "Welcome to Jonathon's Fare Calculator" << endl;

	cout << "How many adults (age 12 or over) are in your party?: ";

	cin >> adults;

	cout << "How many children (age 5 - 11) are in your party?: ";
	cin >> children;

	cout << "Are you driving a vehicle on to the ferry (y/n)?: ";
	cin >> vehicle;

	if (vehicle == 'y'){

		//Yes they have a vehicle dialogue branch to get vehicle length and height threshold
		cout << "What is the length of the vehicle in feet?: ";

		cin >> vehLength;

		cout << "Is the vehicle above 7 feet tall (y/n)? ";

		cin >> isTall;

		cout << endl;
	}



	//Price per adult plus surcharge
	price += adults * 13.00;

	surcharge += adults * 1.25;

	//Price per child plus surcharge
	price += children * 6.50;

	surcharge += children * 1.25;

	//If statement for evaluating vehicle cost
	if (vehicle == 'y') {

		if (vehLength >= 20 && isTall == 'y') { //test for length over 20ft and height over 7 feet

			//find difference of length and 20ft threshhold
			vehLength -= 20;

			//Add footage calulation to total price
			price += vehLength * 3.45;

			//Add flat rate cost to price
			price += 69;

			//Add surcharge
			surcharge += 10.40;

		}
		else if (vehLength > 20 && isTall == 'n') { //test for vehicle over 20ft but under height threshhold

			//Find difference of length and threshhold
			vehLength -= 20;

			//Calculate footage price over 20ft and add to price
			price += vehLength * 2.15;

			surcharge += 4.15;

			//Add flat rate to total price
			price += 43;
		}
		else if (vehLength < 20 && isTall == 'n') {   //Test for tolerance on flat rate vehicle cost

			//Add flat rate and surcharge
			price += 43;

			surcharge += 4.15;
		}
	}

	cout << "Your fare is $" << price << " plus a fuel surcharge of $" << surcharge << endl;

	cout << "The total amount payable is $" << price + surcharge << endl << endl;

	finalprice += price + surcharge;

	//Section for recipt transaction
	// prompt and get input
	cout << "Please enter amount given: ";
	cin >> amountGiven;

	cout << endl << endl;


	///Set left justification
	cout << left;

	// compute change and output it
	//  a tenth of a penny added to account for float imprecision
	change = amountGiven - finalprice + .001;

	cout << setw(49) << setfill('*') << '*';
	cout << endl;
	cout << setfill(' ');


	// print a title line
	cout << setw(8) << "* Price |";
	cout << setw(12) << " Surcharge |";
	cout << setw(7) << " Due |";
	cout << setw(12) << " Received |";
	cout << setw(9) << " Change *";
	cout << endl;

	//Fill line

	cout << setw(49) << setfill('*') << '*';
	cout << endl;
	cout << setfill(' ');



	//Final receipt table
	cout << setw(8) << price;
	cout << setw(12) << surcharge;
	cout << setw(7) << price + surcharge;
	cout << setw(12) << amountGiven;
	cout << setw(9) << change;
	cout << endl;

	cout << "Thanks for using Jonathon's Fare Calculator!";



	//pause and exit
	getchar();
	getchar();
	return 0;
}