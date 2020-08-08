#ifndef BOOKS_H_
#define BOOKS_H_
#include <iostream>
#include <string>

enum BooksType { liter, art, tech };
enum BooksStatus { in, out };

// （1）每种图书包含信息如：图书序号、图书名称、图书种类、图书总库存量、图书现库存量、作者、库存地点、借还状态等。
class Books {
  public:
    uint64_t id_;
    std::string name_;
    Books()
      : id_(0),
        name_("NA") {}
    ~Books() = default;
    Books(uint64_t id, std::string name);
    void print();
};
#endif