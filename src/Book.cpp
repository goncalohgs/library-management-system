#include "Book.h"
using namespace std;

void Book::setBookDetails(const string &t, const string &a, const string &i, bool available = true, const string &date)
{
    title = t;
    author = a;
    isbn = i;
    isAvailable = available;
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
