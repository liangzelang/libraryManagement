#ifndef STUDENTS_H_
#define STUDENTS_H_
#include <iostream>
#include <vector>

class Students
{
private:
    /* data */
    uint64_t id_;
    std::vector<uint64_t> book_list_;
public:
    Students()
      : id_(0) {};
    ~Students() = default;
    void borrowBooks(uint64_t bookId);
    void print();
};
#endif