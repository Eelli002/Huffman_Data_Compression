cmake_minimum_required(VERSION 3.20.2)

project(Huffman)

add_subdirectory(googletest)

enable_testing()

add_executable(${PROJECT_NAME}
    ../src/binary_in.cpp
    ../src/binary_out.cpp
    ../src/huffman.cpp
    test.cpp
)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)

add_test(NAME AllTests COMMAND runAllTests)