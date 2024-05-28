cmake_minimum_required(VERSION 3.15)

project(bin)

find_package(ut CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Fibonacci CONFIG REQUIRED)

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::ut nlohmann_json::nlohmann_json acme::Fibonacci)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME})
