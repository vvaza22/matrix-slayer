#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR=build/

# Change to the build directory
cd $BUILD_DIR

# Run the test
# ./matrix_test

# Run every test using CTest(not required since we only have one test)
ctest --output-on-failure --verbose

# Run valgrind on the tests
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ctest
