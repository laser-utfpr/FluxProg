# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build

# Include any dependencies generated for this target.
include CMakeFiles/cppremoteapi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppremoteapi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppremoteapi.dir/flags.make

CMakeFiles/cppremoteapi.dir/main.cpp.o: CMakeFiles/cppremoteapi.dir/flags.make
CMakeFiles/cppremoteapi.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppremoteapi.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppremoteapi.dir/main.cpp.o -c /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/main.cpp

CMakeFiles/cppremoteapi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppremoteapi.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/main.cpp > CMakeFiles/cppremoteapi.dir/main.cpp.i

CMakeFiles/cppremoteapi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppremoteapi.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/main.cpp -o CMakeFiles/cppremoteapi.dir/main.cpp.s

CMakeFiles/cppremoteapi.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/cppremoteapi.dir/main.cpp.o.requires

CMakeFiles/cppremoteapi.dir/main.cpp.o.provides: CMakeFiles/cppremoteapi.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/cppremoteapi.dir/build.make CMakeFiles/cppremoteapi.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/cppremoteapi.dir/main.cpp.o.provides

CMakeFiles/cppremoteapi.dir/main.cpp.o.provides.build: CMakeFiles/cppremoteapi.dir/main.cpp.o


CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o: CMakeFiles/cppremoteapi.dir/flags.make
CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o: ../remoteApi/extApi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o   -c /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/remoteApi/extApi.c

CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/remoteApi/extApi.c > CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.i

CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/remoteApi/extApi.c -o CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.s

CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.requires:

.PHONY : CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.requires

CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.provides: CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.requires
	$(MAKE) -f CMakeFiles/cppremoteapi.dir/build.make CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.provides.build
.PHONY : CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.provides

CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.provides.build: CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o


CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o: CMakeFiles/cppremoteapi.dir/flags.make
CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o: ../remoteApi/extApiPlatform.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o   -c /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/remoteApi/extApiPlatform.c

CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/remoteApi/extApiPlatform.c > CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.i

CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/remoteApi/extApiPlatform.c -o CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.s

CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.requires:

.PHONY : CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.requires

CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.provides: CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.requires
	$(MAKE) -f CMakeFiles/cppremoteapi.dir/build.make CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.provides.build
.PHONY : CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.provides

CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.provides.build: CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o


# Object files for target cppremoteapi
cppremoteapi_OBJECTS = \
"CMakeFiles/cppremoteapi.dir/main.cpp.o" \
"CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o" \
"CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o"

# External object files for target cppremoteapi
cppremoteapi_EXTERNAL_OBJECTS =

cppremoteapi: CMakeFiles/cppremoteapi.dir/main.cpp.o
cppremoteapi: CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o
cppremoteapi: CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o
cppremoteapi: CMakeFiles/cppremoteapi.dir/build.make
cppremoteapi: CMakeFiles/cppremoteapi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cppremoteapi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppremoteapi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppremoteapi.dir/build: cppremoteapi

.PHONY : CMakeFiles/cppremoteapi.dir/build

CMakeFiles/cppremoteapi.dir/requires: CMakeFiles/cppremoteapi.dir/main.cpp.o.requires
CMakeFiles/cppremoteapi.dir/requires: CMakeFiles/cppremoteapi.dir/remoteApi/extApi.c.o.requires
CMakeFiles/cppremoteapi.dir/requires: CMakeFiles/cppremoteapi.dir/remoteApi/extApiPlatform.c.o.requires

.PHONY : CMakeFiles/cppremoteapi.dir/requires

CMakeFiles/cppremoteapi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppremoteapi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppremoteapi.dir/clean

CMakeFiles/cppremoteapi.dir/depend:
	cd /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build /home/robocup/Desktop/LASER-fluxograma-e-robos/fluxprog/ProjetoRemoteApi/build/CMakeFiles/cppremoteapi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppremoteapi.dir/depend

