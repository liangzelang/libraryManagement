#ifndef BOOKS_H_
#define BOOKS_H_
#include <string>

enum BooksType { liter, art, tech };
enum BooksStatus { in, out };

// （1）每种图书包含信息如：图书序号、图书名称、图书种类、图书总库存量、图书现库存量、作者、库存地点、借还状态等。
class Books {
  public:
    uint64_t id_;
    std::string name_;
    BooksType category_;
    uint64_t total_nums_;
    uint64_t rest_nums_;
    std::string author_;
    std::string place_;
    BooksType status_;
    Books()
      : id_(0),
        name_(""),
        category_(liter),
        total_nums_(0),
        reset_nums_(0),
        author_(""),
        place_(""),
        status_(in) {}
    ~Books() = default;
}

#endif