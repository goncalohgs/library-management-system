#include "Book.h"
#include "LibraryUserInterface.h"
using namespace std;

void Book::setBookDetails(const string &t, const string &a,
                          const string &i, bool available,
                          const string &date)
{
    title = t;
    author = a;
    isbn = i;
    isAvailable = available;
    dateAdded = date;
}

void Book::displayBookDetails() const
{
    cout << BOLD << CYAN << "Title: " << RESET << title << endl;
    cout << BOLD << CYAN << "Author: " << RESET << author << endl;
    cout << BOLD << CYAN << "ISBN: " << RESET << isbn << endl;
    cout << BOLD << CYAN << "Availability: " << RESET << (isAvailable ? "Available" : "Not Available") << endl;
    cout << BOLD << CYAN << "Date Added: " << RESET << dateAdded << endl;
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
