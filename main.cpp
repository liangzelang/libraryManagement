#include <iostream>
#include <vector>
#include <string>
#include "library.h"

using namespace std;
void handleReader(library &library)
{
    uint64_t user_id;
    std::cout << "Please input your ID :";
    std::cin >> user_id;
    if (!library.findStudents(user_id)) {
        std::cout << "Invalid user id, please register." << std::endl;
        std::cout << "Would you like to register one count." << std::endl;
        std::cout << "1 : yes         0 : no" << std::endl;
        uint64_t tmp;
        std::cin >> tmp;
        if (tmp == 1) {
           Students temp;
           std::cout << "Input your user name : ";
           std::cin >>temp.name_;
           std::cin.clear();
           std::cin.sync();
           temp.id_ = library.students.size();
           user_id = temp.id_;
           temp.borrow_nums_ = 0;
           temp.total_nums_ = 0;
           library.students.push_back(temp);
           library.saveStudentsInfo();
        } else {
            std::cout << "Good Bye" << std::endl;
            return;
        }
    }
    // user_id is ok
    uint64_t tmp;
    do {
        std::cout << "Welcome to LIBRARY, " << library.students[user_id].name_ << std::endl;
        std::cout << "1. Show All Books" << std::endl;
        std::cout << "2. Borrow Books" << std::endl;
        std::cout << "3. Return Books" << std::endl;
        std::cout << "4. My Info" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> tmp;
        string bookname;
        string author;
        switch (tmp)
        {
        case 1:
            /* code */
            library.printAllMsg();
            break;
        case 2:
            std::cout << "input books name :";
            std::cin >> bookname;
            std::cout << "input author :";
            std::cin >> author;
            library.borrowBooks(bookname, author);
        default:
            break;
        }
    } while(tmp != 5);

}

int main()
{
    library tmp_library;
    int tmp = 0;
    std::cout << "Please choose user mode: \n"
              << "1 : reader  2 : adaminister" << std::endl;
    std::cin >> tmp;
    switch (tmp) {
        case 1:
            handleReader(tmp_library);
            break;
        case 2:
            std::cout << "Not support now" << std::endl;
            break;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
    }
    tmp_library.saveBooksInfo();  //保存图书信息
    tmp_library.saveStudentsInfo();  //保存学生信息
}