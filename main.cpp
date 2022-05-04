#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
#define MAX_NAME_CHARS 43
#define MAX_NUM_CHARS 24
using namespace std;
using std::regex;

unordered_map<string,string> db;

void menu();
void add(string& name, string& num);
void deleteByName(string& name);
void deleteByNum(string& num);
void viewList();
bool validateName(string& name);
bool validateNum(string& num);

int main()
{
	//TODO: ingest file automatically
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

void add(string& name, string& num) {

	/* TODO: manually create file with test cases
	/* TODO: file input
	do {
		//TODO: stringstream with pipe delim
		if(validateName(name)) { break; }
	} while(true); */
	
	cout << endl << "Please enter a name." << endl;
	do {
		getline(cin,name);
		name = name.substr(0,MAX_NAME_CHARS);
		if(validateName(name)) { break; }
	} while(true);
	
	cout << endl << "Please enter a phone number." << endl;
	do {
		getline(cin,num);
		num = num.substr(0,MAX_NUM_CHARS);
		if(validateNum(num)) { break; }
	} while(true);
	
	// Insert data into database
	db.emplace(name,num);
	cout << "Successfully inserted entry." << endl << endl;
	return;
}

void deleteByName(string& name) {

	cout << "Please enter the name for the entry you wish to delete." << endl;
	do {
		getline(cin,name);
		name = name.substr(0,MAX_NAME_CHARS);
		if(validateName(name)) { break; }
	} while(true);

	unordered_map<string,string>::const_iterator got = db.find(name);
	if(got == db.end()) {
		cout << "Name not found. Please enter the name exactly as displayed in the database." << endl << endl;
	}
	else {
		db.erase(name);
		cout << "Successfully deleted entry." << endl << endl;
	}
	return;
}

void deleteByNum(string& num) {
	cout << "Please enter the phone number for the entry you wish to delete." << endl;
	do {
		getline(cin,num);
		num = num.substr(0,MAX_NUM_CHARS);
		if(validateNum(num)) { break; }
	} while(true);

	for(auto& entry : db) {
		if(entry.second == num) {
			db.erase(entry.first);
			cout << "Successfully deleted entry." << endl << endl;
			return;
		}
	}
	cout << "Phone number not found. Please enter the phone number exactly as displayed in the database." << endl << endl;
	return;
}

void viewList() {
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

bool validateName(string& name) {
	regex e("(?=.{2,})(?!.{42,})(?!\\s)[a-zA-Z]+(?:,? ?'?-?[a-zA-Z']+,?)(?: ?'?-?[a-zA-Z]+){0,2}");
	regex_constants::match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(name,e,f);
	if(!matching) {
		cout << "Invalid name. Please try again." << endl;
	}
	return matching;
}

bool validateNum(string& num) {
	regex e("(?=.{7,})(?!.{23,})(?!\\s)\\+?\\(?(?!0{1,3}|001\\)|555|1[\\.\\-/ ]?555|1?[\\.\\-/ ]?800)\\d+\\)?(?:\\ ?\\(?[\\.\\-/ ]?\\d+\\)?)(?:[\\.\\-/ ]?\\d+){0,3}(?:[\\.\\-/ ]?(?:ext|ex|e|xt|x)?(?:[\\.\\-/ ]?\\d{1,4})?)?");
	regex_constants::match_flag_type f = regex_constants::match_any | regex_constants::match_not_null;
	bool matching = regex_match(num,e,f);
	if(!matching) {
		cout << "Invalid number. Please try again." << endl;
	}
	return matching;
}
