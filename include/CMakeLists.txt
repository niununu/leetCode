#SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

cmake_minimum_required(VERSION 3.10) 

# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_subdirectory("PrimaryAlgorithm")

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES 
    PrimaryAlgorithm/*.h
)

#add_library(PrimaryAlgorithmTestsLib ${SOURCES})
#set_property(TARGET PrimaryAlgorithmTestsLib PROPERTY FOLDER Src)