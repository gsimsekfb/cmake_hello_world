cmake_minimum_required(VERSION 3.10)

# Enable C++17 features 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (hello)
add_executable(hello src/main.cpp)
