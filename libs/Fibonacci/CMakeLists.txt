cmake_minimum_required(VERSION 3.22)

project(Fibonacci_consumer
    VERSION 0.0.1
    DESCRIPTION "Consumer of the Fibonacci sequence"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

# global debug postfix for libraries (executables still need to set it)
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Filename postfix for libraries under DEBUG configuration")

add_library(${PROJECT_NAME} src/Fibonacci.cpp)
add_library(acme::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "include/acme/Fibonacci.h")

# install the target and create export-set
install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}Targets"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# generate and install export file
install(EXPORT "${PROJECT_NAME}Targets"
    FILE "${PROJECT_NAME}Targets.cmake"
    NAMESPACE acme::
    DESTINATION "share/${PROJECT_NAME}"
)

# generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    COMPATIBILITY AnyNewerVersion
)
# create config file
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "share/${PROJECT_NAME}"
)
# install config files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "share/${PROJECT_NAME}"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json)

enable_testing()
add_subdirectory(tests)
