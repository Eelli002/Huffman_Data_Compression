# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /class/classes/eelli002/final-project-scrumlins/src/huffman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build

# Include any dependencies generated for this target.
include Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/compiler_depend.make

# Include the progress variables for this target.
include Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/flags.make

Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/flags.make
Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: ../../Huffman_Test/googletest/googlemock/src/gmock-all.cc
Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o -MF CMakeFiles/gmock.dir/src/gmock-all.cc.o.d -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /class/classes/eelli002/final-project-scrumlins/src/huffman/Huffman_Test/googletest/googlemock/src/gmock-all.cc

Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /class/classes/eelli002/final-project-scrumlins/src/huffman/Huffman_Test/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /class/classes/eelli002/final-project-scrumlins/src/huffman/Huffman_Test/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

lib/libgmock.a: Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
lib/libgmock.a: Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/build.make
lib/libgmock.a: Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgmock.a"
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/build: lib/libgmock.a
.PHONY : Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/build

Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/clean

Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /class/classes/eelli002/final-project-scrumlins/src/huffman /class/classes/eelli002/final-project-scrumlins/src/huffman/Huffman_Test/googletest/googlemock /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock /class/classes/eelli002/final-project-scrumlins/src/huffman/out/build/Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Huffman_Test/googletest/googlemock/CMakeFiles/gmock.dir/depend

