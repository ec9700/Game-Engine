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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pr2200\Documents\GitHub\Game-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug

# Include any dependencies generated for this target.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/progress.make

# Include the compile flags for this target's objects.
include glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/includes_C.rsp
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: C:/Users/pr2200/Documents/GitHub/Game-Engine/glfw-3.3.9/examples/offscreen.c
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj -MF CMakeFiles\offscreen.dir\offscreen.c.obj.d -o CMakeFiles\offscreen.dir\offscreen.c.obj -c C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\examples\offscreen.c

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/offscreen.dir/offscreen.c.i"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\examples\offscreen.c > CMakeFiles\offscreen.dir\offscreen.c.i

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/offscreen.dir/offscreen.c.s"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\examples\offscreen.c -o CMakeFiles\offscreen.dir\offscreen.c.s

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/glfw.rc.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/glfw.rc.obj: C:/Users/pr2200/Documents/GitHub/Game-Engine/glfw-3.3.9/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object glfw-3.3.9/examples/CMakeFiles/offscreen.dir/glfw.rc.obj"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\examples\glfw.rc CMakeFiles\offscreen.dir\glfw.rc.obj

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/flags.make
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/includes_C.rsp
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: C:/Users/pr2200/Documents/GitHub/Game-Engine/glfw-3.3.9/deps/glad_gl.c
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\offscreen.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\offscreen.dir\__\deps\glad_gl.c.obj -c C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\deps\glad_gl.c

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/offscreen.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\deps\glad_gl.c > CMakeFiles\offscreen.dir\__\deps\glad_gl.c.i

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/offscreen.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\deps\glad_gl.c -o CMakeFiles\offscreen.dir\__\deps\glad_gl.c.s

# Object files for target offscreen
offscreen_OBJECTS = \
"CMakeFiles/offscreen.dir/offscreen.c.obj" \
"CMakeFiles/offscreen.dir/glfw.rc.obj" \
"CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj"

# External object files for target offscreen
offscreen_EXTERNAL_OBJECTS =

glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/offscreen.c.obj
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/glfw.rc.obj
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/__/deps/glad_gl.c.obj
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/build.make
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/src/libglfw3.a
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/linkLibs.rsp
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/objects1.rsp
glfw-3.3.9/examples/offscreen.exe: glfw-3.3.9/examples/CMakeFiles/offscreen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable offscreen.exe"
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\offscreen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw-3.3.9/examples/CMakeFiles/offscreen.dir/build: glfw-3.3.9/examples/offscreen.exe
.PHONY : glfw-3.3.9/examples/CMakeFiles/offscreen.dir/build

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/clean:
	cd /d C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples && $(CMAKE_COMMAND) -P CMakeFiles\offscreen.dir\cmake_clean.cmake
.PHONY : glfw-3.3.9/examples/CMakeFiles/offscreen.dir/clean

glfw-3.3.9/examples/CMakeFiles/offscreen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pr2200\Documents\GitHub\Game-Engine C:\Users\pr2200\Documents\GitHub\Game-Engine\glfw-3.3.9\examples C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples C:\Users\pr2200\Documents\GitHub\Game-Engine\cmake-build-debug\glfw-3.3.9\examples\CMakeFiles\offscreen.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : glfw-3.3.9/examples/CMakeFiles/offscreen.dir/depend

