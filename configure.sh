#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the build directory
BUILD_DIR=out/build/

# Remove the build directory if it exists
rm -rf $BUILD_DIR

# Create the build directory if it doesn't exist
mkdir -p $BUILD_DIR

# Run CMake to configure the project
cmake -S . -B $BUILD_DIR
