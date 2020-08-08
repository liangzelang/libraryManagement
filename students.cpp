#include "students.h"

void Students::borrowBooks(uint64_t bookId) {
    book_list_.push_back(bookId);
}

void Students::print() {
    std::cout << "Name : " << id_ << std::endl;
}