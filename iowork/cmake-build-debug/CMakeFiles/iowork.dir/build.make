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
CMAKE_SOURCE_DIR = /home/lqc/CLionProjects/iowork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lqc/CLionProjects/iowork/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/iowork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/iowork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iowork.dir/flags.make

CMakeFiles/iowork.dir/main.cpp.o: CMakeFiles/iowork.dir/flags.make
CMakeFiles/iowork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/iowork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iowork.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iowork.dir/main.cpp.o -c /home/lqc/CLionProjects/iowork/main.cpp

CMakeFiles/iowork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iowork.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lqc/CLionProjects/iowork/main.cpp > CMakeFiles/iowork.dir/main.cpp.i

CMakeFiles/iowork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iowork.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lqc/CLionProjects/iowork/main.cpp -o CMakeFiles/iowork.dir/main.cpp.s

CMakeFiles/iowork.dir/mutiThread.cpp.o: CMakeFiles/iowork.dir/flags.make
CMakeFiles/iowork.dir/mutiThread.cpp.o: ../mutiThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/iowork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/iowork.dir/mutiThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iowork.dir/mutiThread.cpp.o -c /home/lqc/CLionProjects/iowork/mutiThread.cpp

CMakeFiles/iowork.dir/mutiThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iowork.dir/mutiThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lqc/CLionProjects/iowork/mutiThread.cpp > CMakeFiles/iowork.dir/mutiThread.cpp.i

CMakeFiles/iowork.dir/mutiThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iowork.dir/mutiThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lqc/CLionProjects/iowork/mutiThread.cpp -o CMakeFiles/iowork.dir/mutiThread.cpp.s

CMakeFiles/iowork.dir/file.cpp.o: CMakeFiles/iowork.dir/flags.make
CMakeFiles/iowork.dir/file.cpp.o: ../file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/iowork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/iowork.dir/file.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iowork.dir/file.cpp.o -c /home/lqc/CLionProjects/iowork/file.cpp

CMakeFiles/iowork.dir/file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iowork.dir/file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lqc/CLionProjects/iowork/file.cpp > CMakeFiles/iowork.dir/file.cpp.i

CMakeFiles/iowork.dir/file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iowork.dir/file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lqc/CLionProjects/iowork/file.cpp -o CMakeFiles/iowork.dir/file.cpp.s

CMakeFiles/iowork.dir/file2.cpp.o: CMakeFiles/iowork.dir/flags.make
CMakeFiles/iowork.dir/file2.cpp.o: ../file2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lqc/CLionProjects/iowork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/iowork.dir/file2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iowork.dir/file2.cpp.o -c /home/lqc/CLionProjects/iowork/file2.cpp

CMakeFiles/iowork.dir/file2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iowork.dir/file2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lqc/CLionProjects/iowork/file2.cpp > CMakeFiles/iowork.dir/file2.cpp.i

CMakeFiles/iowork.dir/file2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iowork.dir/file2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lqc/CLionProjects/iowork/file2.cpp -o CMakeFiles/iowork.dir/file2.cpp.s

# Object files for target iowork
iowork_OBJECTS = \
"CMakeFiles/iowork.dir/main.cpp.o" \
"CMakeFiles/iowork.dir/mutiThread.cpp.o" \
"CMakeFiles/iowork.dir/file.cpp.o" \
"CMakeFiles/iowork.dir/file2.cpp.o"

# External object files for target iowork
iowork_EXTERNAL_OBJECTS =

iowork: CMakeFiles/iowork.dir/main.cpp.o
iowork: CMakeFiles/iowork.dir/mutiThread.cpp.o
iowork: CMakeFiles/iowork.dir/file.cpp.o
iowork: CMakeFiles/iowork.dir/file2.cpp.o
iowork: CMakeFiles/iowork.dir/build.make
iowork: CMakeFiles/iowork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lqc/CLionProjects/iowork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable iowork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iowork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iowork.dir/build: iowork

.PHONY : CMakeFiles/iowork.dir/build

CMakeFiles/iowork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iowork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iowork.dir/clean

CMakeFiles/iowork.dir/depend:
	cd /home/lqc/CLionProjects/iowork/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lqc/CLionProjects/iowork /home/lqc/CLionProjects/iowork /home/lqc/CLionProjects/iowork/cmake-build-debug /home/lqc/CLionProjects/iowork/cmake-build-debug /home/lqc/CLionProjects/iowork/cmake-build-debug/CMakeFiles/iowork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iowork.dir/depend
