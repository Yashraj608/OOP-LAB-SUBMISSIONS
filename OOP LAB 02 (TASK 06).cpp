//LIBRARY MANAGEMENT SYSTEM//
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int bookID;
    string title;
    string author;
    bool isAvailable;
};

void addBook(Book *&books, int &count) {
    Book *newBooks = new Book[count + 1];
    for (int i = 0; i < count; i++) {
        newBooks[i] = books[i];
    }
    cout<<"Enter book ID: ";
    cin>>newBooks[count].bookID;
    cin.ignore();
    cout<<"Enter book title:";
    getline(cin, newBooks[count].title);
    cout<<"Enter book author: ";
    getline(cin, newBooks[count].author);
    newBooks[count].isAvailable = true;
    delete[] books;
    books = newBooks;
    count++;
    cout<<"Book added successfully."<< endl;
}

void removeBook(Book *&books, int &count, int id) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].bookID == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout<<"Book not found"<<endl;
        return;
    }
    Book *newBooks = new Book[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newBooks[j++] = books[i];
        }
    }
    delete[] books;
    books = newBooks;
    count--;
    cout<<"Book removed"<<endl;
}

void searchBook(Book *books, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (books[i].bookID == id) {
            cout << "Book found: " << books[i].title << " by " << books[i].author << endl;
            return;
        }
    }
    cout<<"Book not found"<<endl;
}

void displayBooks(Book *books, int count) {
    if (count == 0) {
        cout<<"No books in the library"<<endl;
        return;
    }
    cout << "Available books:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "ID: " << books[i].bookID << ", Title: " << books[i].title << ", Author: " << books[i].author << ", Available: " << (books[i].isAvailable ? "Yes" : "No") << endl;
    }
}

int main() {
    Book *books = nullptr;
    int count = 0;
    int choice, id;

    while (true) {
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Display all books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books, count);
                break;
            case 2:
                cout << "Enter book ID to remove: ";
                cin >> id;
                removeBook(books, count, id);
                break;
            case 3:
                cout << "Enter book ID to search: ";
                cin >> id;
                searchBook(books, count, id);
                break;
            case 4:
                displayBooks(books, count);
                break;
            case 5:
                delete[] books;
                cout << "24K-0737 exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}