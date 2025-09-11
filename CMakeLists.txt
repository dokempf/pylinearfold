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

# Compilation options
option(BUILD_PYTHON "Enable building of Python bindings" OFF)

# compile the library
add_subdirectory(src)

# compile the application
add_subdirectory(app)

# compile the tests
include(CTest)
if(BUILD_TESTING)
  add_subdirectory(ext/Catch2)
  include(./ext/Catch2/contrib/Catch.cmake)
  add_subdirectory(tests)
endif()

if(BUILD_PYTHON)
  # Add Python bindings
  find_package(pybind11 REQUIRED)
  # Compile the Pybind11 module
  pybind11_add_module(_pylinearfold python/pylinearfold/_pylinearfold.cpp)
  target_link_libraries(_pylinearfold PUBLIC pylinearfold)

  # Install the Python module shared library
  install(TARGETS _pylinearfold DESTINATION .)
endif()

# Add an alias target for use if this project is included as a subproject in
# another project
add_library(pylinearfold::pylinearfold ALIAS pylinearfold)

# Install targets and configuration
install(
  TARGETS pylinearfold
  EXPORT pylinearfold-config
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  EXPORT pylinearfold-config
  NAMESPACE pylinearfold::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/pylinearfold)

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This prints a summary of found dependencies
include(FeatureSummary)
feature_summary(WHAT ALL)
