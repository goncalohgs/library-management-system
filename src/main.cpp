#include <iostream>
#include <string>
#include "Book.h"
#include <limits>

using namespace std;

const int LIBRARY_SIZE = 5;

// This function searches for a book by ISBN.
// If the ISBN is found, it returns the index (0–4).
// If not found, it returns -1.

int findByISBN(Book library[], int size, const string &isbn)
{
    for (int i = 0; i < size; ++i)
        if (library[i].getISBN() == isbn)
            return i;
    return -1;
}

int main()
{
    // Create an array with 5 Book objects

    Book library[LIBRARY_SIZE];

    // Set book details (title, author, ISBN, availability, date added) 5 books
    library[0].setBookDetails("The Golden Dawn", "Israel Regardie", "1111", true, "07/11/2025");
    library[1].setBookDetails("Neijing Suwen - The Yellow Emperor’s Classic of Medicine", "Maoshing Ni, PH.D", "2222", true, "07/11/2025");
    library[2].setBookDetails("Accelerated C++", "Andrew Koenig & Barbara E. Moo", "3333", true, "07/11/2025");
    library[3].setBookDetails("Think and Grow Rich", "Napoleon Hill", "4444", true, "07/11/2025");
    library[4].setBookDetails("The Emerald Tablet of Thoth", "Doreal", "5555", true, "07/11/2025");

    int choice;
    string isbn;

    // Main menu loop (keeps repeating until user enters 0)
    while (true)
    {
        // Display menu
        cout << "==== Community Library System ====\n";
        cout << "1 - Borrow Book\n";
        cout << "2 - Return Book\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";

        // Validation to avoid program crashing if user types letters
        if (!(cin >> choice))
        {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue; // go back to the menu
        }

        // Exit the program
        if (choice == 0)
        {
            cout << "Exiting program.\n";
            return 0;
        }

        // Ask user for ISBN
        cout << "Enter ISBN: ";
        cin >> isbn;

        // Search for the book in the array with book not found logic
        int bookIndex = findByISBN(library, LIBRARY_SIZE, isbn);
        if (bookIndex == -1)
        {
            cout << "Book with ISBN " << isbn << " not found.\n";
            continue;
        }

        // Borrow logic
        if (choice == 1)
        {
            if (library[bookIndex].borrowBook())
            {
                cout << "Borrowed successfully.\n";
                cout << "-----------------------------\n";
                library[bookIndex].displayBookDetails();
                cout << "-----------------------------\n";
            }
            else
            {
                cout << "This book is already borrowed.\n";
            }
        }

        // Return logic
        else if (choice == 2)
        {
            if (library[bookIndex].returnBook())
            {
                cout << "Returned successfully.\n";
                cout << "-----------------------------\n";
                library[bookIndex].displayBookDetails();
                cout << "-----------------------------\n";
            }
            else
            {
                cout << "This book is already available.\n";
            }
        }
        else
        {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
