cmake_minimum_required(VERSION 3.10) 

# specify the C++ standard 
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib/Catch2)

file(GLOB TESTS 
    *.cpp
)
add_executable(unit_tests ${TESTS})
target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(unit_tests PRIVATE unit_test_lib)


# These tests need their own main
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

# These tests can use the Catch2-provided main
