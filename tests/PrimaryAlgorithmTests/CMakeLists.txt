SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

cmake_minimum_required(VERSION 3.10) 
# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

# project name and version
project(PrimaryAlgorithmTests VERSION 1.0)

file(GLOB TESTS 
    *.cpp
)

add_executable(PrimaryAlgorithmTests ${TESTS})
target_link_libraries(PrimaryAlgorithmTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(PrimaryAlgorithmTests PRIVATE PrimaryAlgorithmTestsLib)
set_property(TARGET PrimaryAlgorithmTests PROPERTY FOLDER UnitTests)