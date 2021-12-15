cmake_minimum_required(VERSION 3.10) 

# project name and version
project(leetCode VERSION 1.0) 

include_directories(include)

#aux_source_directory(src DIR_SRCS)



# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory("tests")

# puts all .cpp files inside src to the SOURCES variable
file(GLOB SOURCES 
    src/*.cpp
    include/*.h
)

add_library(unit_test_lib ${SOURCES})
#add_executable(Example ${DIR_SRCS})
#add_executable(Example ${SOURCES})