cmake_minimum_required(VERSION 3.22.1)

# Set the project name
project(matrix-slayer VERSION 1.0)

# Define variables for the library and test names
set(LIBRARY_NAME matrixslayer)
set(TEST_NAME matrix_test)

# Add the library
add_library(${LIBRARY_NAME} STATIC src/Matrix.cpp)

# Specify the include directories for the library
target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set the C++ standard to C++17
set_target_properties(${LIBRARY_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED YES)

# Set the most paranoid properties for g++
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${LIBRARY_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wshadow
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Wcast-align
        -Woverloaded-virtual
        -Wconversion
        -Wsign-conversion
        -Wmisleading-indentation
        -Wduplicated-cond
        -Wduplicated-branches
    )
endif()

# Enable testing
enable_testing()

# Find GoogleTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add an executable for the test
add_executable(${TEST_NAME} test/Matrix_test.cpp)

# Link the test executable with the library
target_link_libraries(${TEST_NAME} PRIVATE ${LIBRARY_NAME} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

# Add a test
add_test(NAME MatrixTest COMMAND ${TEST_NAME})
