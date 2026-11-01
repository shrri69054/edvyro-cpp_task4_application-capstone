#include "Library.h"
#include <cassert>
#include <iostream>

int main() {
    Library lib;
    lib.addBook({1, "C++", "A"});
    lib.addBook({2, "Algorithms", "B"});

    assert(lib.all().size() == 2);
    assert(!lib.borrowBook(99));
    assert(lib.borrowBook(1));
    assert(!lib.borrowBook(1));
    assert(lib.returnBook(1));
    assert(!lib.returnBook(1));
    assert(lib.search("Algo").size() == 1);

    std::cout << "Capstone tests passed.\n";
}
