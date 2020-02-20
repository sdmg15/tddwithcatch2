cmake_minimum_required(VERSION 3.10)

project(testTodo)

set(TEST_SOURCES testMain.cpp TestTodo.cpp)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})
add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE:${PROJECT_NAME}>)