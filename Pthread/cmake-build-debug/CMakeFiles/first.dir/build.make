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
CMAKE_COMMAND = /opt/clion-2017.3.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.3.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/koshachok/src/APP/Pthread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/koshachok/src/APP/Pthread/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/first.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/first.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/first.dir/flags.make

CMakeFiles/first.dir/main.cpp.o: CMakeFiles/first.dir/flags.make
CMakeFiles/first.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/koshachok/src/APP/Pthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/first.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/first.dir/main.cpp.o -c /home/koshachok/src/APP/Pthread/main.cpp

CMakeFiles/first.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/first.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/koshachok/src/APP/Pthread/main.cpp > CMakeFiles/first.dir/main.cpp.i

CMakeFiles/first.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/first.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/koshachok/src/APP/Pthread/main.cpp -o CMakeFiles/first.dir/main.cpp.s

CMakeFiles/first.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/first.dir/main.cpp.o.requires

CMakeFiles/first.dir/main.cpp.o.provides: CMakeFiles/first.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/first.dir/build.make CMakeFiles/first.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/first.dir/main.cpp.o.provides

CMakeFiles/first.dir/main.cpp.o.provides.build: CMakeFiles/first.dir/main.cpp.o


CMakeFiles/first.dir/src/Matrix.cpp.o: CMakeFiles/first.dir/flags.make
CMakeFiles/first.dir/src/Matrix.cpp.o: ../src/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/koshachok/src/APP/Pthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/first.dir/src/Matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/first.dir/src/Matrix.cpp.o -c /home/koshachok/src/APP/Pthread/src/Matrix.cpp

CMakeFiles/first.dir/src/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/first.dir/src/Matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/koshachok/src/APP/Pthread/src/Matrix.cpp > CMakeFiles/first.dir/src/Matrix.cpp.i

CMakeFiles/first.dir/src/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/first.dir/src/Matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/koshachok/src/APP/Pthread/src/Matrix.cpp -o CMakeFiles/first.dir/src/Matrix.cpp.s

CMakeFiles/first.dir/src/Matrix.cpp.o.requires:

.PHONY : CMakeFiles/first.dir/src/Matrix.cpp.o.requires

CMakeFiles/first.dir/src/Matrix.cpp.o.provides: CMakeFiles/first.dir/src/Matrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/first.dir/build.make CMakeFiles/first.dir/src/Matrix.cpp.o.provides.build
.PHONY : CMakeFiles/first.dir/src/Matrix.cpp.o.provides

CMakeFiles/first.dir/src/Matrix.cpp.o.provides.build: CMakeFiles/first.dir/src/Matrix.cpp.o


CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o: CMakeFiles/first.dir/flags.make
CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o: ../tests/test_basic_multiplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/koshachok/src/APP/Pthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o -c /home/koshachok/src/APP/Pthread/tests/test_basic_multiplication.cpp

CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/koshachok/src/APP/Pthread/tests/test_basic_multiplication.cpp > CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.i

CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/koshachok/src/APP/Pthread/tests/test_basic_multiplication.cpp -o CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.s

CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.requires:

.PHONY : CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.requires

CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.provides: CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.requires
	$(MAKE) -f CMakeFiles/first.dir/build.make CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.provides.build
.PHONY : CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.provides

CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.provides.build: CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o


# Object files for target first
first_OBJECTS = \
"CMakeFiles/first.dir/main.cpp.o" \
"CMakeFiles/first.dir/src/Matrix.cpp.o" \
"CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o"

# External object files for target first
first_EXTERNAL_OBJECTS =

first: CMakeFiles/first.dir/main.cpp.o
first: CMakeFiles/first.dir/src/Matrix.cpp.o
first: CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o
first: CMakeFiles/first.dir/build.make
first: CMakeFiles/first.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/koshachok/src/APP/Pthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable first"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/first.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/first.dir/build: first

.PHONY : CMakeFiles/first.dir/build

CMakeFiles/first.dir/requires: CMakeFiles/first.dir/main.cpp.o.requires
CMakeFiles/first.dir/requires: CMakeFiles/first.dir/src/Matrix.cpp.o.requires
CMakeFiles/first.dir/requires: CMakeFiles/first.dir/tests/test_basic_multiplication.cpp.o.requires

.PHONY : CMakeFiles/first.dir/requires

CMakeFiles/first.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/first.dir/cmake_clean.cmake
.PHONY : CMakeFiles/first.dir/clean

CMakeFiles/first.dir/depend:
	cd /home/koshachok/src/APP/Pthread/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/koshachok/src/APP/Pthread /home/koshachok/src/APP/Pthread /home/koshachok/src/APP/Pthread/cmake-build-debug /home/koshachok/src/APP/Pthread/cmake-build-debug /home/koshachok/src/APP/Pthread/cmake-build-debug/CMakeFiles/first.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/first.dir/depend

