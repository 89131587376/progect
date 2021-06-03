#pragma once
#include "GroupmateList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Menu {
private:
	Menu() {}
public:
	static void execute(GroupmateList list) {
		while (true) {
			Menu::show_menu();
			int answer;
			cin >> answer;
			switch (answer) {
				case 1:
					add_item(list);
					break;	
				case 2:
					del_item(list);
					break;
				case 3:
					edit_item(list);
					break;
				case 4:
					load_from_file(list);
					break;
				case 5:
					save_into_file(list);
					break;
				case 6:
					list.show();
					break;
				case 7:
					list.show_all();
					break;
				case 8:
					next_item(list);
					break;
				case 9:
					previous_item(list);
					break;
				case 0:
					exit(0);
				default:
					cout << "No such action" << endl;
			}
				
					
		}
	}
	static void show_menu() {
		cout << endl;
		cout << "1) Add item" << endl
			<< "2) Delete item" << endl
			<< "3) Edit item" << endl
			<< "4) Load from file" << endl
			<< "5) Save into file" << endl
			<< "6) Show item" << endl
			<< "7) Show all" << endl
			<< "8) Next item" << endl
			<< "9) Previous item" << endl
			<< "0) Exit" << endl;
	}
	static void add_item(GroupmateList &list) {
		string name, surname, patronymic, email, phone_number, group;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter patronymic: ";
		cin >> patronymic;
		cout << "Enter email: ";
		cin >> email;
		cout << "Enter phone number: ";
		cin >> phone_number;
		cout << "Enter group: ";
		cin >> group;
		list.add(name, surname, patronymic, email, phone_number, group);
	}
	static void edit_item(GroupmateList& list) {
		string name, surname, patronymic, email, phone_number, group;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter patronymic: ";
		cin >> patronymic;
		cout << "Enter email: ";
		cin >> email;
		cout << "Enter phone number: ";
		cin >> phone_number;
		cout << "Enter group: ";
		cin >> group;
		list.edit(name, surname, patronymic, email, phone_number, group);
	}
	static void del_item(GroupmateList& list) {
		list.remove();
	}
	static void load_from_file(GroupmateList& list) {
		cout << "Enter filename: ";
		string filename;
		cin >> filename;
		ifstream fin(filename);
		if (!fin) {
			cout << "File not open" << endl;
			return;
		}
		list.load_from_file(fin);
		fin.close();
	}
	static void save_into_file(GroupmateList& list) {
		cout << "Enter filename: ";
		string filename;
		cin >> filename;
		ofstream fout(filename);
		if (!fout) {
			cout << "File not open";
			return;
		}
		list.save_into_file(fout);
		fout.close();
	}
	static void next_item(GroupmateList& list) {
		list.step_forward();
	}
	static void previous_item(GroupmateList& list) {
		list.step_backward();
	}
};