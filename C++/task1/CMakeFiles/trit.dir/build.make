# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/d/Projects/study/C++/NSU/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Projects/study/C++/NSU/task1

# Include any dependencies generated for this target.
include CMakeFiles/trit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/trit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/trit.dir/flags.make

CMakeFiles/trit.dir/src/main.cpp.o: CMakeFiles/trit.dir/flags.make
CMakeFiles/trit.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/study/C++/NSU/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/trit.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/trit.dir/src/main.cpp.o -c /mnt/d/Projects/study/C++/NSU/task1/src/main.cpp

CMakeFiles/trit.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/trit.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/study/C++/NSU/task1/src/main.cpp > CMakeFiles/trit.dir/src/main.cpp.i

CMakeFiles/trit.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/trit.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/study/C++/NSU/task1/src/main.cpp -o CMakeFiles/trit.dir/src/main.cpp.s

CMakeFiles/trit.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/trit.dir/src/main.cpp.o.requires

CMakeFiles/trit.dir/src/main.cpp.o.provides: CMakeFiles/trit.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/trit.dir/build.make CMakeFiles/trit.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/trit.dir/src/main.cpp.o.provides

CMakeFiles/trit.dir/src/main.cpp.o.provides.build: CMakeFiles/trit.dir/src/main.cpp.o


# Object files for target trit
trit_OBJECTS = \
"CMakeFiles/trit.dir/src/main.cpp.o"

# External object files for target trit
trit_EXTERNAL_OBJECTS =

trit: CMakeFiles/trit.dir/src/main.cpp.o
trit: CMakeFiles/trit.dir/build.make
trit: libtritlib.a
trit: CMakeFiles/trit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/study/C++/NSU/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable trit"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/trit.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/trit.dir/build: trit

.PHONY : CMakeFiles/trit.dir/build

CMakeFiles/trit.dir/requires: CMakeFiles/trit.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/trit.dir/requires

CMakeFiles/trit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/trit.dir/cmake_clean.cmake
.PHONY : CMakeFiles/trit.dir/clean

CMakeFiles/trit.dir/depend:
	cd /mnt/d/Projects/study/C++/NSU/task1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1/CMakeFiles/trit.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/trit.dir/depend

