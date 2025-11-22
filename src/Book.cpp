#include <iomanip>
#include <chrono>
#include <thread>

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

void Book::displayBookDetails(int index) const
{
    if (index >= 0)
    {
        cout << BOLD << BLUE
             << "┌──────────────────────────── Book" << setw(2) << (index + 1) << "  Details ───────────────────────────┐\n"
             << RESET;
    }
    cout << BOLD << BLUE << "│ Title:      " << RESET << title << "\n";
    cout << BOLD << BLUE << "│ Author:     " << RESET << author << "\n";
    cout << BOLD << BLUE << "│ ISBN:       " << RESET << isbn << "\n";
    cout << BOLD << BLUE << "│ Date Added: " << RESET << dateAdded << "\n";
    // Availability badge
    if (isAvailable)
    {
        cout << BOLD << BLUE << "│ Availability: " << RESET << GREEN << "🟩 AVAILABLE" << RESET << "\n";
    }
    else
    {
        cout << BOLD << BLUE << "│ Availability: " << RESET << RED << "🟥 BORROWED" << RESET << "\n";
    }

    cout << BOLD << BLUE
         << "└────────────────────────────────────────────────────────────────────────┘\n"
         << RESET;
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
