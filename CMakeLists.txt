cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(
  pylinearfold
  VERSION 0.0.1
  LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add Python bindings
find_package(pybind11 REQUIRED)
# Compile the Pybind11 module
pybind11_add_module(_pylinearfold pylinearfold/_pylinearfold.cpp)

# Install the Python module shared library
install(TARGETS _pylinearfold DESTINATION .)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
