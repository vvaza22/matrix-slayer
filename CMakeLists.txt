cmake_minimum_required(VERSION 3.22.1)

# Set the project name
project(matrix-slayer VERSION 1.0)

# Define variables for the library and test names
set(LIBRARY_NAME matrixslayer)
set(TEST_NAME matrix_test)

# Recursively find all .cpp files in the src directory
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# Add the library
add_library(${LIBRARY_NAME} STATIC ${SRC_FILES})

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

# Get all .cpp files in the test directory
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

# Iterate over each test source file
foreach(TEST_SOURCE ${TEST_SOURCES})
    # Get the filename without the directory and extension
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # Add an executable for each test source file
    add_executable(${TEST_NAME} ${TEST_SOURCE})

    # Link the test executable with the library and GoogleTest
    target_link_libraries(${TEST_NAME} PRIVATE ${LIBRARY_NAME} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})

    # Add a test for each executable
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
