cmake_minimum_required(VERSION 3.15)

project(Fibonacci_test)

find_package(ut CONFIG REQUIRED)

add_executable(${PROJECT_NAME} test_fibonacci.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::ut acme::Fibonacci)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
