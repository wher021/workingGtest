# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/willy/eclipse-workspace/TestProj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/willy/eclipse-workspace/TestProj/build

# Include any dependencies generated for this target.
include entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/flags.make

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/flags.make
entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../gmock-1.7.0/gtest/src/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willy/eclipse-workspace/TestProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/willy/eclipse-workspace/TestProj/gmock-1.7.0/gtest/src/gtest_main.cc

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/willy/eclipse-workspace/TestProj/gmock-1.7.0/gtest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/willy/eclipse-workspace/TestProj/gmock-1.7.0/gtest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:

.PHONY : entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/build.make entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o


# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

entry/{CMAKE_BINARY_DIR}/gmock/gtest/libgtest_main.a: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
entry/{CMAKE_BINARY_DIR}/gmock/gtest/libgtest_main.a: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/build.make
entry/{CMAKE_BINARY_DIR}/gmock/gtest/libgtest_main.a: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/willy/eclipse-workspace/TestProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/build: entry/{CMAKE_BINARY_DIR}/gmock/gtest/libgtest_main.a

.PHONY : entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/build

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/requires: entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

.PHONY : entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/requires

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/clean:
	cd /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/clean

entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/depend:
	cd /home/willy/eclipse-workspace/TestProj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/willy/eclipse-workspace/TestProj /home/willy/eclipse-workspace/TestProj/gmock-1.7.0/gtest /home/willy/eclipse-workspace/TestProj/build /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest /home/willy/eclipse-workspace/TestProj/build/entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : entry/{CMAKE_BINARY_DIR}/gmock/gtest/CMakeFiles/gtest_main.dir/depend

