#include <fstream>
#include "ContactBook.h"
using namespace std;
void ContactsBook::add_contact(const Contact& contact)
{
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
	if (full())
	{
		resize_list();
	}
	contacts_list[contacts_count++] = contact;

}

int ContactsBook::total_contacts()
{
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	return contacts_count;
}

bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/
	return contacts_count == size_of_contacts;
}

void ContactsBook::resize_list()
{
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
	int new_size = size_of_contacts * 2;
	Contact* new_contacts_list = new Contact[new_size];
	for (int i = 0; i < contacts_count; i++)
	{
		new_contacts_list[i] = *contacts_list[i].copy_contact();
	}
	delete[] contacts_list;
	contacts_list = new_contacts_list;
	this->size_of_contacts = new_size;
}

Contact* ContactsBook::search_contact(string first_name, string last_name)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].get_first_name() == first_name || contacts_list[i].get_last_name() == last_name)
		{
			return contacts_list[i].copy_contact();
		}
	}
	return nullptr;
}

Contact* ContactsBook::search_contact(string phone)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].get_mobile_number() == phone)
		{
			return contacts_list[i].copy_contact();
		}
	}
	return nullptr;
}

Contact* ContactsBook::search_contact(const Address& address)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getaddress().equals(address))
		{
			return contacts_list[i].copy_contact();
		}
	}
	return nullptr;
}

ContactsBook::ContactsBook(int size_of_list)
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
	this->size_of_contacts = size_of_list;
	this->contacts_list = new Contact[size_of_contacts];
	this->contacts_count = 0;
}

Contact* ContactsBook::copy_contact_list()
{
	Contact* copy_contact = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++)
	{
		copy_contact[i] = *contacts_list[i].copy_contact();
	}
	return copy_contact;
}

void ContactsBook::print_contacts()
{
	cout << "Contacts: " << endl;;
	for (int i = 0; i < contacts_count; i++)
	{
		cout << "Contact " << i + 1 << ":" << endl;
		cout << "First Name: " << contacts_list[i].get_first_name() << endl;
		cout << "Last Name: " << contacts_list[i].get_last_name() << endl;
		cout << "Mobile Number: " << contacts_list[i].get_mobile_number() << endl;
		cout << "Email Address: " << contacts_list[i].get_email_address() << endl;
		cout << "Address: ";
		Address address = contacts_list[i].getaddress();
		if (address.get_house() != "")
		{
			cout << address.get_house() << ", ";
		}
		if (address.get_street() != "")
		{
			cout << address.get_street() << ", ";
		}
		if (address.get_city() != "")
		{
			cout << address.get_city() << ", ";
		}
		if (address.get_country() != "")
		{
			cout << address.get_country();
		}
		cout << endl << endl;
	}
}

void ContactsBook::print_contacts_sorted(string choice)
{
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* sorted_contacts = copy_contact_list();
	sort_contacts_list(sorted_contacts, choice);
	for (int i = 0; i < contacts_count; i++)
	{
		cout << sorted_contacts[i].get_first_name() << " " << sorted_contacts[i].get_last_name() << " " << sorted_contacts[i].get_mobile_number() << " " << sorted_contacts[i].get_email_address() << endl;
		sorted_contacts[i].getaddress().print_address();
		cout << endl;
	}
}

void ContactsBook::sort_contacts_list(Contact* contacts_list, string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
	bool sort_by_first_name = (choice == "first_name");
	quick_sort_contacts_list(contacts_list, 0, contacts_count - 1, sort_by_first_name);
}

void ContactsBook::quick_sort_contacts_list(Contact* contacts_list, int low, int high, bool by_first_name)
{
	if (low < high)
	{
		int index;
		if (by_first_name)
		{
			index = partition_by_first_name(contacts_list, low, high);
		}
		else
		{
			index = partition_by_last_name(contacts_list, low, high);
		}
		quick_sort_contacts_list(contacts_list, low, index - 1, by_first_name);
		quick_sort_contacts_list(contacts_list, index + 1, high, by_first_name);
	}
}

int ContactsBook::partition_by_first_name(Contact* contacts_list, int low, int high)
{
	Contact point = contacts_list[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (contacts_list[j].get_first_name() <= point.get_first_name())
		{
			i++;
			swap(contacts_list[i], contacts_list[j]);
		}
	}
	swap(contacts_list[i + 1], contacts_list[high]);
	return i + 1;
}

int ContactsBook::partition_by_last_name(Contact* contacts_list, int low, int high)
{
	Contact point = contacts_list[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (contacts_list[j].get_first_name() <= point.get_first_name())
		{
			i++;
			swap(contacts_list[i], contacts_list[j]);
		}
	}
	swap(contacts_list[i + 1], contacts_list[high]);
	return i + 1;
}

void ContactsBook::merge_duplicates()
{
	int merged_count = 0;
	for (int i = 0; i < contacts_count - 1; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				for (int k = j; k < contacts_count - 1; k++)
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				contacts_count--;
				j--;
				merged_count++;
			}
		}
	}
	cout << "Merged " << merged_count << " duplicates " << endl;
}


void ContactsBook::load_from_file(string file_name)
{
	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Error is opening file " << endl;
		return;
	}
	int loaded_contacts_count;
	file >> loaded_contacts_count;
	for (int i = 0; i < loaded_contacts_count; i++)
	{
		string first_name, last_name, mobile_number, email_address, house, streat, city, country;
		file >> first_name >> last_name >> mobile_number >> email_address >> house >> streat >> city >> country;
		Address* address = new Address(house, streat, city, country);
	}
	file.close();

}


void ContactsBook::save_to_file(string file_name)
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
	ofstream file(file_name);
	if (!file.is_open())
	{
		cout << "Error is opening file " << endl;
		return;
	}
	file << contacts_count << endl;
	for (int i = 0; i < contacts_count; i++)
	{
		file << contacts_list[i].get_first_name() << "," << contacts_list[i].get_last_name() << "," << contacts_list[i].get_mobile_number() << "," << contacts_list[i].get_email_address() << endl;
		file << contacts_list[i].getaddress().get_house() << "," << contacts_list[i].getaddress().get_street() << "," << contacts_list[i].getaddress().get_city() << "," << contacts_list[i].getaddress().get_country() << endl;
	}
	file.close();
}