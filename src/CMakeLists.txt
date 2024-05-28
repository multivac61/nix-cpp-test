cmake_minimum_required(VERSION 3.15)

project(bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(ut CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Fibonacci REQUIRED)

add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::ut nlohmann_json::nlohmann_json acme::Fibonacci)

execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME})
