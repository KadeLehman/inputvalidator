#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,string> db;

void menu();
void add(string name, string num); //regex
void deleteByName(string name); //regex
void deleteByNum(string num); //regex
void viewList();

int main()
{
	//TODO: ingest file automatically
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


void add(string name, string num) { // REGEX!
	//TODO: name input within while loop
	//TODO: num input with while loop
}

void deleteByName(string name) {}
void deleteByNum(string num) {}
void viewList() {}