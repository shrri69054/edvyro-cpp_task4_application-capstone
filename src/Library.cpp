#include "Library.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

void Library::addBook(const Book& book) {
    for (const auto& b : books)
        if (b.id == book.id) return;
    books.push_back(book);
}

bool Library::borrowBook(int id) {
    for (auto& b : books) {
        if (b.id == id && b.available) {
            b.available = false;
            return true;
        }
    }
    return false;
}

bool Library::returnBook(int id) {
    for (auto& b : books) {
        if (b.id == id && !b.available) {
            b.available = true;
            return true;
        }
    }
    return false;
}

std::vector<Book> Library::search(const std::string& keyword) const {
    std::vector<Book> result;
    for (const auto& b : books)
        if (b.title.find(keyword) != std::string::npos ||
            b.author.find(keyword) != std::string::npos)
            result.push_back(b);
    return result;
}

double Library::availabilityRate() const {
    if (books.empty()) return 0.0;
    size_t available = 0;
    for (const auto& b : books) if (b.available) ++available;
    return 100.0 * available / books.size();
}

void Library::printReport() const {
    size_t available = 0;
    for (const auto& b : books) if (b.available) ++available;
    std::cout << "\n=== Library Report ===\n"
              << "Total books: " << books.size() << '\n'
              << "Available: " << available << '\n'
              << "Borrowed: " << books.size() - available << '\n'
              << "Availability: " << std::fixed << std::setprecision(1)
              << availabilityRate() << "%\n";
}

bool Library::save(const std::string& path) const {
    std::ofstream out(path);
    if (!out) return false;
    for (const auto& b : books)
        out << b.id << '|' << b.title << '|' << b.author << '|'
            << (b.available ? 1 : 0) << '\n';
    return true;
}

bool Library::load(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    books.clear();

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string id, title, author, available;
        std::getline(ss, id, '|');
        std::getline(ss, title, '|');
        std::getline(ss, author, '|');
        std::getline(ss, available, '|');
        try {
            addBook({std::stoi(id), title, author, std::stoi(available) == 1});
        } catch (...) {
            // Skip malformed rows instead of corrupting the application state.
        }
    }
    return true;
}

const std::vector<Book>& Library::all() const { return books; }
