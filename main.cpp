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
        std::cout << "Welcome to LIBRARY: \n" 
                  << "Please remember your usr_name: " << library.students[user_id].name_
                  << "your usr_id: " << user_id << std::endl;
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

void handleAdam(library &library)
{
    std::string pwd;
    bool flag = false;
    for (uint32_t i = 0; i < 3; i++) {
        std::cout << "Please input your pwd :";
        std::cin >> pwd;
        if (pwd != "123456") {
            std::cout << "Invalid pwd." << std::endl;
            continue;
        }
        std::cout << "Pwd is OK" << std::endl;
        flag = true;
        break;
    }

    if (flag) {
        uint64_t tmp;
        do {
            std::cin.clear();
            std::cin.sync();
            std::cout << "Welcome, Adaminister." << "\n"
                        << "1: Add Books" << "\n"
                        << "2: Remove Books" << "\n"
                        << "3: Show All Books" << "\n"
                        << "4: books statics" << "\n"
                        << "5: students statics" << "\n"
                        << "6: Quit" << std::endl;
            std::cin >> tmp;
            switch (tmp) {
                case 1:
                    library.addBooks();
                    break;
                case 2:
                    library.deleteBooks(0);
                    break;
                case 3:
                    library.printAllMsg();
                    break;
                case 4:
                    std::cout << "not supported now" << std::endl;
                    break;
                case 5:
                    std::cout << "not supported now" << std::endl;
                    break;
                default:
                    break;
            }
        } while(tmp != 6);
    }
    return;
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
            handleAdam(tmp_library);
            break;
        default:
            std::cout << "Invalid Input" << std::endl;
            break;
    }
    tmp_library.saveBooksInfo();  //保存图书信息
    tmp_library.saveStudentsInfo();  //保存学生信息
}