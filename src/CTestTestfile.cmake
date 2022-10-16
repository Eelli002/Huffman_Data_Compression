# CMake generated Testfile for 
# Source directory: /class/classes/eelli002/final-project-scrumlins/src
# Build directory: /class/classes/eelli002/final-project-scrumlins/src
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[AllTests]=] "runAllTests")
set_tests_properties([=[AllTests]=] PROPERTIES  _BACKTRACE_TRIPLES "/class/classes/eelli002/final-project-scrumlins/src/CMakeLists.txt;21;add_test;/class/classes/eelli002/final-project-scrumlins/src/CMakeLists.txt;0;")
subdirs("huffman/Huffman_Test/googletest")
