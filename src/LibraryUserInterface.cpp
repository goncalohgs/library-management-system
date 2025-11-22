#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "LibraryUserInterface.h"

using namespace std;

// Clear whole screen
void clearScreen()
{
    cout << "\033[2J\033[H";
}

// Banner at top
void showBanner()
{
    cout << CYAN << BOLD;
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║        COMMUNITY LIBRARY SYSTEM      ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << RESET;
}

// Main menu with box for choice (we move cursor into it in main)
void showMenu()
{
    cout << BLUE << BOLD;
    cout << "\n📘  1 - View All Books\n\n";
    cout << "📕  2 - Borrow Book\n\n";
    cout << "📗  3 - Return Book\n\n";
    cout << "🚪  0 - Exit\n\n";
    cout << RESET;

    cout << BOLD << "╔══════════════════════════════════════╗\n";
    cout << "║        Choice:                       ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << RESET;
}

// Loading animation before listing books
void showBooksLoading()
{
    cout << CYAN << "\n\nLoading books";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    cout << RESET << "\n\n";
}

// Header above book list
void showBooksHeader()
{
    cout << CYAN << BOLD
         << "══════════════════════════════ Books Available "
            "══════════════════════════════\n\n"
         << RESET;
}

// Footer below book list
void showBooksFooter()
{
    cout << CYAN
         << "\n════════════════════════════════════════════════════════════════════════════\n"
         << RESET;
}

// Status bar at bottom
void showStatusBar(Book library[], int size)
{
    int total = size;
    int available = 0;

    for (int i = 0; i < size; ++i)
    {
        if (library[i].getAvailability())
            ++available;
    }

    int borrowed = total - available;

    cout << "\n";
    cout << CYAN << "╔══════════════ Library Status ═══════════════╗\n"
         << RESET;
    cout << "  Total:      " << total
         << "    " << GREEN << "Available: " << available << RESET
         << "    " << YELLOW << "Borrowed: " << borrowed << RESET << "\n";
    cout << CYAN << "╚═════════════════════════════════════════════╝\n"
         << RESET;
}

// ---------------------- Generic messages ----------------------

void showInvalidInputMessage()
{
    cout << RED << "\nInvalid input. Please enter a number.\n"
         << RESET;
}

void showInvalidOptionMessage()
{
    cout << RED << "\n❗Invalid option.\n"
         << RESET;
}

void showExitMessage()
{
    cout << GREEN << "\nExiting program.\n"
         << RESET;
}

// ---------------------- Borrow / Return headers ----------------------

void showBorrowHeader()
{
    cout << BOLD << BLUE << "\n\n\n=== Borrow Book ===\n"
         << RESET;
}

void showReturnHeader()
{
    cout << BOLD << BLUE << "\n=== Return Book ===\n"
         << RESET;
}

// ---------------------- ISBN prompt + errors ----------------------

void showISBNPrompt()
{
    cout << BOLD << YELLOW << "\nPlease enter the ISBN: " << RESET;
}

void showBookNotFoundMessage(const string &isbn)
{
    cout << RED << "\n❗ Book with ISBN " << isbn << " not found.\n"
         << RESET;
}

// ---------------------- Borrow / return result messages ----------------------

void showBorrowSuccessMessage()
{
    cout << GREEN << BOLD << "\n✅ Book borrowed successfully!\n"
         << RESET;
}

void showAlreadyBorrowedMessage()
{
    cout << RED << BOLD << "\n⚠ This book is already borrowed.\n"
         << RESET;
}

void showReturnSuccessMessage()
{
    cout << GREEN << BOLD << "\n✅ Book returned successfully!\n"
         << RESET;
}

void showAlreadyAvailableMessage()
{
    cout << YELLOW << BOLD << "\n⚠ This book is already available.\n"
         << RESET;
}

void waitForEnter()
{
    cout << YELLOW << "\n\nPress Enter to return to the menu..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover input
    cin.get();                                           // wait for Enter
}