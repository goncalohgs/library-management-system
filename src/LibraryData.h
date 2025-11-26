#ifndef LIBRARY_DATA_H
#define LIBRARY_DATA_H

#include "Book.h"

void populateLibrary(Book library[]);

int findByISBN(Book library[], int size, const string &isbn);

// Sorting (QuickSort)
void sortBookData(Book books[], int size);

#endif // LIBRARY_DATA_H