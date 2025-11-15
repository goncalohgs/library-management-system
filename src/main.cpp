#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

int findByISBN(Book library[], int size, const string &isbn)
{
    for (int i = 0; i < size; ++i)
        if (library[i].getISBN() == isbn)
            return i;
    return -1; // not found
}

int main()
{
    Book library[5];

    // Create 5 books
    library[0].setBookDetails("The Golden Dawn", "Israel Regardie", "1111", true, "07/11/2025");
    library[1].setBookDetails("Neijing Suwen - The Yellow Emperor’s Classic of Medicine", "Maoshing Ni, PH.D", "2222", true, "07/11/2025");
    library[2].setBookDetails("Accelerated C++", "Andrew Koenig & Barbara E. Moo", "3333", true, "07/11/2025");
    library[3].setBookDetails("Think and Grow Rich", "Napoleon Hill", "4444", true, "07/11/2025");
    library[4].setBookDetails("The Emerald Tablet of Thoth", "Doreal", "5555", true, "07/11/2025");

    int choice;
    string isbn;

    while (true)
    {

        cout << "==== Community Library System ====\n";
        cout << "1 - Borrow Book\n";
        cout << "2 - Return Book\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting program.\n";
            return 0;
        }

        cout << "Enter ISBN: ";
        cin >> isbn;

        int fbi = findByISBN(library, 5, isbn);

        if (choice == 1)
        {
            if (library[fbi].borrowBook())
                cout << "Borrowed successfully.\n";
            else
                cout << "This book is already borrowed.\n";
        }
        else if (choice == 2)
        {
            if (library[fbi].returnBook())
                cout << "Returned successfully.\n";
            else
                cout << "This book is already available.\n";
        }
        else
        {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
