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
include entry/ipv4/CMakeFiles/ipv42.dir/depend.make

# Include the progress variables for this target.
include entry/ipv4/CMakeFiles/ipv42.dir/progress.make

# Include the compile flags for this target's objects.
include entry/ipv4/CMakeFiles/ipv42.dir/flags.make

entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o: entry/ipv4/CMakeFiles/ipv42.dir/flags.make
entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o: ../entry/ipv4/src/osudpconnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/willy/eclipse-workspace/TestProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o -c /home/willy/eclipse-workspace/TestProj/entry/ipv4/src/osudpconnection.cpp

entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ipv42.dir/src/osudpconnection.cpp.i"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/willy/eclipse-workspace/TestProj/entry/ipv4/src/osudpconnection.cpp > CMakeFiles/ipv42.dir/src/osudpconnection.cpp.i

entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ipv42.dir/src/osudpconnection.cpp.s"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/willy/eclipse-workspace/TestProj/entry/ipv4/src/osudpconnection.cpp -o CMakeFiles/ipv42.dir/src/osudpconnection.cpp.s

entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.requires:

.PHONY : entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.requires

entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.provides: entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.requires
	$(MAKE) -f entry/ipv4/CMakeFiles/ipv42.dir/build.make entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.provides.build
.PHONY : entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.provides

entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.provides.build: entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o


# Object files for target ipv42
ipv42_OBJECTS = \
"CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o"

# External object files for target ipv42
ipv42_EXTERNAL_OBJECTS =

entry/ipv4/libipv42.a: entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o
entry/ipv4/libipv42.a: entry/ipv4/CMakeFiles/ipv42.dir/build.make
entry/ipv4/libipv42.a: entry/ipv4/CMakeFiles/ipv42.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/willy/eclipse-workspace/TestProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libipv42.a"
	cd /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 && $(CMAKE_COMMAND) -P CMakeFiles/ipv42.dir/cmake_clean_target.cmake
	cd /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ipv42.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
entry/ipv4/CMakeFiles/ipv42.dir/build: entry/ipv4/libipv42.a

.PHONY : entry/ipv4/CMakeFiles/ipv42.dir/build

entry/ipv4/CMakeFiles/ipv42.dir/requires: entry/ipv4/CMakeFiles/ipv42.dir/src/osudpconnection.cpp.o.requires

.PHONY : entry/ipv4/CMakeFiles/ipv42.dir/requires

entry/ipv4/CMakeFiles/ipv42.dir/clean:
	cd /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 && $(CMAKE_COMMAND) -P CMakeFiles/ipv42.dir/cmake_clean.cmake
.PHONY : entry/ipv4/CMakeFiles/ipv42.dir/clean

entry/ipv4/CMakeFiles/ipv42.dir/depend:
	cd /home/willy/eclipse-workspace/TestProj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/willy/eclipse-workspace/TestProj /home/willy/eclipse-workspace/TestProj/entry/ipv4 /home/willy/eclipse-workspace/TestProj/build /home/willy/eclipse-workspace/TestProj/build/entry/ipv4 /home/willy/eclipse-workspace/TestProj/build/entry/ipv4/CMakeFiles/ipv42.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : entry/ipv4/CMakeFiles/ipv42.dir/depend

