#ifndef BOOKS_H_
#define BOOKS_H_
#include <iostream>
#include <string>

enum BooksType { liter, art, tech, None };
enum BooksStatus { in, out };

// （1）每种图书包含信息如：图书序号、图书名称、图书种类、图书总库存量、图书现库存量、作者、库存地点、借还状态等。
class Books {
  public:
    uint64_t id_;
    std::string name_;
    uint64_t borrow_count_;
    BooksType kind_;
    uint64_t price;
    uint64_t sum_;
    uint64_t rest_num_;
    std::string author_;
    uint64_t appointment_;
    bool can_borrow_;
    std::string borrow_date_;
    std::string return_date_;
    std::string place_;

    Books() : id_(0),
              name_("NA"),
              borrow_count_(0),
              kind_(BooksType::None),
              price(0),
              sum_(1),
              rest_num_(1),
              author_(""),
              appointment_(0),
              can_borrow_(true),
              borrow_date_(""),
              return_date_(""),
              place_("") {}
    ~Books() = default;
    Books(uint64_t id, std::string name);
    // check whether can borrow or not by id or name
    bool canBorrow(uint64_t id);
    bool canBorrow(std::string name);
    void print();
};
#endif