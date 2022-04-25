#include <iostream>
#include <map>
#define MAX_NAME_CHARS 64
#define MAX_NUM_CHARS 32
using namespace std;

map<char*,char*> db;

void menu();
void add(char* name, char* num);
void deleteByName(char* name);
void deleteByNum(char* num);
void viewList();
bool validateName(char* name);
bool validateNum(char* num);

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
				add(name,num);
				break;
			case '2':
				deleteByName(name);
				break;
			case '3':
				deleteByNum(num);
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

void add(char* name, char* num) {
	// use fgets using exam example
	do {
		cout << "Please enter a name." << endl;
		fgets(name,MAX_NAME_CHARS);
		if(validateName(name)) { break; }
	} while(true);
	do {
		cout << "Please enter a phone number." << endl;
		fgets(num,MAX_NUM_CHARS);
		if(validateNum(num)) { break; }
	} while(true);
}

void deleteByName(char* name) {}
void deleteByNum(char* num) {}
void viewList() {}

bool validateName(char* name) {
	regex e("(?!\\s)");
	match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(name,e,f);
	//TODO: print error msg if failed
	//TODO: pass? return true -> breaks from loop.
	return matching;
}

bool validateNum(char* num) {
	regex e("(?!\\s)");
	match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(num,e,f);
	//TODO: print error msg if failed
	//TODO: pass? return true -> breaks from loop.
	return matching;
}
