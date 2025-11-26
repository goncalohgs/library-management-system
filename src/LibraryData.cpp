#include "LibraryData.h"
#include <utility>
#include <string>

void populateLibrary(Book library[])
{
    library[0].setBookDetails("The Golden Dawn",
                              "Israel Regardie",
                              "5111",
                              true,
                              "07/11/2025");

    library[1].setBookDetails("Neijing Suwen - The Yellow Emperor’s Classic of Medicine",
                              "Maoshing Ni, PH.D",
                              "2222",
                              true,
                              "07/11/2025");

    library[2].setBookDetails("Accelerated C++",
                              "Andrew Koenig & Barbara E. Moo",
                              "1333",
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

int findByISBN(Book library[], int size, const string &isbn)
{
    for (int i = 0; i < size; ++i)
        if (library[i].getISBN() == isbn)
            return i;
    return -1;
}

// helper to organise books around a pivot
static int splitBooks(Book books[], int left, int right)
{
    string pivotValue = books[right].getISBN(); // last element as pivot
    int smaller = left - 1;

    for (int pos = left; pos < right; pos++)
    {
        // if ISBN is "smaller", keep it on the left side
        if (books[pos].getISBN() < pivotValue)
        {
            smaller++;
            swap(books[smaller], books[pos]);
        }
    }

    // put pivot in the correct place
    swap(books[smaller + 1], books[right]);
    return smaller + 1;
}

// QuickSort
static void runQuickSort(Book books[], int start, int end)
{
    if (start < end)
    {
        int pivotSpot = splitBooks(books, start, end);
        runQuickSort(books, start, pivotSpot - 1);
        runQuickSort(books, pivotSpot + 1, end);
    }
}

// Public function
void sortBookData(Book books[], int count)
{
    if (count > 1)
        runQuickSort(books, 0, count - 1);
}
