cmake_minimum_required(VERSION 3.16)
project(CppLibraryCapstone LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(library_app src/main.cpp src/Library.cpp)
target_include_directories(library_app PRIVATE include)

add_executable(library_tests tests.cpp src/Library.cpp)
target_include_directories(library_tests PRIVATE include)
