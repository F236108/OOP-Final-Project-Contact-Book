#include "Adress.h"
#include<iomanip>

Address::Address(string house, string street, string city, string country)
{
	this->house = "home";
	this->street = "41";
	this->city = "FSD";
	this->country = "Pakistan";
}

void Address::set_house()
{
	cout << "Enter the House name : ";
	string h;
	getline(cin, h);
	this->house = h;
}

void Address::set_street()
{
	cout << "Enter the street Number : ";
	string s;
	getline(cin, s);
	this->street = s;
}

void Address::set_city()
{
	cout << "Enter the City Name : ";
	string c;
	getline(cin, c);
	this->city = c;
}

void Address::set_country()
{
	cout << "Enter the Country name : ";
	string p;
	getline(cin, p);
	this->country = p;
}

string Address::get_house()
{
	return this->house;
}

string Address::get_street()
{
	return this->street;
}

string Address::get_city()
{
	return this->city;
}

string Address::get_country()
{
	return this->country;
}

bool Address::equals(const Address& address)
{
	if (this->house == address.house && this->street == address.street && this->city == address.city && this->country == address.country) {
		return true;
	}
	return false;
}

void Address::print_address()
{
	cout << setw(20) << left<< house  << setw(20) << left << street << setw(20) << left << city  << setw(20) << left << country << endl;
}

Address Address::copy_address()
{
	return Address(this->house, this->street, this->city, this->country);
}

void Address::operator=(const Address& obj)
{
	this->house = obj.house;
	this->city = obj.city;
	this->street = obj.street;
	this->country = obj.country;
}
