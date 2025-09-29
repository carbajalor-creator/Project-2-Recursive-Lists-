cmake_minimum_required(VERSION 3.30)
project(RecursiveListsProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(RecursiveListsProject main.cpp lex.cpp parser.cpp reclists.cpp solutions.cpp)
