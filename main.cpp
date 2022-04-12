#include <iostream>
#include <map>
#define MAX_NAME_CHARS 64
#define MAX_NUM_CHARS 32
using namespace std;

map<char*,char*> db;

void menu();
void add(char* name, char* num); //regex
void deleteByName(char* name); //regex
void deleteByNum(char* num); //regex
void viewList();

int main()
{
	//TODO: ingest file automatically
	char name[MAX_NAME_CHARS];
	char num[MAX_NUM_CHARS];
	char choice = '0';
	do {
		menu();
		cin >> choice;
		switch(choice) {
			case '0': //exit
				break;
			case '1':
				add("","");
				break;
			case '2':
				deleteByName("");
				break;
			case '3':
				deleteByNum("");
				break;
			case '4':
				viewList();
				break;
			default:
				cout << "Invalid menu choice." << endl;
		}
	} while(choice != '0');
	
	return 0;
}

void menu() {
	cout << "Menu" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Add" << endl;
	cout << "2. Delete by Name" << endl;
	cout << "3. Delete by Number" << endl;
	cout << "4. View List" << endl;
	return;
}

void add(char* name, char* num) { // REGEX!
	//TODO: name input within while loop
	// use fgets using exam example
	do {
		break;
	} while(true);
	//TODO: num input with while loop
}

void deleteByName(char* name) {}
void deleteByNum(char* num) {}
void viewList() {}