#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include"adress.h"
#include"contact.h"
#include"contactbook.h"
#include<iomanip>
#include <ctime>
using namespace std;
int delay(int milliseconds) {
    clock_t goal = milliseconds + clock();
    while (goal > clock());
    return 1;
}
int main() {
    cout << "\n\n\            **Welcome to Contact Book**" << endl;
    delay(2000);
    system("cls");
    int choice;

    //  contactsbook contactsbook(size);
    const int size = 3; // Declare size variable here
    ContactsBook contactsbook(size); // Assuming initial size of contact book as 100
    Contact obj[size];
    Address obj2[size];

    do {
        cout << "\n\n********** Contact Book Menu **********" << endl;
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n" ;
        cout << "3. Search Contact\n";
        cout << "4. Sort Contacts\n";
        cout << "5. Merge Duplicates\n" ;
        cout << "6. Save Contacts to File\n";
        cout << "7. Load Contacts from File\n" ;
        cout << "8. Exit\n";
        cout << "****************************************\n" << endl;

        cout << "Enter your choice(only integer value):";
        cin >> choice;
       
        cin.ignore();
        string str;
        switch (choice) {
        case 1:
            for (int i = 0; i < size; i++)
            {
                cout << "\n** Add Contact **" << endl;
                obj[i].set_first_name();
                
                obj[i].set_last_name();
                
                obj[i].set_mobile_number();

                obj[i].set_email_address();
                cout << endl;
                cout << "\t***Enter the Address*** " << endl;
                
                obj2[i].set_house();
               
                obj2[i].set_street();
                
                obj2[i].set_city();
                
                obj2[i].set_country();
                obj[i].set_Address(obj2[i]);

                contactsbook.add_contact(obj[i]);
            }
            cout << "Contact Added Successfully!" << endl;
            break;
        case 2: {
            cout << "\n*** Display Contacts (sorted) ***" << endl;
            cout << setw(20) << left << "House" << setw(20) << left << "Street" << setw(20) << left << "City" << setw(20) << left << "Country" << endl;

            for (int i = 0; i < size; i++) {
                obj2[i].print_address();

            }
            cout << endl;
            cout << "********* Contact Details *********\n";
            cout << setw(20) << left << "First Name" << setw(20) << left << "Last Name" << setw(20) << left << "Mobile Number" << setw(20) << left << "Email Address" << endl;

            for (int i = 0; i < size; i++) {

                obj[i].print_contacts();
                
            }
            break;
        }
        case 3: {
            string choice;
            cout << "Enter search contacts(first_name, last_name or phone): ";
            cin >> choice;
            if (choice == "first_name" || choice == "last_name")
            {
                string name;
                cout << "Enter " << choice << ": ";
                cin.ignore();
                getline(cin, name);
                Contact* result = nullptr;
                if (choice == "first_name")
                {
                    result = contactsbook.search_contact(name, "");
                }
                else
                {
                    result = contactsbook.search_contact("", name);
                }
                if (result != nullptr)
                {
                    cout << "Contact found" << endl;
                    result->print_contacts();

                }
                else
                {
                    cout << "Contact not found" << endl;
                }
            }
            else if (choice == "phone")
            {
                string phone_number;
                cout << "Enter phone number: ";
                cin >> phone_number;
                Contact* result = nullptr;
                result = contactsbook.search_contact(phone_number);

                if (result != nullptr)
                {
                    cout << "Contact found" << endl;
                    result->print_contacts();
                }
                else
                {
                    cout << "Contact not found" << endl;
                }
            }
            break;
        }
        case 4: {
            string choice;
            cout << "Enter the choice(first_name or last_name): ";
            cin >> choice;
            contactsbook.print_contacts_sorted(choice);
            break;
        }
        case 5:
            cout << "*** Merge Duplicate Contacts ***" << endl;
            contactsbook.merge_duplicates();
            cout << "Duplicate Contacts Merged Successfully!" << endl;
            break;
        case 6:
            cout << "*** Save Contacts to File ***" << endl;
             ContactsBook save_contacts_to_file();
            cout << "Contacts Saved Successfully!" << endl;
            break;
        case 7:
            cout << "*** Load Contacts from File ***" << endl;
             ContactsBook load_contacts_from_file();
            cout << "Contacts Loaded Successfully!" << endl;
            break;
        case 8:
            cout << "Exiting...please wait" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 8);
    system("pause");
    return 0;
}
