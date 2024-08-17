cmake_minimum_required(VERSION 3.10)

# Set the project name
project(C_Plus_Plus)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories
include_directories(include)

# Add the executable
# add_executable(MyExecutable src/Main.cpp)

# You can list additional source files like this:
add_executable(main src/main.cpp src/TwoPointers.cpp)

# # Optionally, include tests
# add_subdirectory(tests)