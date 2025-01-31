#pragma once
#include "Adress.h"
#include "Contact.h"
using namespace std;
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#include<fstream>
#endif // !BASIC_LIB


class ContactsBook
{
private:
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
	// stored at this count plus 1 index

public:
	void add_contact(const Contact& contact);
	int total_contacts();

	Contact* search_contact(string first_name, string last_name);
	Contact* search_contact(string phone);
	Contact* search_contact(const Address& address);

	ContactsBook(int size_of_list);

	void print_contacts_sorted(string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal, this means if

/*
*  This function loads contacts from the given file (see details in ContactsBook.cpp)
*/
	void load_from_file(string file_name);
	void save_to_file(string file_name);
	Contact* copy_contact_list();
	void quick_sort_contacts_list(Contact* contacts_list, int low, int high, bool by_first_name);
	int partition_by_first_name(Contact* contacts_list, int low, int high);
	int partition_by_last_name(Contact* contacts_list, int low, int high);
	void print_contacts();
private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, string choice);
};