#pragma once
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB.
#include "Adress.h"


class Contact {
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address address;

public:
	bool equals(Contact contact);
	Contact* copy_contact();

	Contact() {
		first_name = "Zain Abbas";
		last_name = "Laiba Afzaal";
		mobile_number = "0987653456";
		email_address = "Zainabbasm416@gmail.com";
		
	}
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address address);
	void operator=(const Contact& obj);

	void set_first_name();
	void set_last_name();
	void set_mobile_number();
	void set_email_address();
	void set_Address(Address address);

	string get_first_name();
	string get_last_name();
	string get_mobile_number();
	string get_email_address();
	Address getaddress();

	void print_contacts();

}; 
