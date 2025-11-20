#include <iostream>
#include "LibraryUserInterface.h"

using namespace std;

void showBanner()
{
    cout << CYAN << BOLD;
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║        COMMUNITY LIBRARY SYSTEM      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << RESET;
}

void showMenu()
{
    cout << BLUE << BOLD;
    cout << "\n📘  1 - View All Books\n\n";
    cout << "📕  2 - Borrow Book\n\n";
    cout << "📗  3 - Return Book\n\n";
    cout << "🚪  0 - Exit\n\n";
    cout << RESET;

    cout << CYAN << "──────────────────────────────\n"
         << RESET;
    cout << BOLD << "Choice: " << RESET;
}

void showBookWithSeparator(const Book &book, int index)
{
    cout << "-----------------------------\n";
    if (index >= 0)
        cout << BOLD << BLUE << "Book " << (index + 1) << ":\n"
             << RESET << endl;
    book.displayBookDetails();
    cout << "-----------------------------\n";
}
