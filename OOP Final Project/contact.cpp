#include "Contact.h"
#include<iomanip>
Contact::Contact(std::string first_name = "", std::string last_name = "", std::string mobile_number = "", std::string email_address = "", Address address = { "", "", "", "" }) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->mobile_number = mobile_number;
	this->email_address = email_address;
	this->address = address;
}

void Contact::operator=(const Contact& obj)
{
	this->first_name = obj.first_name;
	this->last_name = obj.last_name;
	this->address = obj.address;
	this->mobile_number = obj.mobile_number;
	this->email_address = obj.email_address;

}

void Contact::set_first_name()
{
	cout << "Enter the First Name :";
	string n;
	getline(cin, n);
	this->first_name = n;
}

void Contact::set_last_name()
{
	cout << "Enter the last Name :";
	string l;
	getline(cin, l);
	this->last_name = l;
}

void Contact::set_mobile_number()
{
	cout << "Enter the Mobile Number :";
	string N;
	getline(cin, N);
	this->mobile_number = N;
}

void Contact::set_email_address()
{
	cout << "Enter the Email Address :";
	string e;
	getline(cin, e);
	this->email_address = e;
}

void Contact::set_Address(Address address)
{
	this->address = address;
}

string Contact::get_first_name()
{
	return this->first_name;
}

string Contact::get_last_name()
{
	return this->last_name;
}

string Contact::get_mobile_number()
{
	return this->mobile_number;
}

string Contact::get_email_address()
{
	return this->email_address;
}

Address Contact::getaddress()
{
	return address;
}
void Contact::print_contacts()
{
	cout << setw(20) << left << first_name << setw(20) << left << last_name << setw(20) << left << mobile_number << setw(20) << left << email_address << endl;

	
}


/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/



/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/

bool Contact::equals(Contact contact)
{
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->email_address == contact.email_address && this->mobile_number == contact.mobile_number && this->address.equals(contact.address)) {
		return true;
	}
	return false;
}

Contact* Contact::copy_contact()
{
	Contact obj(this->first_name, this->last_name, this->mobile_number, this->email_address, this->address), * ptr;
	ptr = &obj;
	return ptr;
}

