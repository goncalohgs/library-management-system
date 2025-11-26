#include <iostream>
#include "Book.h"
#include "LibraryData.h"

using namespace std;

int main()
{
    // Initialization

    Book firstBook;
    Book secondBook;
    Book thirdBook;

    firstBook.setBookDetails("The Golden Dawn",
                             "Israel Regardie",
                             "1111",
                             true,
                             "07/11/2025");

    secondBook.setBookDetails("Neijing Suwen - The Yellow Emperor’s Classic of Medicine",
                              "Maoshing Ni, PH.D",
                              "2222",
                              true,
                              "07/11/2025");

    thirdBook.setBookDetails("Accelerated C++",
                             "Andrew Koenig & Barbara E. Moo",
                             "3333",
                             true,
                             "07/11/2025");
}
