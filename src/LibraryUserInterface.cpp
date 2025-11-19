#include <iostream>
#include "LibraryUserInterface.h"

using namespace std;

void showBanner()
{
    cout << CYAN;
    cout << "\n┌──────────────────────────────┐\n";
    cout << "│       Community Library      │\n";
    cout << "└──────────────────────────────┘\n";
    cout << RESET;
}

void showMenu()
{
    cout << BLUE << "1 - View all books\n"
         << RESET;
    cout << BLUE << "2 - Borrow Book\n"
         << RESET;
    cout << BLUE << "3 - Return Book\n"
         << RESET;
    cout << BLUE << "0 - Exit\n"
         << RESET;
    cout << "------------------------------\n";
    cout << "Choice: ";
}

void showBookWithSeparator(const Book &book, int index)
{
    cout << "-----------------------------\n";
    if (index >= 0)
        cout << "Book " << (index + 1) << ":\n";
    book.displayBookDetails();
    cout << "-----------------------------\n";
}
