#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR=out/build/

# Change to the build directory
cd $BUILD_DIR

# Run the tests
./matrix_test

# Run every test using CTest(not required since we only have one test)
# cd $BUILD_DIR && ctest --output-on-failure --verbose

# Run valgrind on the test
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./matrix_test
