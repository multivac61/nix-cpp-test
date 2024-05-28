cmake_minimum_required(VERSION 3.22)

project(Fibonacci
    VERSION 0.0.1
    DESCRIPTION "C++ Fibonacci sequence generator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

# global debug postfix for libraries (executables still need to set it)
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Filename postfix for libraries under DEBUG configuration")

add_library(${PROJECT_NAME} src/Fibonacci.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(FetchContent)
FetchContent_Declare(
  PACKAGEPROJECT.CMAKE
  GIT_REPOSITORY      https://github.com/TheLartians/PackageProject.cmake
  GIT_TAG MD5=2d8a4685857c768da7ad1d8a7c6e07b1b5285cca
)
FetchContent_MakeAvailable(PACKAGEPROJECT.CMAKE)

packageProject(
  # the name of the target to export
  NAME ${PROJECT_NAME}
  # the version of the target to export
  VERSION ${PROJECT_VERSION}
  # a temporary directory to create the config files
  BINARY_DIR ${PROJECT_BINARY_DIR}
  # location of the target's public headers
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
  # should match the target's INSTALL_INTERFACE include directory
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
  # (optional) option to install only header files with matching pattern
  INCLUDE_HEADER_PATTERN "*.h"
  # semicolon separated list of the project's dependencies
  # DEPENDENCIES "fmt 7.1.3;cxxopts 2.2.0"
  # (optional) create a header containing the version info
  # Note: that the path to headers should be lowercase
  # VERSION_HEADER "${PROJECT_NAME}/version.h"
  # (optional) create a export header using GenerateExportHeader module
  # EXPORT_HEADER "${PROJECT_NAME}/export.h"
  # (optional) install your library with a namespace (Note: do NOT add extra '::')
  NAMESPACE acme
  # (optional) define the project's version compatibility, defaults to `AnyNewerVersion`
  # supported values: `AnyNewerVersion|SameMajorVersion|SameMinorVersion|ExactVersion`
  COMPATIBILITY AnyNewerVersion
  # (optional) option to disable the versioning of install destinations
  DISABLE_VERSION_SUFFIX YES
  # (optional) option to ignore target architecture for package resolution
  # defaults to YES for header only (i.e. INTERFACE) libraries
  # ARCH_INDEPENDENT YES
  # (optional) option to generate CPack variables
  # CPACK YES
)

enable_testing()
add_subdirectory(tests)
