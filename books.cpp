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
    borrow_count_ = 0;
    kind_ = BooksType::None;
    price = 0;
    sum_ = 1;
    rest_num_ = 1;
    author_ = "";
    appointment_ = 0;
    can_borrow_ = true;
    borrow_date_ = "";
    return_date_ = "";
    place_ =  "";
}
void Books::print() {
    std::cout << "id : " << id_ << "  name : " << name_ << std::endl;
}