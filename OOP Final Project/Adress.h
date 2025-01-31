#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
	string house;
	string street;
	string city;
	string country;

public:
	Address(string house,string street,string city,string country);
	Address() {
		house = "Family";
		street = "1";
		city = "FSD";
		country = "Pakistan";
	}

	void set_house();
	void set_street();
	void set_city();
	void set_country();

	string get_house();
	string get_street();
	string get_city();
	string get_country();
	bool equals(const Address& address);
	void print_address();
	Address copy_address();
	void operator=(const Address& obj);
};