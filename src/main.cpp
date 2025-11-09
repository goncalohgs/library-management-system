#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

int main()
{
    Book library[5];

    // Array of 5 books
    library[0].setBookDetails("The Golden Dawn", "Israel Regardie", "1111", true, "07/11/2025");
    library[1].setBookDetails("Neijing Suwen- The Yellow Emperor’s Classic of Medicine", "Maoshing Ni, PH. D", "2222", true, "07/11/2025");
    library[2].setBookDetails("Accelerated C++", "Andrew Koenig & Barbara E. Moo", "3333", true, "07/11/2025");
    library[3].setBookDetails("Think and Grow Rich", "Napolean Hill", "4444", true, "07/11/2025");
    library[4].setBookDetails("The Emerald Tablet of Thoth ", "Doreal", "5555", true, "07/11/2025");

    cout << " ==== Welcome to the Comunity Library Systemn ==== " << endl;
}
