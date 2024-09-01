#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR=out/build/

# Change to the build directory and run the tests
cd $BUILD_DIR && ./matrix_test

# Run every test using CTest(not required since we only have one test)
# cd $BUILD_DIR && ctest --output-on-failure --verbose
