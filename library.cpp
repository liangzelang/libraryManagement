#include "library.h"

library::library() {
  std::string file_name = "./books.txt";
  std::ifstream ifs(file_name);
  uint64_t allBooks;
  uint64_t allStudents;
  if (!ifs.is_open()) {
      std::cout << "can't open this file " << file_name << std::endl;
  }
  ifs >> allBooks; //第一行存储图书管理系统中一共的书籍数量
  for (uint64_t i = 0; i < allBooks; i++) {
      Books temp;
      ifs >> temp.id_ >> temp.name_;
      books.push_back(temp);
  }
  ifs.close();

  file_name = "./students.txt";
  ifs.open(file_name);
  if (!ifs.is_open()) {
      std::cout << "can't open this file" << file_name << std::endl;
  }
  ifs >> allStudents;
  for (uint64_t i = 0; i < allStudents; i++) {
      Students temp;
      ifs >> temp.id_ >> temp.name_ >> temp.borrow_nums_ >> temp.total_nums_;
      students.push_back(temp);
  }
  ifs.close();
}

library::~library() {
  std::string file_name = "./books.txt";
  std::ofstream ofs(file_name);
  std::cout << "Deinit class library" << std::endl;
  if (!ofs.is_open()) {
    std::cout << "can't open this file" << file_name << std::endl;
  }
  ofs << books.size() << "\n";
  for (auto &book : books) {
    ofs << book.id_ << " " << book.name_ << "\n";
  }
  ofs.close();

  file_name = "./students.txt";
  ofs.open(file_name);
  if (!ofs.is_open()) {
      std::cout << "can't open this file " << file_name << std::endl;
  }
  ofs << students.size() << "\n";
  for (auto &temp : students) {
      ofs << temp.id_ << " " << temp.name_ << " "
          << temp.borrow_nums_ << " " << temp.total_nums_ << "\n";
  }
  ofs.close();
}


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
void library::borrowBooks(std::string bookname, std::string author) {
    int64_t user_id = -1;
    bool flag = false;
    for (uint64_t i = 0; i < books.size(); i++) {
        if (books[i].name_ == bookname && books[i].author_ == author) {
            if (books[i].rest_num_) {
                std::cout << "Please input your ID :";
                std::cin >> user_id;
                if (students[user_id].borrow_nums_ >= 10) {
                    std::cout << "Sorry, you cannot borrow books more, you have borrowed 10 books" << std::endl;
                    break;
                }
                books[i].rest_num_--; //update library this books rest nums
                books[i].borrow_count_++; //update library this books borrow nums
                students[user_id].borrow_nums_++; //update books nums kept by this students
                students[user_id].book_list_.push_back(books[i].id_);
                books[i].can_borrow_ =  bool(books[i].rest_num_);
                students[user_id].book_list_.push_back(books[i].id_);
                total_borrow_nums++;
                flag = true;
            } else {
                std::cout << "All this books have been borrowed." << std::endl;
            }

        }
    }
    if (!flag) {
        std::cout << "Sorry, not find this book : " << bookname;
    }
}
bool library::borrowBooks(std::string bookName, Students &student) {
    uint64_t id = 0;
    if (findBooks(bookName, id) == false) {  // the diff the addr pointer and reference
        std::cout << "Sorry, can't find this book:" << bookName << std::endl;
    }
    student.borrowBooks(id);    
    auto iter = find_if(students.begin(), students.end(), [&](auto n) { return (n.getID() == student.getID()); });
    if (iter == students.end()) {    
        students.push_back(student);
    }
    std::cout << "[BORROW]:" << " borrow book <<" << bookName << ">>!" << std::endl;
    return true;
}

void library::returnBooks(std::string bookname, std::string author) {
    int64_t user_id = -1;
    bool flag = false;
    std::cout << "please input your id." << std::endl;
    std::cin >> user_id;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].name_ == bookname && books[i].author_ == author) {
            books[i].rest_num_++;
            books[i].can_borrow_=bool(books[i].rest_num_);
            books[i].borrow_count_--;
            students[user_id].borrow_nums_--;
            //auto it = books.begin() + books[i].id_;
            //students[user_id].book_list_.erase(book_list_.begin() + books[i].id_);
            total_return_nums++;
            flag = true;
        }
    }
    if (!flag) {
        std::cout << "Sorry cannot find this book under your credit" << std::endl;
    }

    void saveBooksInfo();  //保存图书信息
    void saveStudentsInfo();  //保存学生信息
}

void library::saveBooksInfo() {
  std::string file_name = "./books.txt";
  std::ofstream ofs(file_name);
  if (!ofs.is_open()) {
      std::cout << "Open failed :" << file_name;
  }
  ofs << books.size() << "\n"; //first line is book nums
  for (int i = 0; i < books.size(); i++) {
      ofs << books[i].id_ << " " << books[i].name_ << " "
          << books[i].author_ << " " << books[i].sum_ << " "
          << books[i].rest_num_ << " " << books[i].can_borrow_ << "\n";
  }
  ofs.close();
}

void library::saveStudentsInfo() {
  std::string file_name = "./students.txt";
  std::ofstream ofs(file_name);
  if (!ofs.is_open()) {
      std::cout << "Open failed :" << file_name;
  }
  ofs << students.size() << "\n";
  for (int i = 0; i < students.size(); i++) {
      ofs << students[i].id_ << " " << students[i].name_ << " "
          << students[i].total_nums_ << " " << students[i].borrow_nums_;
      for (int j = 0; j < students[i].book_list_.size(); j++) {
          ofs << " " << students[i].book_list_[j];
      }
      ofs << "\n";
  }
  ofs.close();
}

void library::printAllMsg() {
    for (auto &book : books) {
        book.print();
    }
}


bool library::findStudents(uint64_t user_id) {
    uint32_t size = students.size();
    for (uint32_t i = 0; i < size; i++) {
        if(students[i].id_ == user_id) {
            return true;
        }
    }
    return false;
}