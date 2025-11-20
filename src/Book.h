#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book
{
protected:
    string title;
    string author;
    string isbn;
    bool isAvailable;
    string dateAdded;

public:
    void setBookDetails(const string &t,
                        const string &a,
                        const string &i,
                        bool available,
                        const string &date);

    void displayBookDetails() const;

    bool borrowBook();
    bool returnBook();

    const string &getISBN() const { return isbn; }
    bool getAvailability() const { return isAvailable; }
};

#endif // BOOK_H
