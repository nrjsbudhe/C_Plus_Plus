cmake_minimum_required(VERSION 3.10)

# Set the project name
project(C_Plus_Plus)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# You can list additional source files like this:
add_executable(main src/main.cpp src/TwoPointers.cpp)

# Add GTest
add_subdirectory(external/googletest)

# Include directories for GTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add the test executable
add_executable(MyTests tests/test_main.cpp src/TwoPointers.cpp)

# Link test executable against GTest and GTest main
target_link_libraries(MyTests gtest gtest_main)