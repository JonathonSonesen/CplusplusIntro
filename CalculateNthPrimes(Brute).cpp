//Jonathon Sonesen
//Assignment 6
//Source: Kelly Briles
//Check for the primality of a number

#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

//Prototype for funstion of isPrime
bool isPrime(int n);


int main(){
	
	//Sart the first number at 2
	int currentCheck = 2;
	int nthPrime = 0;

	//Part One print out the first 100 prime #'s
	while (nthPrime < 100){

		//If its prime increment the nthPrime and print the number
		if (isPrime(currentCheck) != false){

			nthPrime++;

			cout << "Prime #" << nthPrime << " is " << currentCheck << endl;
		}

		//Increment number to be checked by 1
		currentCheck++;
	}


	//Part 2 print out the first 1000000 in increments of a factor of 10
	//reinitialize variables
	currentCheck = 2;
	nthPrime = 0;

	cout << "n:			" << "nth Prime: " << endl;

	//Find the tenth prime
	while (nthPrime < 10){

		//If its prime increment the nthPrime
		if (isPrime(currentCheck) != false){

			nthPrime++;
		}

		//increment number to check primality
		currentCheck++;
	}

	//print in format of assignment
	cout << nthPrime << "				" << currentCheck - 1 << endl;

	//find the 100th prime
	while (nthPrime < 100){

		//If its prime increment the nthPrime
		if (isPrime(currentCheck) != false){

			nthPrime++;
		}

		currentCheck++;
	}

	cout << nthPrime << "				" << currentCheck - 1 << endl;

	//Check for 1000th prime
	while (nthPrime < 1000){

		//If its prime increment the nthPrime
		if (isPrime(currentCheck) != false){

			nthPrime++;
		}

		currentCheck++;
	}

	cout << nthPrime << "				" << currentCheck - 1 << endl;

	//check for 10000th 
	while (nthPrime < 10000){

		//If its prime increment the nthPrime
		if (isPrime(currentCheck) != false){

			nthPrime++;
		}

		currentCheck++;
	}

	cout << nthPrime << "				" << currentCheck - 1 << endl;

	//check for 10000th 
	while (nthPrime < 100000){

		//If its prime increment the nthPrime
		if (isPrime(currentCheck) != false){

			nthPrime++;



		}

		currentCheck++;
	}

	cout << nthPrime << "				" << currentCheck - 1 << endl;
	//check for 10000th 
	while (nthPrime < 1000000){

		//If its prime increment the nthPrime
		if (isPrime(currentCheck) != false){

			nthPrime++;



		}

		currentCheck++;
	}

	cout << nthPrime << "				" << currentCheck - 1 << endl;

	//pause and exit
	getchar();
	getchar();
	return 0;
}

bool isPrime(int n)
{
	//if not 1 and less than 4 we know it is prime
	if (n < 4) {

		return true;
	}


	if (~n & 1) {

		return false;
	}

	//Skip factors of 2 and three, also square the divisor for optimimum primality checking action
	for (int divisor = 3; divisor * divisor <= n; divisor += 2)
	{


		//check if divisor is a factor
		if (n % divisor == 0) return false;
	}

	return true;
}

