#include <iostream>
#include <vector>
#include <string>
#include "library.h"

using namespace std;

int main()
{
    library tmp_library;
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (int i = 0; i < 5; i++) {
        Books book(i, msg[i]);
        tmp_library.addBooks(book);
    }
    tmp_library.printAllMsg();
    Students student(0, "LiMing");
    tmp_library.borrowBooks("Hello", student);
}