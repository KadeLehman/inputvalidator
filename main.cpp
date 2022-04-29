#include <iostream>
#include <regex>
#include <map>
#define MAX_NAME_CHARS 64
#define MAX_NUM_CHARS 32
using namespace std;
using std::regex;

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
		getline(cin,choice);
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

	/*
	cout << "Please enter a name." << endl;
	do {
		fgets(name,MAX_NAME_CHARS);
		if(validateName(name)) { break; }
	} while(true);
	*/
	
	cout << "Please enter a phone number." << endl;
	char numCopy[MAX_NUM_CHARS];
	do {
		getline(cin,num);
		strncpy(numCopy,num,MAX_NUM_CHARS);
		if(validateNum(numCopy)) { break; }
	} while(true);
	// TODO: input into map
	num = numCopy;
	cout << numCopy << endl;
	return;
}

void deleteByName(char* name) {}
void deleteByNum(char* num) {}
void viewList() {}

bool validateName(char* name) {
	regex e("(?!\\s)");
	regex_constants::match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(name,e,f);
	if(!matching) {
		cout << "Invalid name. Please try again." << endl;
	}
	return matching;
}

bool validateNum(char* num) {
	regex e("(?!\\s)\\+?\\(?(?!000|001\\)|555|1[\\.-/ ]?555|1-555)\\d+\\)?(?:[\\.-/ ]?\\d+){1,4}(?:(?:x|ex|ext|xt)?(?:[\\.-/ ]?\\d{1,4})?)?");
	regex_constants::match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(num,e,f);
	if(!matching) {
		cout << "Invalid number. Please try again." << endl;
	}
	return matching;
}
