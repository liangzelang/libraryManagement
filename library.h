#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include <algorithm>
#include <vector>
#include "books.h"
#include "students.h"

class library
{
private:
    /* data */
    uint64_t total_books_nums;
    uint64_t total_students_nums;
    std::vector<Books> books;
    std::vector<Students> students;
public:
    
    library()
    : total_books_nums(0),
        total_students_nums(0) {};
    ~library() = default;

    void addBooks(Books newBook);
    bool findBooks(std::string bookName, uint64_t &id);
    bool findBooks(uint64_t book_id);
    bool borrowBooks(std::string bookName, Students &student);
    void printAllMsg();
};

#endif