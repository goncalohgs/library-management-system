#include "Book.h"

void Book::setBookDetails(const string &t, const string &a, const string &i, const string &date)
{
    title = t;
    author = a;
    isbn = i;
    isAvailable = true; // New books are available by default
    dateAdded = date;
}

void Book::displayBookDetails() const
{
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    cout << "Date Added: " << dateAdded << endl;
}

bool Book::borrowBook()
{
    if (isAvailable)
    {
        isAvailable = false;
        return true;
    }
    return false;
}

bool Book::returnBook()
{
    if (!isAvailable)
    {
        isAvailable = true;
        return true;
    }
    return false;
}
