#SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

cmake_minimum_required(VERSION 3.10) 

# project name and version
project(leetCode VERSION 1.0) 

include_directories(include)

# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("tests")
add_subdirectory("include")