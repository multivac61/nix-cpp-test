cmake_minimum_required(VERSION 3.15)

project(Fibonacci_consumer)

find_package(ut CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::ut nlohmann_json::nlohmann_json sml::sml)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/../compile_commands.json)
