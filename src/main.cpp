#include "Database.h"
#include <iostream>
#include <string>

using namespace std;

void showMenu() {
    cout << "\n--- Database Menu ---\n";
    cout << "1. Insert a record\n";
    cout << "2. Retrieve a record\n";
    cout << "3. Delete a record\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Database db("users.data");
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: { // Insert a record
                int id, age;
                string name;

                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore(); // Clear the newline from the input buffer
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;

                db.insert(id, name, age);
                cout << "Record inserted successfully.\n";
                break;
            }

            case 2: { // Retrieve a record
                int id;
                cout << "Enter ID to retrieve: ";
                cin >> id;

                string record = db.retrieve(id);
                if (record == "Record not found") {
                    cout << "Record not found.\n";
                } else {
                    cout << "Record found: " << record << endl;
                }
                break;
            }

            case 3: { // Delete a record
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;

                db.deleteRecord(id);
                cout << "Record deleted (logical deletion).\n";
                break;
            }

            case 4: { // Exit
                cout << "Exiting the program. Goodbye!\n";
                break;
            }

            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
