#include "books.h"
/*
    uint64_t id_;
    std::string name_;
    BooksType category_;
    uint64_t total_nums_;
    uint64_t rest_nums_;
    std::string author_;
    std::string place_;
    BooksStatus status_; 
 */

Books::Books(uint64_t id, std::string name) {
    id_ = id;
    name_ = name;
}
void Books::print() {
    std::cout << "id : " << id_ << "name : " << name_ << std::endl;
}