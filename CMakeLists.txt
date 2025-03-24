cmake_minimum_required(VERSION 3.10)

# Set the project name
project(C_Plus_Plus)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# You can list additional source files like this:
add_executable(main src/main.cpp src/TwoPointers.cpp src/ArrayHashing.cpp src/Graph.cpp)
add_exectuable(mutex src/mutex.cpp)

# Enable testing
enable_testing()

# Find GoogleTest package installed system-wide
find_package(GTest REQUIRED)

# Add the test executable
add_executable(MyTests tests/test_main.cpp src/TwoPointers.cpp src/ArrayHashing.cpp src/Graph.cpp)

# Link against the system-installed GTest
target_link_libraries(MyTests GTest::GTest GTest::Main)