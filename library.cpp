#include "library.h"

/*
private:
    uint64_t total_books_nums;
    uint64_t total_students_nums;
    std::vector<Books> books;
    std::vector<Students> students;
*/

/*
void library::a(Books newBook) {
   books.push_back(newBook);
}
bool findBooks(std::string bookName);
bool findBooks(uint64_t book_id);
bool borrowBooks(std::string bookName, Students &student);
void printAllMsg();
*/
void library::addBooks(Books newbook) {
    books.push_back(newbook);
}

bool library::findBooks(std::string bookName, uint64_t &id) {
    bool res = false;
    for (auto &book : books) {
        if (book.name_ == bookName) {
            book.print();
            id = book.id_;
            res = true; 
            return res;
        }
    }
    return res;
}

bool library::borrowBooks(std::string bookName, Students &student) {
    uint64_t id = 0;
    if (findBooks(bookName, id) == false) {  // the diff the addr pointer and reference
        std::cout << "Sorry, can't find this book:" << bookName << std::endl;
    }
    student.borrowBooks(id);
    /*
    if (find(students.begin(), students.end(), student) == students.end()) {
        students.push_back(student);
    }
    */
    //std::cout << "[BORROW]:" << student.print() << " borrow book <<" << ">>!" << std::endl; 
    return true;
}

void library::printAllMsg() {
    for (auto &book : books) {
        book.print();
    }
}
