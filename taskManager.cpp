/*
* Personal Organizer
*
* Written by Jonathon Sonesen
* A program to track assignments.
* By due dates, coursename and description
* Text based menu UI
* Search by function
*/

#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;
const int MAX_CHAR = 100;
const int MAX_TASK = 1000;

struct tasks
{
	char course[MAX_CHAR];
	char description[MAX_CHAR];
	char dueDate[MAX_CHAR];

};

int load_DB(tasks toDo[]);
void show_All(tasks toDo[], int listSize);
int menu(tasks toDo[], int listSize);
int add_Task(tasks toDo[], int listSize);
int remove_Task(tasks toDo[], int listSize);
void search_Task(tasks toDo[], int listSize);
void search_ByCourse(tasks toDo[], int listSize);
void search_ByDes(tasks toDo[], int listSize);
void search_ByDate(tasks toDo[], int listSize);
void sort_Course(tasks todo[], int listSize);
void sort_Date(tasks toDO[], int listSize);
void write_DB(tasks toDo[], int listSize);

int main()
{
	tasks toDo[MAX_TASK];
	int listSize = 0;

	listSize = load_DB(toDo);
	show_All(toDo, listSize);
	listSize = menu(toDo, listSize);
	write_DB(toDo, listSize);
	
	cin.get();
	return 0;;
}

int load_DB(tasks todo[])
{
	ifstream fileIn;
	int listSize = 0;
	
	fileIn.open("tasks.txt");
	while (!fileIn)
	{
		cout << "shit is fucked";
	}

	for (int i = 0; !fileIn.eof(); i++)
	{
		fileIn.get(todo[i].course, 100, ';');
		fileIn.ignore(100, ';');
		fileIn.get(todo[i].dueDate, 100, ';');
		fileIn.ignore(100, ';');
	    fileIn.get(todo[i].description, 100, '\n');
		fileIn.ignore(100, '\n');
		listSize++;
	}
	listSize--;
	fileIn.clear();
	fileIn.close();
	cout << "There were " << listSize << " entries found.\n";
	return listSize;
}

void show_All(tasks toDo[], int listSize)
{
	for (int i = 0; i < listSize; i++)
	{
		cout << i + 1 << ".  " << "Course: " << toDo[i].course << "\n" << "Due Date: " << toDo[i].dueDate;
		cout << "\n" << "Description: " << toDo[i].description << "\n\n";
	}
	return;
}

int menu(tasks toDo[], int listSize)
{
	char choice = '\0';
	bool quit = false;

	
	while (!quit)
	{
		cout << "Enter Q to (Q)uit, (A)dd task, (R)emove task, (F)ind task, (S)how all:";
		cin >> choice;
		cin.ignore(100, '\n');
		switch (choice) {
			case 'A':
			case 'a':
				//choice = '\0';
				listSize = add_Task(toDo, listSize);
				show_All(toDo, listSize);
				break;
			case 'R':
			case 'r':
				listSize = remove_Task(toDo, listSize);
				show_All(toDo, listSize);
				choice = '\0';
				break;
			case 'F':
			case 'f':
				search_Task(toDo, listSize);
				choice = '\n';
				break;
			case 'S':
			case 's':
				show_All(toDo, listSize);
				choice = '\0';
				break;
			case 'Q':
			case 'q':
				quit = true;
				break;
			default:
				cout << "Oops! Invalid input, please try again\n";
				choice = '\0';
				break;
		}
	}
	return listSize;
}

int add_Task(tasks toDo[], int listSize)
{
	//
	cout << "Please enter the course name: ";
	cin.get(toDo[listSize].course,MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << '\n';
	cout << "Please enter the due date: ";
	cin.get(toDo[listSize].dueDate, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << '\n';
	cout << "Please enter the description: ";
	cin.get(toDo[listSize].description, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << '\n';

	listSize++;
	cout << listSize;
	return listSize;

}

int remove_Task(tasks toDo[], int listSize)
{
	tasks nullTask;
	int choice;
	int len = 0;
	bool conf = true;
	for (int i = 0; i < MAX_CHAR; i++)
	{
		nullTask.course[i] = '\0';
		nullTask.dueDate[i] = '\0';
		nullTask.description[i] = '\0';
	}
	
	cout << "Please enter the item number you want to remove:";
	cin >> choice;
	cin.ignore(MAX_CHAR, '\n');
	
	//error handling
	while (!cin)
	{
		//clear stream
		cin.clear();
		cin.ignore(100, '\n');
		cout << "You have entered an invalid number please try again: ";
		cin >> choice;
		cin.ignore(MAX_CHAR, '\n');
		len = strlen(toDo[choice - 1].dueDate);
	}
	choice--;									//compensate for array index

	//error handling for illegal selection
	while (choice  > listSize || choice < 0)
	{
		cout << "Oops, that item number is not is the cart!";
		cout << "\nPlease enter the item number that you wish to remove: ";
		cin >> choice;
		cin.ignore(MAX_CHAR, '\n');
	}


	//shift elements of array
	for (int i = choice; i < listSize; i++)
	{
		toDo[i] = toDo[i + 1];
	}
	listSize--;
	return listSize;
}

void search_Task(tasks toDo[], int listSize)
{
	char choice = '\n';

	cout << "How would you like to search? \n";
	cout << "Enter D to Search by (D)ue date, D(e)scription, or (C)ourse:";
	cin >> choice;
	cin.ignore(MAX_CHAR, '\n');
	switch (choice){
	case 'C':
	case 'c':
		search_ByCourse(toDo, listSize);
		break;
	case 'D':
	case 'd':
		search_ByDate(toDo, listSize);
		break;
	case 'E':
	case 'e':
		search_ByDes(toDo, listSize);
		break;
	default:
		cout << "Invalid";
		break;
	}
	return;
}

void search_ByDes(tasks toDo[], int listSize)
{
	//cout << "FUCKL";
	char desc[MAX_CHAR];
	char * pch = '\0';
	
	cout << "\n\nPlease enter the search term:";
	cin.get(desc, MAX_CHAR, '\n');
	
	for (int i = 0; i < listSize; i++)
	{
		pch = strstr(toDo[i].description, desc);
		if (pch != NULL)
		{
			cout << i + 1 << ".  " << "Course: " << toDo[i].course << "\n" << "Due Date: " << toDo[i].dueDate;
			cout << "\n" << "Description: " << toDo[i].description << "\n\n";
		}
	}
	return;
}

void search_ByDate(tasks toDo[], int listSize)
{	
	//cout << "FUCKL";
	char desc[MAX_CHAR];
	char * pch = '\0';

	cout << "\n\nPlease enter the search term:";
	cin.get(desc, MAX_CHAR, '\n');

	for (int i = 0; i < listSize; i++)
	{
		pch = strstr(toDo[i].dueDate, desc);
		if (pch != NULL)
		{
			cout << i + 1 << ".  " << "Course: " << toDo[i].course << "\n" << "Due Date: " << toDo[i].dueDate;
			cout << "\n" << "Description: " << toDo[i].description << "\n\n";
		}
	}
	return;
}

void search_ByCourse(tasks toDo[], int listSize)
{
	//cout << "FUCKL";
	char desc[MAX_CHAR];
	char * pch = '\0';

	cout << "\n\nPlease enter the search term:";
	cin.get(desc, MAX_CHAR, '\n');

	for (int i = 0; i < listSize; i++)
	{
		pch = strstr(toDo[i].course, desc);
		if (pch != NULL)
		{
			cout << i + 1 << ".  " << "Course: " << toDo[i].course << "\n" << "Due Date: " << toDo[i].dueDate;
			cout << "\n" << "Description: " << toDo[i].description << "\n\n";
		}
	}
}

void write_DB(tasks toDo[],int listSize)
{
	ofstream fileOut;
	fileOut.open("tasks.txt", std::ofstream::out | std::ofstream::trunc);
	cout << listSize;
	for (int i = 0; i < listSize; i++)
	{
		fileOut << toDo[i].course << ';' << toDo[i].dueDate << ';' << toDo[i].description << '\n';
	}
	fileOut.close();
	return;
}
