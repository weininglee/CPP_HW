#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct StRec {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

int main() {
	vector<StRec> data;
	string firstName, lastName, phone;
	string mode;
	while (cin >> mode) {
		bool error = false;
		bool exist = false;
		if (mode == "print") {
			if (data.empty()) {
				cout << "Print Error" << endl;
			}
			else {
				for (int i = 0; i < data.size(); i++) {
					cout << data[i].firstName << " " << data[i].lastName << " " << data[i].phone << endl;
				}
			}
		}
		else {
			cin >> firstName >> lastName >> phone;
			// if error
			if (firstName.size() > 25 || lastName.size() > 30 || phone.size() > 15) {
				//cout << firstName.size() << "  " << lastName.size() << " " << phone.size() << endl;
				cout << "Input Error" << endl;
				error = true;
			}
			else {
				int tmp;
				for (int i = 0; i < phone.size(); i++) {
					tmp = (int)phone[i];
					if (tmp >= 48 && tmp <= 57) {
						//cout << tmp << endl;
						continue;
					}
					else {
						cout << "Input Error" << endl;
						error = true;
						break;
					}
				}
			}
			if (error) {
				continue;
			}
			if (mode == "insert") {
				//cout << data.size() << endl;
				if (data.size() >= 10) {
					cout << "Insert Error" << endl;
					continue;
				}
				for (int i = 0; i < data.size(); i++) {
					if (data[i].firstName == firstName && data[i].lastName == lastName && data[i].phone == phone) {
						cout << "Insert Error" << endl;
						error = true;
						break;
					}
				}
				if (error) {
					continue;
				}
				// insert
				StRec input;
				size_t length;
				length = firstName.copy(input.firstName, firstName.size(), 0);
				input.firstName[length] = '\0';
				length = lastName.copy(input.lastName, lastName.size(), 0);
				input.lastName[length] = '\0';
				length = phone.copy(input.phone, phone.size(), 0);
				input.phone[length] = '\0';
				data.push_back(input);
			}
			else if (mode == "search") {
				for (int i = 0; i < data.size(); i++) {
					if (firstName == data[i].firstName && lastName == data[i].lastName && phone == data[i].phone) {
						cout << i << endl;
						exist = true;
						break;
					}
				}
				if (!exist) {
					cout << "Search Error" << endl;
				}
			}
			else if (mode == "delete") {
				for (int i = 0; i < data.size(); i++) {
					if (firstName == data[i].firstName && lastName == data[i].lastName && phone == data[i].phone) {
						data.erase(data.begin() + i);
						exist = true;
						break;
					}
				}
				if (!exist) {
					cout << "Delete Error" << endl;
				}
			}
			else {
				cout << "Input Error" << endl;
			}
		}
	}
}