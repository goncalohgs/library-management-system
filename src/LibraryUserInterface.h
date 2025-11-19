#include <string>
#include "Book.h"

// Console colours
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

// Show the top banner
void showBanner();

// Show main menu options
void showMenu();

// Show one book with separators (optional index)
void showBookWithSeparator(const Book &book, int index = -1);
