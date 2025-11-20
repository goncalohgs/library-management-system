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
    cout << BOLD << BLUE << "Title:       " << RESET << title << "\n";
    cout << BOLD << BLUE << "Author:      " << RESET << author << "\n";
    cout << BOLD << BLUE << "ISBN:        " << RESET << isbn << "\n";

        cout << BOLD << BLUE << "Date Added:  " << RESET << dateAdded << "\n";
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
