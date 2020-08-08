#include "students.h"

Students::Students(uint64_t id, std::string name) {
    id_ = id;
    name_ = name;
}

void Students::borrowBooks(uint64_t bookId) {
    book_list_.push_back(bookId);
}

void Students::print() {
    std::cout << "Name : " << id_ << std::endl;
}
uint64_t Students::getID() {
    return id_;
}
