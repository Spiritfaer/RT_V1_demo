# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/istalevs/CLionProjects/RT_V1_demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RT_V1_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RT_V1_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RT_V1_demo.dir/flags.make

CMakeFiles/RT_V1_demo.dir/main.c.o: CMakeFiles/RT_V1_demo.dir/flags.make
CMakeFiles/RT_V1_demo.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RT_V1_demo.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RT_V1_demo.dir/main.c.o   -c /Users/istalevs/CLionProjects/RT_V1_demo/main.c

CMakeFiles/RT_V1_demo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RT_V1_demo.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/RT_V1_demo/main.c > CMakeFiles/RT_V1_demo.dir/main.c.i

CMakeFiles/RT_V1_demo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RT_V1_demo.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/RT_V1_demo/main.c -o CMakeFiles/RT_V1_demo.dir/main.c.s

CMakeFiles/RT_V1_demo.dir/file.c.o: CMakeFiles/RT_V1_demo.dir/flags.make
CMakeFiles/RT_V1_demo.dir/file.c.o: ../file.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RT_V1_demo.dir/file.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RT_V1_demo.dir/file.c.o   -c /Users/istalevs/CLionProjects/RT_V1_demo/file.c

CMakeFiles/RT_V1_demo.dir/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RT_V1_demo.dir/file.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/RT_V1_demo/file.c > CMakeFiles/RT_V1_demo.dir/file.c.i

CMakeFiles/RT_V1_demo.dir/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RT_V1_demo.dir/file.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/RT_V1_demo/file.c -o CMakeFiles/RT_V1_demo.dir/file.c.s

CMakeFiles/RT_V1_demo.dir/foo.c.o: CMakeFiles/RT_V1_demo.dir/flags.make
CMakeFiles/RT_V1_demo.dir/foo.c.o: ../foo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/RT_V1_demo.dir/foo.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RT_V1_demo.dir/foo.c.o   -c /Users/istalevs/CLionProjects/RT_V1_demo/foo.c

CMakeFiles/RT_V1_demo.dir/foo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RT_V1_demo.dir/foo.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/RT_V1_demo/foo.c > CMakeFiles/RT_V1_demo.dir/foo.c.i

CMakeFiles/RT_V1_demo.dir/foo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RT_V1_demo.dir/foo.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/RT_V1_demo/foo.c -o CMakeFiles/RT_V1_demo.dir/foo.c.s

CMakeFiles/RT_V1_demo.dir/init.c.o: CMakeFiles/RT_V1_demo.dir/flags.make
CMakeFiles/RT_V1_demo.dir/init.c.o: ../init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/RT_V1_demo.dir/init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RT_V1_demo.dir/init.c.o   -c /Users/istalevs/CLionProjects/RT_V1_demo/init.c

CMakeFiles/RT_V1_demo.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RT_V1_demo.dir/init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/RT_V1_demo/init.c > CMakeFiles/RT_V1_demo.dir/init.c.i

CMakeFiles/RT_V1_demo.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RT_V1_demo.dir/init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/RT_V1_demo/init.c -o CMakeFiles/RT_V1_demo.dir/init.c.s

CMakeFiles/RT_V1_demo.dir/set_scene.c.o: CMakeFiles/RT_V1_demo.dir/flags.make
CMakeFiles/RT_V1_demo.dir/set_scene.c.o: ../set_scene.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/RT_V1_demo.dir/set_scene.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RT_V1_demo.dir/set_scene.c.o   -c /Users/istalevs/CLionProjects/RT_V1_demo/set_scene.c

CMakeFiles/RT_V1_demo.dir/set_scene.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RT_V1_demo.dir/set_scene.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/istalevs/CLionProjects/RT_V1_demo/set_scene.c > CMakeFiles/RT_V1_demo.dir/set_scene.c.i

CMakeFiles/RT_V1_demo.dir/set_scene.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RT_V1_demo.dir/set_scene.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/istalevs/CLionProjects/RT_V1_demo/set_scene.c -o CMakeFiles/RT_V1_demo.dir/set_scene.c.s

# Object files for target RT_V1_demo
RT_V1_demo_OBJECTS = \
"CMakeFiles/RT_V1_demo.dir/main.c.o" \
"CMakeFiles/RT_V1_demo.dir/file.c.o" \
"CMakeFiles/RT_V1_demo.dir/foo.c.o" \
"CMakeFiles/RT_V1_demo.dir/init.c.o" \
"CMakeFiles/RT_V1_demo.dir/set_scene.c.o"

# External object files for target RT_V1_demo
RT_V1_demo_EXTERNAL_OBJECTS =

RT_V1_demo: CMakeFiles/RT_V1_demo.dir/main.c.o
RT_V1_demo: CMakeFiles/RT_V1_demo.dir/file.c.o
RT_V1_demo: CMakeFiles/RT_V1_demo.dir/foo.c.o
RT_V1_demo: CMakeFiles/RT_V1_demo.dir/init.c.o
RT_V1_demo: CMakeFiles/RT_V1_demo.dir/set_scene.c.o
RT_V1_demo: CMakeFiles/RT_V1_demo.dir/build.make
RT_V1_demo: CMakeFiles/RT_V1_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable RT_V1_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RT_V1_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RT_V1_demo.dir/build: RT_V1_demo

.PHONY : CMakeFiles/RT_V1_demo.dir/build

CMakeFiles/RT_V1_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RT_V1_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RT_V1_demo.dir/clean

CMakeFiles/RT_V1_demo.dir/depend:
	cd /Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/istalevs/CLionProjects/RT_V1_demo /Users/istalevs/CLionProjects/RT_V1_demo /Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug /Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug /Users/istalevs/CLionProjects/RT_V1_demo/cmake-build-debug/CMakeFiles/RT_V1_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RT_V1_demo.dir/depend

