#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class GroupmateList {
private:
	struct Groupmate {
		struct Fullname {
			string name;
			string surname;
			string patronymic;
		};
		Fullname fullname;
		string email;
		string phone_number;
		string group;
		Groupmate* next_node = nullptr;
		Groupmate* previous_node = nullptr;
	};
	Groupmate* start_node = nullptr	;
	Groupmate* current_node = nullptr;
public:
	GroupmateList(string _name, string _surname, string _patronymic, string _email, string _phone_number, string _group) {
		Groupmate* node = new Groupmate;
		node->fullname.name = _name;
		node->fullname.surname = _surname;
		node->fullname.patronymic = _patronymic;
		node->email = _email;
		node->phone_number = _phone_number;
		node->group = _group;
		this->start_node = node;
		this->current_node = node;
	}
	~GroupmateList()
	{
		current_node = start_node;
		while (current_node->next_node)
			current_node = current_node->next_node;
		while (current_node != start_node)
			remove();
		delete start_node;
	}
	void add(string _name, string _surname, string _patronymic, string _email, string _phone_number, string _group) {
		Groupmate* new_node = new Groupmate;
		new_node->fullname.name = _name;
		new_node->fullname.surname = _surname;
		new_node->fullname.patronymic = _patronymic;
		new_node->email = _email;
		new_node->phone_number = _phone_number;
		new_node->group = _group;
		new_node->next_node = current_node->next_node;
		new_node->previous_node = current_node;
		current_node->next_node = new_node;
		current_node = new_node;
	}
	void remove(){
		Groupmate* node = start_node;
		while (node->next_node != current_node)
			node = node->next_node;
		node->next_node = current_node->next_node;
		if (current_node->next_node)
			current_node->next_node->previous_node = node;
		delete current_node;
		current_node = node;
	}
	void step_forward() {
		if (current_node->next_node)
			current_node = current_node->next_node;
	}
	void step_backward() {
		if (current_node->previous_node)
			current_node = current_node->previous_node;
	}
	void edit(string _name, string _surname, string _patronymic, string _email, string _phone_number, string _group) {
		current_node->fullname.name = _name;
		current_node->fullname.surname = _surname;
		current_node->fullname.patronymic = _patronymic;
		current_node->email = _email;
		current_node->phone_number = _phone_number;
		current_node->group = _group;
	} 
	void show() {
		cout << current_node->fullname.name << " "
			<< current_node->fullname.surname << " "
			<< current_node->fullname.patronymic << " "
			<< current_node->email << " "
			<< current_node->phone_number << " "
			<< current_node->group << endl;
	}
	void show_all() {
		Groupmate *node = start_node;
		do {
			if (node == current_node) {
				cout << "(" << node->fullname.name << " "
					<< node->fullname.surname << " "
					<< node->fullname.patronymic << " "
					<< node->email << " "
					<< node->phone_number << " "
					<< node->group << ")" << endl;
			}
			else {
				cout << node->fullname.name << " "
					<< node->fullname.surname << " "
					<< node->fullname.patronymic << " "
					<< node->email << " "
					<< node->phone_number << " "
					<< node->group << endl;
			}
			node = node->next_node;
		} while (node);
	}
	void load_from_file(ifstream &fin) {
		while (!fin.eof()) {
			string str;
			getline(fin, str);
			if (str == "")
				break;
			string name = "", surname = "", patronymic = "", email = "", phone_number = "", group = "", delimiter = ",";
			name = str.substr(0, str.find(delimiter));
			str = str.erase(0, str.find(delimiter) + delimiter.length());
			surname = str.substr(0, str.find(delimiter));
			str = str.erase(0, str.find(delimiter) + delimiter.length());
			patronymic = str.substr(0, str.find(delimiter));
			str = str.erase(0, str.find(delimiter) + delimiter.length());
			email = str.substr(0, str.find(delimiter));
			str = str.erase(0, str.find(delimiter) + delimiter.length());
			phone_number = str.substr(0, str.find(delimiter));
			str = str.erase(0, str.find(delimiter) + delimiter.length());
			group = str.substr(0, str.find(delimiter));
			add(name, surname, patronymic, email, phone_number, group);
		}
	}
	void save_into_file(ofstream &fout) {
		Groupmate *node = this->start_node;
		do {
			fout << node->fullname.name << ","
				<< node->fullname.surname << ","
				<< node->fullname.patronymic << ","
				<< node->email << ","
				<< node->phone_number << ","
				<< node->group << endl;
			node = node->next_node;
		} while (node);
	}
};