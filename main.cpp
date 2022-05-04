#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>
#define MAX_NAME_CHARS 43
#define MAX_NUM_CHARS 24
using namespace std;
using std::regex;

unordered_map<string,string> db;

void menu();
void ingestFile();
void add(string& name, string& num);
void deleteByName(string& name);
void deleteByNum(string& num);
void viewList();
bool validateName(string& name, bool fromFile);
bool validateNum(string& num, bool fromFile);

int main()
{
	// Ingest file and activate menu.
	cout << endl;
	ingestFile();
	string name("");
	string num("");
	string choice_str("");
	char choice = '0';
	do {
		menu();
		getline(cin,choice_str);
		choice = choice_str.front();
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

void ingestFile() {

	// Attempt to open file.
	ifstream ifs("input.txt");
	if(!ifs.is_open()) {
		cout << "No file named \"input.txt\" found." << endl << endl;
		return;
	}
	
	// Ingest file into database.
	char str[256];
	bool nameToken(true);
	bool pairValid(true);
	int lineCounter = 0;
	string name("");
	string num("");
    while (ifs.getline(str, 256)) {
    	
    	lineCounter++;
    
    	// Attempt name input.
    	if(nameToken) {
    		name = str;
			name = name.substr(0,MAX_NAME_CHARS);
			if(!validateName(name,true)) {
				cout << "Line " << lineCounter << " failed." << endl;
				pairValid = false;
			}
			nameToken = !nameToken;
			continue;
		}
		
		// Attempt number input.
		num = str;
		num = num.substr(0,MAX_NUM_CHARS);
		if(!validateNum(num,true)) {
			cout << "Line " << lineCounter << " failed." << endl;
			pairValid = false;
		}
		nameToken = !nameToken;
		
		// If valid, insert pair into database
		if(pairValid) {
			cout << "Lines " << lineCounter-1 << "-" << lineCounter << " passed." << endl;
			db.emplace(name,num);
		}
		pairValid = true;
    }
    
    // Close file.
    if(lineCounter == 0) {
    	cout << "\"input.txt\" is in the project folder, but it is empty." << endl;
    }
    cout << endl;
	ifs.close();
	return;
}

void add(string& name, string& num) {
	
	// Ask user to enter name.
	cout << endl << "Please enter a name." << endl;
	do {
		getline(cin,name);
		name = name.substr(0,MAX_NAME_CHARS);
		if(validateName(name,false)) { break; }
	} while(true);
	
	// Ask user to enter phone number.
	cout << endl << "Please enter a phone number." << endl;
	do {
		getline(cin,num);
		num = num.substr(0,MAX_NUM_CHARS);
		if(validateNum(num,false)) { break; }
	} while(true);
	
	// Insert data into database.
	db.emplace(name,num);
	cout << endl << "Successfully inserted entry." << endl << endl;
	return;
}

void deleteByName(string& name) {

	// Ask user to enter name.
	cout << endl << "Please enter the name for the entry you wish to delete." << endl;
	do {
		getline(cin,name);
		name = name.substr(0,MAX_NAME_CHARS);
		if(validateName(name,false)) { break; }
	} while(true);

	// Delete entry if supplied name is found.
	unordered_map<string,string>::const_iterator got = db.find(name);
	if(got == db.end()) {
		cout << "Name not found. Please enter the name exactly as displayed in the database." << endl << endl;
	}
	else {
		db.erase(name);
		cout << endl << "Successfully deleted entry." << endl << endl;
	}
	return;
}

void deleteByNum(string& num) {

	// Ask user to enter phone number.
	cout << endl << "Please enter the phone number for the entry you wish to delete." << endl;
	do {
		getline(cin,num);
		num = num.substr(0,MAX_NUM_CHARS);
		if(validateNum(num,false)) { break; }
	} while(true);

	// Delete entry if supplied number is found.
	for(auto& entry : db) {
		if(entry.second == num) {
			db.erase(entry.first);
			cout << endl << "Successfully deleted entry." << endl << endl;
			return;
		}
	}
	cout << "Phone number not found. Please enter the phone number exactly as displayed in the database." << endl << endl;
	return;
}

void viewList() {
	// Print database contents.
	if(db.empty()) {
		cout << endl << "The database is empty." << endl << endl;
		return;
	}
	cout << endl << "DATABASE:" << endl << endl;
	for(auto& entry : db) {
		cout << entry.first << "|" << entry.second << endl;
	}
	cout << endl;
	return;
}

bool validateName(string& name, bool fromFile) {
	// Test inputted name against regular expression.
	regex e("(?=.{2,})(?!.{42,})(?!\\s)[a-zA-Z]+(?:,? ?'?-?[a-zA-Z']+,?)(?: ?'?-?[a-zA-Z]+){0,2}");
	regex_constants::match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(name,e,f);
	if(!matching && !fromFile) {
		cout << "Invalid name. Please try again." << endl;
	}
	return matching;
}

bool validateNum(string& num, bool fromFile) {
	// Test inputted number against regular expression.
	regex e("(?=.{7,})(?!.{23,})(?!\\s)\\+?\\(?(?!0{1,3}|001\\)|555|1[\\.\\-/ ]?555|1?[\\.\\-/ ]?800)\\d+\\)?(?:\\ ?\\(?[\\.\\-/ ]?\\d+\\)?)(?:[\\.\\-/ ]?\\d+){0,3}(?:[\\.\\-/ ]?(?:ext|ex|e|xt|x)?(?:[\\.\\-/ ]?\\d{1,4})?)?");
	regex_constants::match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(num,e,f);
	if(!matching && !fromFile) {
		cout << "Invalid number. Please try again." << endl;
	}
	return matching;
}
