//Jonathon Sonesen
//Lab 10 
//Sources: Kelly Briles
//A sort algorithm that tracks time

#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<time.h>


using namespace std;

void init(int arr[10][100000]);
void selectionSort(int arr[], int size);

int main() {
	
	//Declare array for sorintg
	static int arr[10][100000] = { 0 };

	//Initilize the array to be full of random numbers
	init(arr);
	
	//Iterate through rows
	for (int i = 1; i <= 10; i++) {
		
			selectionSort(arr[i - 1], i * 10000);					//sort through columns
	}
	
	//Pause and exit
	getchar();
	getchar();
	return 0;
}

void init(int arr[10][100000]){
	
	srand(time(NULL));											//Initialize srand with time

	//iterate through rows and columns initializing to a random number
	for (int r = 0; r < 10; r++) {		
		
		for (int c = 0; c < 100000; c++){
		
			arr[r][c] = rand();
		}
	}
	return;
}

void selectionSort(int arr[], int size) {
	clock_t t;
	t = clock();
	int first;
	int temp;

	for (int index = 0; index < size; index++) {
		
		first = 0;

		for (int c = 0; c < size; c++) {

			if (arr[c] < arr[first]) {
				first = c;
			}
			temp = arr[first];
			arr[first] = arr[c];
			arr[c] = temp;
		}
		
	}
	

	
	t = clock() - t;
	cout << size << " " << t << endl;
	return;
}