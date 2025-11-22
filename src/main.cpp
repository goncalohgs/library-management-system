#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>

#include "Book.h"
#include "LibraryUserInterface.h"
#include "LibraryData.h"

using namespace std;

const int LIBRARY_SIZE = 5;

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

void waitForEnter()
{
    cout << YELLOW << "\n\nPress Enter to return to the menu..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
    cin.get();                                           // wait for Enter
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
    int choice = -1;
    string isbn;

    // Main menu loop (keeps repeating until user enters 0)
    while (true)
    {
        clearScreen();

        showBanner();

        showMenu();

        // Move cursor up 2 lines (into the box) and right after "Choice: "
        cout << "\033[2A";  // move cursor up 2 lines
        cout << "\033[18C"; // move cursor right 18 columns (adjust if needed)

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
            cout << CYAN << "Loading books";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
            cout << RESET << "\n\n";
            cout << CYAN << BOLD
                 << "\n═════════════════════════════ Books Available ═════════════════════════════\n\n\n"
                 << RESET;

            for (int i = 0; i < LIBRARY_SIZE; ++i)
            {

                library[i].displayBookDetails(i);
            }

            cout << CYAN << "\n\n\n══════════════════════════════════════════════════════════════════════════\n"
                 << RESET;
            showStatusBar(library, LIBRARY_SIZE);

            // Pause
            waitForEnter();
            continue;
        }

        // For anything that is not 2 or 3, show error and go back
        if (choice != 2 && choice != 3)
        {
            cout << RED << "\n❗Invalid option.\n"
                 << RESET;
            waitForEnter();

            continue;
        }

        // ---------------------------------------------------------------------
        // Borrow / Return need ISBN
        // ---------------------------------------------------------------------
        if (choice == 2)
        {
            cout << BOLD << BLUE << "\n=== Borrow Book ===\n"
                 << RESET;
        }
        else if (choice == 3)
        {
            cout << BOLD << BLUE << "\n=== Return Book ===\n"
                 << RESET;
        }

        cout << BOLD << YELLOW << "\nPlease enter the ISBN: " << RESET;
        cin >> isbn;

        // Search for the book
        int bookIndex = findByISBN(library, LIBRARY_SIZE, isbn);

        if (bookIndex == -1)
        {
            cout << RED << "\n❗ Book with ISBN " << isbn << " not found." << RESET << endl;
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
                cout << GREEN << BOLD << "✅ Book borrowed successfully!\n"
                     << RESET;

                library[bookIndex].displayBookDetails();
            }
            else
            {
                cout << RED << BOLD << "⚠ This book is already borrowed.\n"
                     << RESET;
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
                cout << GREEN << "\n✅ Book returned successfully!\n"
                     << RESET;
                library[bookIndex].displayBookDetails();
            }
            else
            {
                cout << YELLOW << "\n⚠ This book is already available.\n"
                     << RESET;
            }

            waitForEnter();
        }
    }

    return 0;
}
