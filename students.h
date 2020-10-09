#ifndef STUDENTS_H_
#define STUDENTS_H_
#include <iostream>
#include <vector>

class Students
{
public:
    /* data */
    uint64_t id_;
    std::string name_;
    std::vector<uint64_t> book_list_;
    uint64_t total_nums_;
    uint64_t borrow_nums_;

    Students()
      : id_(0),
        name_("NA") {};
    ~Students() = default;
    Students(uint64_t id, std::string name);
    uint64_t getID();
    void borrowBooks(uint64_t bookId);
    void print();
};
#endif