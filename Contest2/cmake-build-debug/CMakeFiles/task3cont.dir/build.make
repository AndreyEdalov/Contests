# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andreyedalov/Desktop/С++/Contests/Contest2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task3cont.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/task3cont.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/task3cont.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task3cont.dir/flags.make

CMakeFiles/task3cont.dir/3.cpp.o: CMakeFiles/task3cont.dir/flags.make
CMakeFiles/task3cont.dir/3.cpp.o: /Users/andreyedalov/Desktop/С++/Contests/Contest2/3.cpp
CMakeFiles/task3cont.dir/3.cpp.o: CMakeFiles/task3cont.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task3cont.dir/3.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/task3cont.dir/3.cpp.o -MF CMakeFiles/task3cont.dir/3.cpp.o.d -o CMakeFiles/task3cont.dir/3.cpp.o -c /Users/andreyedalov/Desktop/С++/Contests/Contest2/3.cpp

CMakeFiles/task3cont.dir/3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/task3cont.dir/3.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andreyedalov/Desktop/С++/Contests/Contest2/3.cpp > CMakeFiles/task3cont.dir/3.cpp.i

CMakeFiles/task3cont.dir/3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/task3cont.dir/3.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andreyedalov/Desktop/С++/Contests/Contest2/3.cpp -o CMakeFiles/task3cont.dir/3.cpp.s

# Object files for target task3cont
task3cont_OBJECTS = \
"CMakeFiles/task3cont.dir/3.cpp.o"

# External object files for target task3cont
task3cont_EXTERNAL_OBJECTS =

task3cont: CMakeFiles/task3cont.dir/3.cpp.o
task3cont: CMakeFiles/task3cont.dir/build.make
task3cont: CMakeFiles/task3cont.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task3cont"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task3cont.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task3cont.dir/build: task3cont
.PHONY : CMakeFiles/task3cont.dir/build

CMakeFiles/task3cont.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task3cont.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task3cont.dir/clean

CMakeFiles/task3cont.dir/depend:
	cd /Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andreyedalov/Desktop/С++/Contests/Contest2 /Users/andreyedalov/Desktop/С++/Contests/Contest2 /Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug /Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug /Users/andreyedalov/Desktop/С++/Contests/Contest2/cmake-build-debug/CMakeFiles/task3cont.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/task3cont.dir/depend

