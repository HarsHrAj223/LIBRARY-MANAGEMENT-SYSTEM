#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book structure to store details of a book
struct Book {
    int id;
    string title;
    string author;
    bool isIssued;  // To track if the book is issued
};

// Class Library to manage the library system
class Library {
private:
    vector<Book> books;
    int bookCounter = 0;

public:
    // Function to add a book
    void addBook() {
        Book newBook;
        newBook.id = ++bookCounter;
        cout << "Enter the book title: ";
        cin.ignore();
        getline(cin, newBook.title);
        cout << "Enter the author name: ";
        getline(cin, newBook.author);
        newBook.isIssued = false;  // New book is not issued initially

        books.push_back(newBook);
        cout << "Book added successfully! Book ID: " << newBook.id << endl;
    }

    // Function to view all books
    void viewBooks() {
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }

        cout << "List of books in the library:" << endl;
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                 << ", Status: " << (book.isIssued ? "Issued" : "Available") << endl;
        }
    }

    // Function to search for a book by title or author
    void searchBook() {
        string keyword;
        cout << "Enter book title or author to search: ";
        cin.ignore();
        getline(cin, keyword);

        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos) {
                cout << "Book Found - ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
                     << ", Status: " << (book.isIssued ? "Issued" : "Available") << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No book found with the given details." << endl;
        }
    }

    // Function to issue a book
    void issueBook() {
        int id;
        cout << "Enter the Book ID to issue: ";
        cin >> id;

        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "This book is already issued to someone else." << endl;
                } else {
                    book.isIssued = true;
                    cout << "Book issued successfully!" << endl;
                }
                return;
            }
        }

        cout << "No book found with ID: " << id << endl;
    }

    // Function to return a book
    void returnBook() {
        int id;
        cout << "Enter the Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "This book was not issued." << endl;
                } else {
                    book.isIssued = false;
                    cout << "Book returned successfully!" << endl;
                }
                return;
            }
        }

        cout << "No book found with ID: " << id << endl;
    }
};

int main() {
    Library library;
    int choice;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book\n2. View Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.viewBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                library.issueBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                cout << "Exiting the system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
