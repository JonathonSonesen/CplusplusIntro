//Jonathon Sonesen
//CS161
//Assignment 3: Simultaneous equation solver
//Sources:None
//User will input two equations into the system which will then print
//out the solutions in a1x + b1y = c1, a2x + b2y = c2 format
//Also it will address infinity situations and parallel lines

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	
	
	//Declare user input variables int for user input float for answers
	int a1, a2, b1, b2, c1, c2;
	double x, y;


	//Welcome them, prmpt them for equation one
	cout << "Welcome to Jonathon's Simultaneous Equation Solver." << endl;
	cout << "Pease enter a1, b1, c1 (seperated by spaces): ";

	//Store equation one
	cin >> a1 >> b1 >> c1;

	//Prompt for equation two
	cout << "Please enter a1, b2, c2 (separated by spaces): ";

	//Store equation two
	cin >> a2 >> b2 >> c2;


	//Obtain x and y values for final output
	x = (double) (c1 * b2 - c2 * b1) / (a1* b2 - a2 * b1);

	y = (double) (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

	//Output values

	//Check that lines are not parrarellel or the same
	if (((a1*b2 - a2*b1) != 0) && ((b1*a2 - b2*a1) != 0))
	{
		cout << a1 << "x + " << b1 << "y = " << c1 << endl;
		cout << a2 << "x + " << b2 << "y = " << c2 << endl;

		cout << setprecision(2) << fixed;

		cout << " is x = " << x << " and  y = " << y << endl;
	}
	else
		if (((a1*b2 - a2*b1) == 0) && ((b1*a2 - b2*a1) == 0) && ((c1*b2 - c2*b1) == 0) && ((c1*a2 - c2*a1) == 0)) //Check if the lines are the same
		{
		cout << "Infinitely many solutions are possible, these lines are actually one!" << endl;
		}
		else
			if (((a1*b2 - a2*b1) == 0) && ((b1*a2 - b2*a1) == 0) && ((c1*b2 - c2*b1) != 0) && ((c1*a2 - c2*a1) != 0)) //check if lines are parralel
				//tell the user the lines are parallel
				cout << "No solutions are possible, these lines run parallel!" << endl;


	cout << "Thanks for using Jonathon's Simultaneous Equation Solver.";



	//pause & exit
	getchar();
	getchar();
	return 0;

}
