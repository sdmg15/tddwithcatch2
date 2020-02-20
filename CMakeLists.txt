cmake_minimum_required(VERSION 3.10)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
project(todoTdd)

set(SOURCES main.cpp todo/Todo.hpp todo/Todo.cpp)

add_subdirectory(todo/tests)

add_executable(${PROJECT_NAME} ${SOURCES})
