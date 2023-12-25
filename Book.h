#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    std::string author;
    std::string category;
    int numberOfPages;
    std::string status;

    Book() {
        author = "";
        category = "";
        numberOfPages = 0;
        status = "";
    }
    
    Book(const std::string& author, const std::string& category, int numberOfPages, const std::string& status) {
        this->author = author;
        this->category = category;
        this->numberOfPages = numberOfPages;
        this->status = status;
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Author: " << book.author 
        << ", Category: " << book.category 
        << ", Pages: " << book.numberOfPages 
        << ", Status: " << book.status;
        return os;
    }
};

#endif
