# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/maksim/Public/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/maksim/Public/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maksim/Documents/stepik/mp/lesson5/pipes/task1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task1.dir/flags.make

CMakeFiles/task1.dir/shell.c.o: CMakeFiles/task1.dir/flags.make
CMakeFiles/task1.dir/shell.c.o: ../shell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/task1.dir/shell.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/task1.dir/shell.c.o   -c /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/shell.c

CMakeFiles/task1.dir/shell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/task1.dir/shell.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/shell.c > CMakeFiles/task1.dir/shell.c.i

CMakeFiles/task1.dir/shell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/task1.dir/shell.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/shell.c -o CMakeFiles/task1.dir/shell.c.s

CMakeFiles/task1.dir/shell.c.o.requires:

.PHONY : CMakeFiles/task1.dir/shell.c.o.requires

CMakeFiles/task1.dir/shell.c.o.provides: CMakeFiles/task1.dir/shell.c.o.requires
	$(MAKE) -f CMakeFiles/task1.dir/build.make CMakeFiles/task1.dir/shell.c.o.provides.build
.PHONY : CMakeFiles/task1.dir/shell.c.o.provides

CMakeFiles/task1.dir/shell.c.o.provides.build: CMakeFiles/task1.dir/shell.c.o


# Object files for target task1
task1_OBJECTS = \
"CMakeFiles/task1.dir/shell.c.o"

# External object files for target task1
task1_EXTERNAL_OBJECTS =

task1: CMakeFiles/task1.dir/shell.c.o
task1: CMakeFiles/task1.dir/build.make
task1: CMakeFiles/task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable task1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task1.dir/build: task1

.PHONY : CMakeFiles/task1.dir/build

CMakeFiles/task1.dir/requires: CMakeFiles/task1.dir/shell.c.o.requires

.PHONY : CMakeFiles/task1.dir/requires

CMakeFiles/task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task1.dir/clean

CMakeFiles/task1.dir/depend:
	cd /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maksim/Documents/stepik/mp/lesson5/pipes/task1 /home/maksim/Documents/stepik/mp/lesson5/pipes/task1 /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug /home/maksim/Documents/stepik/mp/lesson5/pipes/task1/cmake-build-debug/CMakeFiles/task1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task1.dir/depend
