# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ck6100\Documents\Game-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug

# Include any dependencies generated for this target.
include glfw-3.3.9/tests/CMakeFiles/iconify.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glfw-3.3.9/tests/CMakeFiles/iconify.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw-3.3.9/tests/CMakeFiles/iconify.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.3.9/tests/CMakeFiles/iconify.dir/flags.make

glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/flags.make
glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/includes_C.rsp
glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj: C:/Users/ck6100/Documents/Game-Engine/glfw-3.3.9/tests/iconify.c
glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj -MF CMakeFiles\iconify.dir\iconify.c.obj.d -o CMakeFiles\iconify.dir\iconify.c.obj -c C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\tests\iconify.c

glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/iconify.dir/iconify.c.i"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\tests\iconify.c > CMakeFiles\iconify.dir\iconify.c.i

glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/iconify.dir/iconify.c.s"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\tests\iconify.c -o CMakeFiles\iconify.dir\iconify.c.s

glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/flags.make
glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/includes_C.rsp
glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: C:/Users/ck6100/Documents/Game-Engine/glfw-3.3.9/deps/getopt.c
glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj -MF CMakeFiles\iconify.dir\__\deps\getopt.c.obj.d -o CMakeFiles\iconify.dir\__\deps\getopt.c.obj -c C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\deps\getopt.c

glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/getopt.c.i"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\deps\getopt.c > CMakeFiles\iconify.dir\__\deps\getopt.c.i

glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/getopt.c.s"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\deps\getopt.c -o CMakeFiles\iconify.dir\__\deps\getopt.c.s

glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/flags.make
glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/includes_C.rsp
glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: C:/Users/ck6100/Documents/Game-Engine/glfw-3.3.9/deps/glad_gl.c
glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: glfw-3.3.9/tests/CMakeFiles/iconify.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\iconify.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\iconify.dir\__\deps\glad_gl.c.obj -c C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\deps\glad_gl.c

glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\deps\glad_gl.c > CMakeFiles\iconify.dir\__\deps\glad_gl.c.i

glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\deps\glad_gl.c -o CMakeFiles\iconify.dir\__\deps\glad_gl.c.s

# Object files for target iconify
iconify_OBJECTS = \
"CMakeFiles/iconify.dir/iconify.c.obj" \
"CMakeFiles/iconify.dir/__/deps/getopt.c.obj" \
"CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj"

# External object files for target iconify
iconify_EXTERNAL_OBJECTS =

glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/iconify.c.obj
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/build.make
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/src/libglfw3.a
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/linkLibs.rsp
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/objects1.rsp
glfw-3.3.9/tests/iconify.exe: glfw-3.3.9/tests/CMakeFiles/iconify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable iconify.exe"
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\iconify.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.3.9/tests/CMakeFiles/iconify.dir/build: glfw-3.3.9/tests/iconify.exe
.PHONY : glfw-3.3.9/tests/CMakeFiles/iconify.dir/build

glfw-3.3.9/tests/CMakeFiles/iconify.dir/clean:
	cd /d C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests && $(CMAKE_COMMAND) -P CMakeFiles\iconify.dir\cmake_clean.cmake
.PHONY : glfw-3.3.9/tests/CMakeFiles/iconify.dir/clean

glfw-3.3.9/tests/CMakeFiles/iconify.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ck6100\Documents\Game-Engine C:\Users\ck6100\Documents\Game-Engine\glfw-3.3.9\tests C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests C:\Users\ck6100\Documents\Game-Engine\cmake-build-debug\glfw-3.3.9\tests\CMakeFiles\iconify.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : glfw-3.3.9/tests/CMakeFiles/iconify.dir/depend

