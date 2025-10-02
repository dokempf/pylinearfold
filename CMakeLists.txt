cmake_minimum_required(VERSION 3.9)

# Set a name and a version number for your project:
project(
  pylinearfold
  VERSION 0.0.1
  LANGUAGES CXX)

# Initialize some default paths
include(GNUInstallDirs)

# Define the minimum C++ standard that is required
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Build libraries for linearfold and linearpartition
add_library(linearfold SHARED ext/LinearFold/src/LinearFold.cpp)
target_include_directories(
  linearfold PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ext/LinearFold/src)
target_compile_definitions(linearfold PUBLIC lv)

add_library(linearpartition SHARED ext/LinearPartition/src/LinearPartition.cpp)
target_include_directories(
  linearpartition PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ext/LinearPartition/src)
target_compile_definitions(linearfold PUBLIC lv)

# Add Python bindings
find_package(pybind11 REQUIRED)
# Compile the Pybind11 module
pybind11_add_module(_pylinearfold pylinearfold/_pylinearfold.cpp)
target_link_libraries(_pylinearfold PUBLIC linearfold linearpartition)
set_target_properties(
  _pylinearfold
  PROPERTIES BUILD_RPATH "\$ORIGIN"
             INSTALL_RPATH "\$ORIGIN"
             INSTALL_RPATH_USE_LINK_PATH TRUE)

# Install the Python module shared library
install(TARGETS _pylinearfold linearfold linearpartition DESTINATION .)

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
