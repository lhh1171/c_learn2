# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/CLion-2020.1.3/clion-2020.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/CLion-2020.1.3/clion-2020.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lqc/CLionProjects/epollTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lqc/CLionProjects/epollTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/epollTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/epollTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/epollTest.dir/flags.make

CMakeFiles/epollTest.dir/main.cpp.o: CMakeFiles/epollTest.dir/flags.make
CMakeFiles/epollTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/epollTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/epollTest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/epollTest.dir/main.cpp.o -c /home/lqc/CLionProjects/epollTest/main.cpp

CMakeFiles/epollTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/epollTest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lqc/CLionProjects/epollTest/main.cpp > CMakeFiles/epollTest.dir/main.cpp.i

CMakeFiles/epollTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/epollTest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lqc/CLionProjects/epollTest/main.cpp -o CMakeFiles/epollTest.dir/main.cpp.s

# Object files for target epollTest
epollTest_OBJECTS = \
"CMakeFiles/epollTest.dir/main.cpp.o"

# External object files for target epollTest
epollTest_EXTERNAL_OBJECTS =

epollTest: CMakeFiles/epollTest.dir/main.cpp.o
epollTest: CMakeFiles/epollTest.dir/build.make
epollTest: CMakeFiles/epollTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lqc/CLionProjects/epollTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable epollTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/epollTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/epollTest.dir/build: epollTest

.PHONY : CMakeFiles/epollTest.dir/build

CMakeFiles/epollTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/epollTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/epollTest.dir/clean

CMakeFiles/epollTest.dir/depend:
	cd /home/lqc/CLionProjects/epollTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lqc/CLionProjects/epollTest /home/lqc/CLionProjects/epollTest /home/lqc/CLionProjects/epollTest/cmake-build-debug /home/lqc/CLionProjects/epollTest/cmake-build-debug /home/lqc/CLionProjects/epollTest/cmake-build-debug/CMakeFiles/epollTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/epollTest.dir/depend

