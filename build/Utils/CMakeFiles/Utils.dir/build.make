# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /snap/cmake/1088/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1088/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sajad/projects/GP_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sajad/projects/GP_cpp/build

# Include any dependencies generated for this target.
include Utils/CMakeFiles/Utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Utils/CMakeFiles/Utils.dir/compiler_depend.make

# Include the progress variables for this target.
include Utils/CMakeFiles/Utils.dir/progress.make

# Include the compile flags for this target's objects.
include Utils/CMakeFiles/Utils.dir/flags.make

Utils/CMakeFiles/Utils.dir/utils.cpp.o: Utils/CMakeFiles/Utils.dir/flags.make
Utils/CMakeFiles/Utils.dir/utils.cpp.o: ../Utils/utils.cpp
Utils/CMakeFiles/Utils.dir/utils.cpp.o: Utils/CMakeFiles/Utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sajad/projects/GP_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Utils/CMakeFiles/Utils.dir/utils.cpp.o"
	cd /home/sajad/projects/GP_cpp/build/Utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Utils/CMakeFiles/Utils.dir/utils.cpp.o -MF CMakeFiles/Utils.dir/utils.cpp.o.d -o CMakeFiles/Utils.dir/utils.cpp.o -c /home/sajad/projects/GP_cpp/Utils/utils.cpp

Utils/CMakeFiles/Utils.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Utils.dir/utils.cpp.i"
	cd /home/sajad/projects/GP_cpp/build/Utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sajad/projects/GP_cpp/Utils/utils.cpp > CMakeFiles/Utils.dir/utils.cpp.i

Utils/CMakeFiles/Utils.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Utils.dir/utils.cpp.s"
	cd /home/sajad/projects/GP_cpp/build/Utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sajad/projects/GP_cpp/Utils/utils.cpp -o CMakeFiles/Utils.dir/utils.cpp.s

# Object files for target Utils
Utils_OBJECTS = \
"CMakeFiles/Utils.dir/utils.cpp.o"

# External object files for target Utils
Utils_EXTERNAL_OBJECTS =

Utils/libUtils.a: Utils/CMakeFiles/Utils.dir/utils.cpp.o
Utils/libUtils.a: Utils/CMakeFiles/Utils.dir/build.make
Utils/libUtils.a: Utils/CMakeFiles/Utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sajad/projects/GP_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libUtils.a"
	cd /home/sajad/projects/GP_cpp/build/Utils && $(CMAKE_COMMAND) -P CMakeFiles/Utils.dir/cmake_clean_target.cmake
	cd /home/sajad/projects/GP_cpp/build/Utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Utils/CMakeFiles/Utils.dir/build: Utils/libUtils.a
.PHONY : Utils/CMakeFiles/Utils.dir/build

Utils/CMakeFiles/Utils.dir/clean:
	cd /home/sajad/projects/GP_cpp/build/Utils && $(CMAKE_COMMAND) -P CMakeFiles/Utils.dir/cmake_clean.cmake
.PHONY : Utils/CMakeFiles/Utils.dir/clean

Utils/CMakeFiles/Utils.dir/depend:
	cd /home/sajad/projects/GP_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sajad/projects/GP_cpp /home/sajad/projects/GP_cpp/Utils /home/sajad/projects/GP_cpp/build /home/sajad/projects/GP_cpp/build/Utils /home/sajad/projects/GP_cpp/build/Utils/CMakeFiles/Utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Utils/CMakeFiles/Utils.dir/depend

