#include "Library.h"
#include <iostream>
#include <limits>

int main() {
    Library library;
    const std::string file = "library_data.txt";

    if (!library.load(file)) {
        library.addBook({1, "The C++ Book", "A. Programmer"});
        library.addBook({2, "Clean Code", "R. Martin"});
        library.addBook({3, "Algorithms", "T. Cormen"});
        library.save(file);
    }

    while (true) {
        std::cout << "\n=== C++ Library Capstone ===\n"
                  << "1. List books\n2. Search\n3. Borrow\n4. Return\n"
                  << "5. Report\n6. Save & exit\nChoose: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            for (const auto& b : library.all())
                std::cout << b.id << " | " << b.title << " | "
                          << b.author << " | "
                          << (b.available ? "Available" : "Borrowed") << '\n';
        } else if (choice == 2) {
            std::string keyword;
            std::cout << "Keyword: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, keyword);
            auto results = library.search(keyword);
            if (results.empty()) std::cout << "No matching books.\n";
            for (const auto& b : results)
                std::cout << b.id << " | " << b.title << " | " << b.author << '\n';
        } else if (choice == 3 || choice == 4) {
            int id;
            std::cout << "Book ID: ";
            if (!(std::cin >> id)) {
                std::cout << "Invalid ID.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            bool ok = (choice == 3) ? library.borrowBook(id) : library.returnBook(id);
            std::cout << (ok ? "Operation successful.\n" :
                                 "Operation rejected: check ID and current availability.\n");
        } else if (choice == 5) {
            library.printReport();
        } else if (choice == 6) {
            if (library.save(file)) std::cout << "Saved successfully.\n";
            else std::cout << "Save failed.\n";
            break;
        } else {
            std::cout << "Choose 1-6.\n";
        }
    }
}
