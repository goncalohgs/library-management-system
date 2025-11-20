#ifndef LIBRARY_USER_INTERFACE_H
#define LIBRARY_USER_INTERFACE_H

#include <string>
#include "Book.h"

// Console colours
const string RESET = "\033[0m";
const string RED = "\033[38;2;220;60;60m";
const string GREEN = "\033[38;2;80;200;120m";
const string YELLOW = "\033[38;2;240;200;40m";
const string BLUE = "\033[38;2;50;140;255m";
const string CYAN = "\033[38;2;0;200;200m";
const string BOLD = "\033[1m";

// Show the top banner
void showBanner();

// Show main menu options
void showMenu();

// Show one book with separators (optional index)
void showBookWithSeparator(const Book &book, int index = -1);

#endif // LIBRARY_USER_INTERFACE_H