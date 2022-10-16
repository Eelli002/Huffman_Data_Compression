cmake_minimum_required(VERSION 3.20.2)

project(Huffman)

add_subdirectory(huffman/Huffman_Test/googletest)

enable_testing()

add_executable(${PROJECT_NAME}
    encryption/RSA.cpp
    encryption/encrypt_driver.cpp
    huffman/binary_in.cpp
    huffman/binary_out.cpp
    huffman/huffman.cpp
    main.cpp
    Main_Test.cpp
)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)

add_test(NAME AllTests COMMAND runAllTests)
