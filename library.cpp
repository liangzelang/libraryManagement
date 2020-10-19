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

void library::addBooks() {
    Books newbook;
    std::cin.clear();
    std::cin.sync();
    newbook.id_ = books.size();
    std::cout << "Please input books name:";
    std::cin >> newbook.name_;
    std::cout << "Please input books author:";
    std::cin >> newbook.author_;
    std::cout << "Please input books num:";
    std::cin >> newbook.sum_;
    newbook.rest_num_ = newbook.sum_;
    books.push_back(newbook);
}

uint64_t library::findBooks(std::string bookName, std::string author) {
    for (auto &book : books) {
        if (book.name_ == bookName && book.author_ == author) {
            book.print();
            return book.id_;
        }
    }
    return -1;
}

bool library::borrowBooks(std::string bookName, std::string author) {
    uint64_t id = findBooks(bookName, author);
    if (id != -1) {
        uint64_t tmp;
        std::cout << "Please input your usr_id:";
        std::cin >> tmp;
        if (tmp < students.size()) {
            if (students[tmp].borrow_nums_ >= 10) {
                std::cout << "sorry , you have already borrowed 10 books" << std::endl;
                return false;
            }
            students[tmp].book_list_.push_back(id);
            students[tmp].borrow_nums_++;
            students[tmp].total_nums_++;
            books[id].rest_num_--;
            books[id].can_borrow_ = (books[id].rest_num_ == 0) ? false : true;
            books[id].borrow_count_++; //redundent
            saveBooksInfo();
            saveStudentsInfo();
        } else {
            std::cout << "wrong usr_id" << std::endl;
            return false;
        }
    } else {
        std::cout << "Sorry, can't find this book:" << bookName << std::endl;
    }
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

bool library::compareBook(const Books &A, const Books &B) {
    return A.borrow_count_ > B.borrow_count_;
}

bool library::compareReader(const Students &A, const Students &B) {
    return A.borrow_nums_ > B.borrow_nums_;
}

void library::bookStatics() {
    sort(books.begin(), books.end(), compareBook);
}
void library::readerStatics() {
    sort(students.begin(), students.end(), compareReader);
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

void library::deleteBooks() {
    std::cin.sync();
    std::cin.clear();
    uint64_t temp = 0;
    std::cout << "Delete Books by id(0) or name(1): " << std::endl;
    std::cin >> temp;
    switch (temp) {
        case 0:
        {
            uint64_t books_id;
            std::cout << "Please input book id: " << std::endl;
            std::cin >> books_id;
            deleteBooks(books_id);
            break;
        }
        case 1:
        {
            std::string books_name;
            std::string books_author;
            std::cout << "Please input book name: " << std::endl;
            std::cin >> books_name;
            std::cout << "Please input book author: " << std::endl;
            std::cin >> books_author;
            deleteBooks(books_name, books_author);
            break;
        }
        default:
            break;
    }
}

void library::deleteBooks(std::string bookname, std::string author) {
    auto it = books.begin();
    while (it != books.end()) {
        if ((*it).name_ == bookname && (*it).author_ == author) {
            books.erase(it);
            saveBooksInfo();
            continue;
        }
        it++;
    }
    return;
}

void library::deleteBooks(uint64_t id) {
    auto it = books.begin();
    while(it != books.end()) {
        if ((*it).id_ == id) {
            books.erase(it); //erase后it迭代器会自动后移这个时候不再需要自增了
            saveBooksInfo();
            continue;
        }
        it++;
    }
    return;
}