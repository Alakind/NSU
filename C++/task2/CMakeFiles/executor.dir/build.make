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
CMAKE_SOURCE_DIR = /mnt/d/Projects/study/C++/NSU/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Projects/study/C++/NSU/task2

# Include any dependencies generated for this target.
include CMakeFiles/executor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/executor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executor.dir/flags.make

CMakeFiles/executor.dir/src/main.cpp.o: CMakeFiles/executor.dir/flags.make
CMakeFiles/executor.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/study/C++/NSU/task2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/executor.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executor.dir/src/main.cpp.o -c /mnt/d/Projects/study/C++/NSU/task2/src/main.cpp

CMakeFiles/executor.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executor.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/study/C++/NSU/task2/src/main.cpp > CMakeFiles/executor.dir/src/main.cpp.i

CMakeFiles/executor.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executor.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/study/C++/NSU/task2/src/main.cpp -o CMakeFiles/executor.dir/src/main.cpp.s

CMakeFiles/executor.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/executor.dir/src/main.cpp.o.requires

CMakeFiles/executor.dir/src/main.cpp.o.provides: CMakeFiles/executor.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/executor.dir/build.make CMakeFiles/executor.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/executor.dir/src/main.cpp.o.provides

CMakeFiles/executor.dir/src/main.cpp.o.provides.build: CMakeFiles/executor.dir/src/main.cpp.o


# Object files for target executor
executor_OBJECTS = \
"CMakeFiles/executor.dir/src/main.cpp.o"

# External object files for target executor
executor_EXTERNAL_OBJECTS =

executor: CMakeFiles/executor.dir/src/main.cpp.o
executor: CMakeFiles/executor.dir/build.make
executor: libexecutorlib.a
executor: CMakeFiles/executor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/study/C++/NSU/task2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable executor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executor.dir/build: executor

.PHONY : CMakeFiles/executor.dir/build

CMakeFiles/executor.dir/requires: CMakeFiles/executor.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/executor.dir/requires

CMakeFiles/executor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executor.dir/clean

CMakeFiles/executor.dir/depend:
	cd /mnt/d/Projects/study/C++/NSU/task2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/study/C++/NSU/task2 /mnt/d/Projects/study/C++/NSU/task2 /mnt/d/Projects/study/C++/NSU/task2 /mnt/d/Projects/study/C++/NSU/task2 /mnt/d/Projects/study/C++/NSU/task2/CMakeFiles/executor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/executor.dir/depend

