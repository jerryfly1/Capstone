# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/user/Capstone/VT_with_Rabbitmq/TestB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/Capstone/VT_with_Rabbitmq/TestB/build

# Include any dependencies generated for this target.
include CMakeFiles/receive.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/receive.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/receive.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/receive.dir/flags.make

CMakeFiles/receive.dir/msqueue_receive.cpp.o: CMakeFiles/receive.dir/flags.make
CMakeFiles/receive.dir/msqueue_receive.cpp.o: ../msqueue_receive.cpp
CMakeFiles/receive.dir/msqueue_receive.cpp.o: CMakeFiles/receive.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/user/Capstone/VT_with_Rabbitmq/TestB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/receive.dir/msqueue_receive.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/receive.dir/msqueue_receive.cpp.o -MF CMakeFiles/receive.dir/msqueue_receive.cpp.o.d -o CMakeFiles/receive.dir/msqueue_receive.cpp.o -c /home/user/Capstone/VT_with_Rabbitmq/TestB/msqueue_receive.cpp

CMakeFiles/receive.dir/msqueue_receive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/receive.dir/msqueue_receive.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/user/Capstone/VT_with_Rabbitmq/TestB/msqueue_receive.cpp > CMakeFiles/receive.dir/msqueue_receive.cpp.i

CMakeFiles/receive.dir/msqueue_receive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/receive.dir/msqueue_receive.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/user/Capstone/VT_with_Rabbitmq/TestB/msqueue_receive.cpp -o CMakeFiles/receive.dir/msqueue_receive.cpp.s

# Object files for target receive
receive_OBJECTS = \
"CMakeFiles/receive.dir/msqueue_receive.cpp.o"

# External object files for target receive
receive_EXTERNAL_OBJECTS =

receive: CMakeFiles/receive.dir/msqueue_receive.cpp.o
receive: CMakeFiles/receive.dir/build.make
receive: CMakeFiles/receive.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/user/Capstone/VT_with_Rabbitmq/TestB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable receive"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/receive.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/receive.dir/build: receive
.PHONY : CMakeFiles/receive.dir/build

CMakeFiles/receive.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/receive.dir/cmake_clean.cmake
.PHONY : CMakeFiles/receive.dir/clean

CMakeFiles/receive.dir/depend:
	cd /home/user/Capstone/VT_with_Rabbitmq/TestB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/user/Capstone/VT_with_Rabbitmq/TestB /home/user/Capstone/VT_with_Rabbitmq/TestB /home/user/Capstone/VT_with_Rabbitmq/TestB/build /home/user/Capstone/VT_with_Rabbitmq/TestB/build /home/user/Capstone/VT_with_Rabbitmq/TestB/build/CMakeFiles/receive.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/receive.dir/depend

