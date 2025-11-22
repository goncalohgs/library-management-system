#ifndef LIBRARY_USER_INTERFACE_H
#define LIBRARY_USER_INTERFACE_H

#include <string>
#include "Book.h"
using namespace std;

// Console colours
const string RESET = "\033[0m";
const string RED = "\033[38;2;220;60;60m";
const string GREEN = "\033[38;2;80;200;120m";
const string YELLOW = "\033[38;2;240;200;40m";
const string BLUE = "\033[38;2;50;140;255m";
const string CYAN = "\033[38;2;0;200;200m";
const string BOLD = "\033[1m";

// Core UI
void clearScreen();
void showBanner();
void showMenu();

// Books listing UI
void showBooksLoading();
void showBooksHeader();
void showBooksFooter();
void showStatusBar(Book library[], int size);

// Generic messages
void showInvalidInputMessage();
void showInvalidOptionMessage();
void showExitMessage();

// Borrow / Return section headers
void showBorrowHeader();
void showReturnHeader();

// ISBN prompt + errors
void showISBNPrompt();
void showBookNotFoundMessage(const string &isbn);

// Borrow / Return result messages
void showBorrowSuccessMessage();
void showAlreadyBorrowedMessage();
void showReturnSuccessMessage();
void showAlreadyAvailableMessage();

void waitForEnter();

#endif // LIBRARY_USER_INTERFACE_H
