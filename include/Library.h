#pragma once
#include <string>
#include <vector>

struct Book {
    int id;
    std::string title;
    std::string author;
    bool available{true};
};

class Library {
    std::vector<Book> books;
public:
    void addBook(const Book& book);
    bool borrowBook(int id);
    bool returnBook(int id);
    std::vector<Book> search(const std::string& keyword) const;
    double availabilityRate() const;
    void printReport() const;
    bool save(const std::string& path) const;
    bool load(const std::string& path);
    const std::vector<Book>& all() const;
};
