#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};


class Library {
private:
    vector<Book> books;

public:

    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "\n✅ Book added successfully!\n";
    }
    void displayBooks() {
        if (books.empty()) {
            cout << "\n⚠️ No books available in the library.\n";
            return;
        }

        cout << "\n----------------------------------------------\n";
        cout << setw(10) << "Book ID" << setw(25) << "Title" << setw(25) << "Author" << setw(15) << "Status";
        cout << "\n----------------------------------------------\n";

        for (auto &book : books) {
            cout << setw(10) << book.id
                 << setw(25) << book.title
                 << setw(25) << book.author
                 << setw(15) << (book.isIssued ? "Issued" : "Available") << endl;
        }
        cout << "----------------------------------------------\n";
    }


    void searchBook() {
        string searchTitle;
        cin.ignore();
        cout << "\nEnter the book title to search: ";
        getline(cin, searchTitle);

        bool found = false;
        for (auto &book : books) {
            if (book.title == searchTitle) {
                cout << "\n✅ Book Found!\n";
                cout << "Book ID: " << book.id << endl;
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Status: " << (book.isIssued ? "Issued" : "Available") << endl;
                found = true;
                break;
            }
        }

        if (!found) cout << "\n❌ Book not found in the library.\n";
    }


    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "\n⚠️ Book is already issued!\n";
                } else {
                    book.isIssued = true;
                    cout << "\n✅ Book issued successfully!\n";
                }
                return;
            }
        }

        cout << "\n❌ Book not found.\n";
    }


    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto &book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "\n⚠️ This book was not issued.\n";
                } else {
                    book.isIssued = false;
                    cout << "\n✅ Book returned successfully!\n";
                }
                return;
            }
        }

        cout << "\n❌ Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "        BOOKS MANAGEMENT SYSTEM        \n";
        cout << "=========================================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                lib.searchBook();
                break;
            case 4:
                lib.issueBook();
                break;
            case 5:
                lib.returnBook();
                break;
            case 6:
                cout << "\n📚 Thank you for using BOOKS Management System!\n";
                break;
            default:
                cout << "\n⚠️ Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
