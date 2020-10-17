#ifndef LIBRARY_H_
#define LIBRARY_H_
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "books.h"
#include "students.h"

class library
{
public:
    uint64_t total_books_nums;
    uint64_t total_students_nums;
    uint64_t total_borrow_nums;
    uint64_t total_return_nums;
    std::vector<Books> books;
    std::vector<Students> students;
    
    library();
    ~library();
    void addBooks(Books newBook); //上架图书
    void addBooks();
    void deleteBooks();
    void deleteBooks(std::string bookname, std::string author);  //下架图书
    void deleteBooks(uint64_t id); //下架图书
    bool borrowBooks(std::string bookname, std::string author); //借阅图书
    void returnBooks(std::string bookname, std::string author); //归还图书
    uint64_t findBooks(std::string bookName, std::string author);
    bool findStudents(uint64_t user_id);
    void printAllMsg();  //输出系统所有图书
    void saveBooksInfo();  //保存图书信息
    void saveStudentsInfo();  //保存学生信息
    int getBorrowNum();//获取本月外借量
    int getReturnNum();//获取本月还书量
};
#endif