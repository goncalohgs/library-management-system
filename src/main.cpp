#include <iostream>
#include <string>
#include "Book.h"
#include <limits>
#include "LibraryUserInterface.h"

using namespace std;

const int LIBRARY_SIZE = 5;
<<<<<<< HEAD
// Fill the library array with 5 sample books
void populateLibrary(Book library[])
{
    library[0].setBookDetails("The Golden Dawn",
                              "Israel Regardie",
                              "1111",
                              true,
                              "07/11/2025");

    library[1].setBookDetails("Neijing Suwen - The Yellow Emperor’s Classic of Medicine",
                              "Maoshing Ni, PH.D",
                              "2222",
                              true,
                              "07/11/2025");

    library[2].setBookDetails("Accelerated C++",
                              "Andrew Koenig & Barbara E. Moo",
                              "3333",
                              true,
                              "07/11/2025");

    library[3].setBookDetails("Think and Grow Rich",
                              "Napoleon Hill",
                              "4444",
                              true,
                              "07/11/2025");

    library[4].setBookDetails("The Emerald Tablet of Thoth",
                              "Doreal",
                              "5555",
                              true,
                              "07/11/2025");
}
=======
>>>>>>> origin/main

// -----------------------------------------------------------------------------
// Search for a book by ISBN.
// Returns index (0–4) if found, or -1 if not found.
// -----------------------------------------------------------------------------
int findByISBN(Book library[], int size, const string &isbn)
{
    for (int i = 0; i < size; ++i)
        if (library[i].getISBN() == isbn)
            return i;
    return -1;
}

// -----------------------------------------------------------------------------
// MAIN PROGRAM
// -----------------------------------------------------------------------------
int main()
{
    // Create an array with 5 Book objects
    Book library[LIBRARY_SIZE];

    // Set book details (title, author, ISBN, availability, date added)
    populateLibrary(library);
    int choice;
    string isbn;

    // Main menu loop (keeps repeating until user enters 0)
    while (true)
    {

        showBanner();

        showMenu();

        // Validate numeric input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "\nInvalid input. Please enter a number.\n"
                 << RESET;
            continue;
        }

        // Exit the program
        if (choice == 0)
        {
            cout << GREEN << "\nExiting program.\n"
                 << RESET;
            break;
        }

        // ---------------------------------------------------------------------
        // View all book details (no ISBN needed)
        // ---------------------------------------------------------------------
        if (choice == 1)
        {
            cout << CYAN << "\nListing all books in the library:\n"
                 << RESET;
            cout << CYAN << "-----------------------------\n"
                 << RESET;

            for (int i = 0; i < LIBRARY_SIZE; ++i)
            {

                showBookWithSeparator(library[i], i);
            }
            continue; // back to menu
        }

        // For anything that is not 2 or 3, show error and go back
        if (choice != 2 && choice != 3)
        {
            cout << RED << "\nInvalid option.\n"
                 << RESET;
            continue;
        }

        // ---------------------------------------------------------------------
        // Borrow / Return need ISBN
        // ---------------------------------------------------------------------
        cout << "\nEnter ISBN: ";
        cin >> isbn;

        // Search for the book
        int bookIndex = findByISBN(library, LIBRARY_SIZE, isbn);

        if (bookIndex == -1)
        {
            cout << RED << "\nBook with ISBN " << isbn << " not found." << RESET << endl;
            continue;
        }

        // ---------------------------------------------------------------------
        // Borrow the book
        // ---------------------------------------------------------------------
        if (choice == 2)
        {
            if (library[bookIndex].borrowBook())
            {
                cout << GREEN << "\nBook borrowed successfully!\n"
                     << RESET;
                showBookWithSeparator(library[bookIndex]);
            }
            else
            {
                cout << YELLOW << "\nThis book is already borrowed.\n"
                     << RESET;
            }
        }
        // ---------------------------------------------------------------------
        // Return the book
        // ---------------------------------------------------------------------
        else if (choice == 3)
        {
            if (library[bookIndex].returnBook())
            {
                cout << GREEN << "\nBook returned successfully!\n"
                     << RESET;
                showBookWithSeparator(library[bookIndex]);
            }
            else
            {
                cout << YELLOW << "\nThis book is already available.\n"
                     << RESET;
            }
        }
    }

    return 0;
}
