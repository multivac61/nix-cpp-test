cmake_minimum_required(VERSION 3.20)

project(Fibonacci
  VERSION 1.0.0
  DESCRIPTION "Calculate the n-th Fibonacci number"
  LANGUAGES CXX
)

add_library(${PROJECT_NAME} SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/src/fibonacci.cpp
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/fibonacci.h
)

target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Generate the pkg-config file: https://manpages.ubuntu.com/manpages/noble/en/man5/pc.5.html
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/pkg.pc.in 
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc 
  @ONLY
)

install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  PUBLIC_HEADER DESTINATION include
)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
  DESTINATION lib/pkgconfig
)

enable_testing()
add_subdirectory(tests)
