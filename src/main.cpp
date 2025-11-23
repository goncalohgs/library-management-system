#include <iostream>
#include <string>
#include <limits>

#include "Book.h"
#include "LibraryUserInterface.h"
#include "LibraryData.h"

using namespace std;

const int LIBRARY_SIZE = 5;

// -----------------------------------------------------------------------------
// MAIN PROGRAM
// -----------------------------------------------------------------------------
int main()
{
    // Create an array with 5 Book objects
    Book library[LIBRARY_SIZE];

    // Set book details (title, author, ISBN, availability, date added)
    populateLibrary(library);
    int choice = -1;
    string isbn;

    // Main menu loop (keeps repeating until user enters 0)
    while (true)
    {
        clearScreen();

        showBanner();
        showMenu();

        // Move cursor
        cout << "\033[2A";  // move cursor up 2 lines
        cout << "\033[18C"; // move cursor right 18 columns

        // Validate numeric input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            showInvalidInputMessage();
            waitForEnter();
            continue;
        }

        // Exit the program
        if (choice == 0)
        {
            showExitMessage();
            break;
        }

        // ---------------------------------------------------------------------
        // View all book details (no ISBN needed)
        // ---------------------------------------------------------------------
        if (choice == 1)
        {
            showBooksLoading();
            showBooksHeader();

            for (int i = 0; i < LIBRARY_SIZE; ++i)
                library[i].displayBookDetails(i);

            showBooksFooter();
            showStatusBar(library, LIBRARY_SIZE);

            waitForEnter();
            continue;
        }

        // For anything that is not 2 or 3, show error and go back
        if (choice != 2 && choice != 3)
        {
            showInvalidOptionMessage();
            waitForEnter();
            continue;
        }

        // ---------------------------------------------------------------------
        // Borrow / Return need ISBN
        // ---------------------------------------------------------------------
        if (choice == 2)
            showBorrowHeader();
        else
            showReturnHeader();

        showISBNPrompt();
        cin >> isbn;

        // Search for the book
        int bookIndex = findByISBN(library, LIBRARY_SIZE, isbn);

        if (bookIndex == -1)
        {
            showBookNotFoundMessage(isbn);
            waitForEnter();
            continue;
        }

        // ---------------------------------------------------------------------
        // Borrow the book
        // ---------------------------------------------------------------------
        if (choice == 2)
        {
            if (library[bookIndex].borrowBook())
            {
                showBorrowSuccessMessage();
                library[bookIndex].displayBookDetails();
            }
            else
            {
                showAlreadyBorrowedMessage();
            }
            waitForEnter();
        }
        // ---------------------------------------------------------------------
        // Return the book
        // ---------------------------------------------------------------------
        else if (choice == 3)
        {
            if (library[bookIndex].returnBook())
            {
                showReturnSuccessMessage();
                library[bookIndex].displayBookDetails();
            }
            else
            {
                showAlreadyAvailableMessage();
            }

            waitForEnter();
        }
    }

    return 0;
}
