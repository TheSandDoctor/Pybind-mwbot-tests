# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed

# Utility rule file for check.

# Include the progress variables for this target.
include CMakeFiles/check.dir/progress.make

CMakeFiles/check:
	./test_cmake_build /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed/../test.py

check: CMakeFiles/check
check: CMakeFiles/check.dir/build.make

.PHONY : check

# Rule to build all files generated by this target.
CMakeFiles/check.dir/build: check

.PHONY : CMakeFiles/check.dir/build

CMakeFiles/check.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/check.dir/cmake_clean.cmake
.PHONY : CMakeFiles/check.dir/clean

CMakeFiles/check.dir/depend:
	cd /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed /Users/kylewilson/Downloads/build/tests/test_cmake_build/installed_embed/CMakeFiles/check.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/check.dir/depend

