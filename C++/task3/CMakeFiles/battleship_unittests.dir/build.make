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
CMAKE_SOURCE_DIR = /mnt/d/Projects/study/C++/NSU/task3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Projects/study/C++/NSU/task3

# Include any dependencies generated for this target.
include CMakeFiles/battleship_unittests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/battleship_unittests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/battleship_unittests.dir/flags.make

CMakeFiles/battleship_unittests.dir/tests/main.cpp.o: CMakeFiles/battleship_unittests.dir/flags.make
CMakeFiles/battleship_unittests.dir/tests/main.cpp.o: tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/study/C++/NSU/task3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/battleship_unittests.dir/tests/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship_unittests.dir/tests/main.cpp.o -c /mnt/d/Projects/study/C++/NSU/task3/tests/main.cpp

CMakeFiles/battleship_unittests.dir/tests/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship_unittests.dir/tests/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/study/C++/NSU/task3/tests/main.cpp > CMakeFiles/battleship_unittests.dir/tests/main.cpp.i

CMakeFiles/battleship_unittests.dir/tests/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship_unittests.dir/tests/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/study/C++/NSU/task3/tests/main.cpp -o CMakeFiles/battleship_unittests.dir/tests/main.cpp.s

CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.requires:

.PHONY : CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.requires

CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.provides: CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/battleship_unittests.dir/build.make CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.provides.build
.PHONY : CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.provides

CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.provides.build: CMakeFiles/battleship_unittests.dir/tests/main.cpp.o


CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o: CMakeFiles/battleship_unittests.dir/flags.make
CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o: tests/battleship_unittest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/study/C++/NSU/task3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o -c /mnt/d/Projects/study/C++/NSU/task3/tests/battleship_unittest.cpp

CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/study/C++/NSU/task3/tests/battleship_unittest.cpp > CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.i

CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/study/C++/NSU/task3/tests/battleship_unittest.cpp -o CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.s

CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.requires:

.PHONY : CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.requires

CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.provides: CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.requires
	$(MAKE) -f CMakeFiles/battleship_unittests.dir/build.make CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.provides.build
.PHONY : CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.provides

CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.provides.build: CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o


# Object files for target battleship_unittests
battleship_unittests_OBJECTS = \
"CMakeFiles/battleship_unittests.dir/tests/main.cpp.o" \
"CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o"

# External object files for target battleship_unittests
battleship_unittests_EXTERNAL_OBJECTS =

battleship_unittests: CMakeFiles/battleship_unittests.dir/tests/main.cpp.o
battleship_unittests: CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o
battleship_unittests: CMakeFiles/battleship_unittests.dir/build.make
battleship_unittests: libbattleship_game.a
battleship_unittests: CMakeFiles/battleship_unittests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/study/C++/NSU/task3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable battleship_unittests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/battleship_unittests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/battleship_unittests.dir/build: battleship_unittests

.PHONY : CMakeFiles/battleship_unittests.dir/build

CMakeFiles/battleship_unittests.dir/requires: CMakeFiles/battleship_unittests.dir/tests/main.cpp.o.requires
CMakeFiles/battleship_unittests.dir/requires: CMakeFiles/battleship_unittests.dir/tests/battleship_unittest.cpp.o.requires

.PHONY : CMakeFiles/battleship_unittests.dir/requires

CMakeFiles/battleship_unittests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/battleship_unittests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/battleship_unittests.dir/clean

CMakeFiles/battleship_unittests.dir/depend:
	cd /mnt/d/Projects/study/C++/NSU/task3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/study/C++/NSU/task3 /mnt/d/Projects/study/C++/NSU/task3 /mnt/d/Projects/study/C++/NSU/task3 /mnt/d/Projects/study/C++/NSU/task3 /mnt/d/Projects/study/C++/NSU/task3/CMakeFiles/battleship_unittests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/battleship_unittests.dir/depend
