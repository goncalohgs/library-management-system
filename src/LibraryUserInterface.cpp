#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "LibraryUserInterface.h"

using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[H";
}

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

    cout << CYAN << BOLD << "╔══════════════════════════════════════╗\n";
    cout << "║        Choice:                       ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << RESET;
}

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