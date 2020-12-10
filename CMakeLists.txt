cmake_minimum_required(VERSION 3.17)
project(libraryManagement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(libraryManagement
        books.cpp
        books.h
        library.cpp
        library.h
        main.cpp
        students.cpp
        students.h)
