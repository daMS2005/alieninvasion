# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /Users/danielmora/miniforge3/bin/cmake

# The command to remove a file.
RM = /Users/danielmora/miniforge3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/danielmora/Desktop/alieninvasion copy"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/danielmora/Desktop/alieninvasion copy/build"

# Include any dependencies generated for this target.
include CMakeFiles/alien_invasion.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/alien_invasion.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/alien_invasion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alien_invasion.dir/flags.make

CMakeFiles/alien_invasion.dir/src/main.cpp.o: CMakeFiles/alien_invasion.dir/flags.make
CMakeFiles/alien_invasion.dir/src/main.cpp.o: /Users/danielmora/Desktop/alieninvasion\ copy/src/main.cpp
CMakeFiles/alien_invasion.dir/src/main.cpp.o: CMakeFiles/alien_invasion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alien_invasion.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/alien_invasion.dir/src/main.cpp.o -MF CMakeFiles/alien_invasion.dir/src/main.cpp.o.d -o CMakeFiles/alien_invasion.dir/src/main.cpp.o -c "/Users/danielmora/Desktop/alieninvasion copy/src/main.cpp"

CMakeFiles/alien_invasion.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_invasion.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielmora/Desktop/alieninvasion copy/src/main.cpp" > CMakeFiles/alien_invasion.dir/src/main.cpp.i

CMakeFiles/alien_invasion.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_invasion.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielmora/Desktop/alieninvasion copy/src/main.cpp" -o CMakeFiles/alien_invasion.dir/src/main.cpp.s

CMakeFiles/alien_invasion.dir/src/Player.cpp.o: CMakeFiles/alien_invasion.dir/flags.make
CMakeFiles/alien_invasion.dir/src/Player.cpp.o: /Users/danielmora/Desktop/alieninvasion\ copy/src/Player.cpp
CMakeFiles/alien_invasion.dir/src/Player.cpp.o: CMakeFiles/alien_invasion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/alien_invasion.dir/src/Player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/alien_invasion.dir/src/Player.cpp.o -MF CMakeFiles/alien_invasion.dir/src/Player.cpp.o.d -o CMakeFiles/alien_invasion.dir/src/Player.cpp.o -c "/Users/danielmora/Desktop/alieninvasion copy/src/Player.cpp"

CMakeFiles/alien_invasion.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_invasion.dir/src/Player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielmora/Desktop/alieninvasion copy/src/Player.cpp" > CMakeFiles/alien_invasion.dir/src/Player.cpp.i

CMakeFiles/alien_invasion.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_invasion.dir/src/Player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielmora/Desktop/alieninvasion copy/src/Player.cpp" -o CMakeFiles/alien_invasion.dir/src/Player.cpp.s

CMakeFiles/alien_invasion.dir/src/Alien.cpp.o: CMakeFiles/alien_invasion.dir/flags.make
CMakeFiles/alien_invasion.dir/src/Alien.cpp.o: /Users/danielmora/Desktop/alieninvasion\ copy/src/Alien.cpp
CMakeFiles/alien_invasion.dir/src/Alien.cpp.o: CMakeFiles/alien_invasion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/alien_invasion.dir/src/Alien.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/alien_invasion.dir/src/Alien.cpp.o -MF CMakeFiles/alien_invasion.dir/src/Alien.cpp.o.d -o CMakeFiles/alien_invasion.dir/src/Alien.cpp.o -c "/Users/danielmora/Desktop/alieninvasion copy/src/Alien.cpp"

CMakeFiles/alien_invasion.dir/src/Alien.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_invasion.dir/src/Alien.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielmora/Desktop/alieninvasion copy/src/Alien.cpp" > CMakeFiles/alien_invasion.dir/src/Alien.cpp.i

CMakeFiles/alien_invasion.dir/src/Alien.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_invasion.dir/src/Alien.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielmora/Desktop/alieninvasion copy/src/Alien.cpp" -o CMakeFiles/alien_invasion.dir/src/Alien.cpp.s

CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o: CMakeFiles/alien_invasion.dir/flags.make
CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o: /Users/danielmora/Desktop/alieninvasion\ copy/src/Projectile.cpp
CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o: CMakeFiles/alien_invasion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o -MF CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o.d -o CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o -c "/Users/danielmora/Desktop/alieninvasion copy/src/Projectile.cpp"

CMakeFiles/alien_invasion.dir/src/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_invasion.dir/src/Projectile.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielmora/Desktop/alieninvasion copy/src/Projectile.cpp" > CMakeFiles/alien_invasion.dir/src/Projectile.cpp.i

CMakeFiles/alien_invasion.dir/src/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_invasion.dir/src/Projectile.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielmora/Desktop/alieninvasion copy/src/Projectile.cpp" -o CMakeFiles/alien_invasion.dir/src/Projectile.cpp.s

CMakeFiles/alien_invasion.dir/src/GameState.cpp.o: CMakeFiles/alien_invasion.dir/flags.make
CMakeFiles/alien_invasion.dir/src/GameState.cpp.o: /Users/danielmora/Desktop/alieninvasion\ copy/src/GameState.cpp
CMakeFiles/alien_invasion.dir/src/GameState.cpp.o: CMakeFiles/alien_invasion.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/alien_invasion.dir/src/GameState.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/alien_invasion.dir/src/GameState.cpp.o -MF CMakeFiles/alien_invasion.dir/src/GameState.cpp.o.d -o CMakeFiles/alien_invasion.dir/src/GameState.cpp.o -c "/Users/danielmora/Desktop/alieninvasion copy/src/GameState.cpp"

CMakeFiles/alien_invasion.dir/src/GameState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/alien_invasion.dir/src/GameState.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielmora/Desktop/alieninvasion copy/src/GameState.cpp" > CMakeFiles/alien_invasion.dir/src/GameState.cpp.i

CMakeFiles/alien_invasion.dir/src/GameState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/alien_invasion.dir/src/GameState.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielmora/Desktop/alieninvasion copy/src/GameState.cpp" -o CMakeFiles/alien_invasion.dir/src/GameState.cpp.s

# Object files for target alien_invasion
alien_invasion_OBJECTS = \
"CMakeFiles/alien_invasion.dir/src/main.cpp.o" \
"CMakeFiles/alien_invasion.dir/src/Player.cpp.o" \
"CMakeFiles/alien_invasion.dir/src/Alien.cpp.o" \
"CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o" \
"CMakeFiles/alien_invasion.dir/src/GameState.cpp.o"

# External object files for target alien_invasion
alien_invasion_EXTERNAL_OBJECTS =

alien_invasion: CMakeFiles/alien_invasion.dir/src/main.cpp.o
alien_invasion: CMakeFiles/alien_invasion.dir/src/Player.cpp.o
alien_invasion: CMakeFiles/alien_invasion.dir/src/Alien.cpp.o
alien_invasion: CMakeFiles/alien_invasion.dir/src/Projectile.cpp.o
alien_invasion: CMakeFiles/alien_invasion.dir/src/GameState.cpp.o
alien_invasion: CMakeFiles/alien_invasion.dir/build.make
alien_invasion: /opt/homebrew/lib/libsfml-graphics.2.6.2.dylib
alien_invasion: /opt/homebrew/lib/libsfml-window.2.6.2.dylib
alien_invasion: /opt/homebrew/lib/libsfml-audio.2.6.2.dylib
alien_invasion: /opt/homebrew/lib/libsfml-system.2.6.2.dylib
alien_invasion: CMakeFiles/alien_invasion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable alien_invasion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alien_invasion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alien_invasion.dir/build: alien_invasion
.PHONY : CMakeFiles/alien_invasion.dir/build

CMakeFiles/alien_invasion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alien_invasion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alien_invasion.dir/clean

CMakeFiles/alien_invasion.dir/depend:
	cd "/Users/danielmora/Desktop/alieninvasion copy/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/danielmora/Desktop/alieninvasion copy" "/Users/danielmora/Desktop/alieninvasion copy" "/Users/danielmora/Desktop/alieninvasion copy/build" "/Users/danielmora/Desktop/alieninvasion copy/build" "/Users/danielmora/Desktop/alieninvasion copy/build/CMakeFiles/alien_invasion.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/alien_invasion.dir/depend

