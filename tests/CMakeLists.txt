SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

cmake_minimum_required(VERSION 3.10) 
# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib/Catch2)
add_subdirectory(PrimaryAlgorithmTests)
