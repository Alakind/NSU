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
include CMakeFiles/tritlib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tritlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tritlib.dir/flags.make

CMakeFiles/tritlib.dir/src/main.cpp.o: CMakeFiles/tritlib.dir/flags.make
CMakeFiles/tritlib.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/study/C++/NSU/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tritlib.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tritlib.dir/src/main.cpp.o -c /mnt/d/Projects/study/C++/NSU/task1/src/main.cpp

CMakeFiles/tritlib.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tritlib.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/study/C++/NSU/task1/src/main.cpp > CMakeFiles/tritlib.dir/src/main.cpp.i

CMakeFiles/tritlib.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tritlib.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/study/C++/NSU/task1/src/main.cpp -o CMakeFiles/tritlib.dir/src/main.cpp.s

CMakeFiles/tritlib.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/tritlib.dir/src/main.cpp.o.requires

CMakeFiles/tritlib.dir/src/main.cpp.o.provides: CMakeFiles/tritlib.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tritlib.dir/build.make CMakeFiles/tritlib.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/tritlib.dir/src/main.cpp.o.provides

CMakeFiles/tritlib.dir/src/main.cpp.o.provides.build: CMakeFiles/tritlib.dir/src/main.cpp.o


CMakeFiles/tritlib.dir/src/trit.cpp.o: CMakeFiles/tritlib.dir/flags.make
CMakeFiles/tritlib.dir/src/trit.cpp.o: src/trit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/study/C++/NSU/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tritlib.dir/src/trit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tritlib.dir/src/trit.cpp.o -c /mnt/d/Projects/study/C++/NSU/task1/src/trit.cpp

CMakeFiles/tritlib.dir/src/trit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tritlib.dir/src/trit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/study/C++/NSU/task1/src/trit.cpp > CMakeFiles/tritlib.dir/src/trit.cpp.i

CMakeFiles/tritlib.dir/src/trit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tritlib.dir/src/trit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/study/C++/NSU/task1/src/trit.cpp -o CMakeFiles/tritlib.dir/src/trit.cpp.s

CMakeFiles/tritlib.dir/src/trit.cpp.o.requires:

.PHONY : CMakeFiles/tritlib.dir/src/trit.cpp.o.requires

CMakeFiles/tritlib.dir/src/trit.cpp.o.provides: CMakeFiles/tritlib.dir/src/trit.cpp.o.requires
	$(MAKE) -f CMakeFiles/tritlib.dir/build.make CMakeFiles/tritlib.dir/src/trit.cpp.o.provides.build
.PHONY : CMakeFiles/tritlib.dir/src/trit.cpp.o.provides

CMakeFiles/tritlib.dir/src/trit.cpp.o.provides.build: CMakeFiles/tritlib.dir/src/trit.cpp.o


# Object files for target tritlib
tritlib_OBJECTS = \
"CMakeFiles/tritlib.dir/src/main.cpp.o" \
"CMakeFiles/tritlib.dir/src/trit.cpp.o"

# External object files for target tritlib
tritlib_EXTERNAL_OBJECTS =

libtritlib.a: CMakeFiles/tritlib.dir/src/main.cpp.o
libtritlib.a: CMakeFiles/tritlib.dir/src/trit.cpp.o
libtritlib.a: CMakeFiles/tritlib.dir/build.make
libtritlib.a: CMakeFiles/tritlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/study/C++/NSU/task1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtritlib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tritlib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tritlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tritlib.dir/build: libtritlib.a

.PHONY : CMakeFiles/tritlib.dir/build

CMakeFiles/tritlib.dir/requires: CMakeFiles/tritlib.dir/src/main.cpp.o.requires
CMakeFiles/tritlib.dir/requires: CMakeFiles/tritlib.dir/src/trit.cpp.o.requires

.PHONY : CMakeFiles/tritlib.dir/requires

CMakeFiles/tritlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tritlib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tritlib.dir/clean

CMakeFiles/tritlib.dir/depend:
	cd /mnt/d/Projects/study/C++/NSU/task1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1 /mnt/d/Projects/study/C++/NSU/task1/CMakeFiles/tritlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tritlib.dir/depend
