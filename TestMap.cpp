#include "Employee.h"													// Defines class Employee
#include "Map.h"														// Defines template Map<Key, Value>
#include "Book.h"
#include <iostream>

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

typedef std::string Title;
typedef Map<Title, Book> Library;

using namespace std;

void addEmployees(Database& database);
void modifyEmployees(Database& database);

void testNonExistentKey(Database& database);
void testDuplicateKeys(Database& database);

void addBooks(Library& library);
void modifyBooks(Library& library);

int main() {
	Database database;
	addEmployees(database);

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Original database:" << endl << database << endl;
	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;

    testNonExistentKey(database);
    testDuplicateKeys(database);




	Library library;
    addBooks(library);

    Library newLibrary = library;
    newLibrary.add("Pan Tadeusz", Book("Adam Mickiewicz", "Epic poem", 376, "on the bookshelf"));
    modifyBooks(newLibrary);

    cout << "Original library:" << endl << library << endl;
    cout << "Modified library:" << endl << newLibrary << endl;

    library = newLibrary;

    cout << "Library after the assignment:" << endl << library << endl;

};

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
}

void testNonExistentKey(Database& database) {
    Employee* nonExistentEmployee = database.find(999999999);
    if (nonExistentEmployee == nullptr) {
        cout << "Employee not found!" << endl;
    } else {
        cout << "Found Employee: " << *nonExistentEmployee << endl;
    }
}

void testDuplicateKeys(Database& database) {
    database.add(761028073, Employee("Duplicate Name", "duplicate position", 30));
    database.add(123456789, Employee("Test Employee", "Test Position", 25));

    cout << "Database after adding data with duplicate keys:" << endl;
    cout << database << endl;
}

void addBooks(Library& library) {
    library.add("Harry Potter", Book("J.K. Rowling", "Science fiction", 820, "on the bookshelf"));
    library.add("Romeo and Juliet", Book("William Shakespeare", "Tragedy", 480, "on the bookshelf"));
    library.add("The Doll", Book("Boleslaw Prus", "Novel", 835, "borrowed"));
    library.add("Hamlet", Book("William Shakespeare", "Tragedy", 184, "borrowed"));
}

void modifyBooks(Library& library) {
    Book* bookPtr;

    bookPtr = library.find("Romeo and Juliet");
    if (bookPtr != nullptr) {
        bookPtr->status = "on the bookshelf";
    }

    bookPtr = library.find("The Doll");
    if (bookPtr != nullptr) {
        bookPtr->numberOfPages = 200;
    }

    bookPtr = library.find("Example Book");
    if (bookPtr == nullptr) {
        cout << "Book not found!" << endl;
    }
}
