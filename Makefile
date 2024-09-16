# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/joseph/CSE220/cse220_hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joseph/CSE220/cse220_hw1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/joseph/CSE220/cse220_hw1/CMakeFiles /home/joseph/CSE220/cse220_hw1//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/joseph/CSE220/cse220_hw1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named hw1_game

# Build rule for target.
hw1_game: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hw1_game
.PHONY : hw1_game

# fast build rule for target.
hw1_game/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/build
.PHONY : hw1_game/fast

#=============================================================================
# Target rules for targets named hw1_solver

# Build rule for target.
hw1_solver: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hw1_solver
.PHONY : hw1_solver

# fast build rule for target.
hw1_solver/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/build
.PHONY : hw1_solver/fast

#=============================================================================
# Target rules for targets named hw1_generator

# Build rule for target.
hw1_generator: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hw1_generator
.PHONY : hw1_generator

# fast build rule for target.
hw1_generator/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/build
.PHONY : hw1_generator/fast

#=============================================================================
# Target rules for targets named run_all_tests

# Build rule for target.
run_all_tests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 run_all_tests
.PHONY : run_all_tests

# fast build rule for target.
run_all_tests/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/build
.PHONY : run_all_tests/fast

#=============================================================================
# Target rules for targets named asan_board12x7

# Build rule for target.
asan_board12x7: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asan_board12x7
.PHONY : asan_board12x7

# fast build rule for target.
asan_board12x7/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/build
.PHONY : asan_board12x7/fast

#=============================================================================
# Target rules for targets named asan_board20x20

# Build rule for target.
asan_board20x20: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asan_board20x20
.PHONY : asan_board20x20

# fast build rule for target.
asan_board20x20/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/build
.PHONY : asan_board20x20/fast

#=============================================================================
# Target rules for targets named asan_board4x4

# Build rule for target.
asan_board4x4: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asan_board4x4
.PHONY : asan_board4x4

# fast build rule for target.
asan_board4x4/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/build
.PHONY : asan_board4x4/fast

#=============================================================================
# Target rules for targets named asan_board_gen13x8

# Build rule for target.
asan_board_gen13x8: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asan_board_gen13x8
.PHONY : asan_board_gen13x8

# fast build rule for target.
asan_board_gen13x8/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/build
.PHONY : asan_board_gen13x8/fast

#=============================================================================
# Target rules for targets named asan_board_gen20x20

# Build rule for target.
asan_board_gen20x20: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asan_board_gen20x20
.PHONY : asan_board_gen20x20

# fast build rule for target.
asan_board_gen20x20/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/build
.PHONY : asan_board_gen20x20/fast

#=============================================================================
# Target rules for targets named asan_board_gen5x5

# Build rule for target.
asan_board_gen5x5: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asan_board_gen5x5
.PHONY : asan_board_gen5x5

# fast build rule for target.
asan_board_gen5x5/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/build
.PHONY : asan_board_gen5x5/fast

src/hw1.o: src/hw1.c.o
.PHONY : src/hw1.o

# target to build an object file
src/hw1.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/src/hw1.c.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/src/hw1.c.o
.PHONY : src/hw1.c.o

src/hw1.i: src/hw1.c.i
.PHONY : src/hw1.i

# target to preprocess a source file
src/hw1.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/src/hw1.c.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/src/hw1.c.i
.PHONY : src/hw1.c.i

src/hw1.s: src/hw1.c.s
.PHONY : src/hw1.s

# target to generate assembly for a file
src/hw1.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/src/hw1.c.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/src/hw1.c.s
.PHONY : src/hw1.c.s

src/hw1_game.o: src/hw1_game.c.o
.PHONY : src/hw1_game.o

# target to build an object file
src/hw1_game.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/src/hw1_game.c.o
.PHONY : src/hw1_game.c.o

src/hw1_game.i: src/hw1_game.c.i
.PHONY : src/hw1_game.i

# target to preprocess a source file
src/hw1_game.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/src/hw1_game.c.i
.PHONY : src/hw1_game.c.i

src/hw1_game.s: src/hw1_game.c.s
.PHONY : src/hw1_game.s

# target to generate assembly for a file
src/hw1_game.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_game.dir/build.make CMakeFiles/hw1_game.dir/src/hw1_game.c.s
.PHONY : src/hw1_game.c.s

src/hw1_generator.o: src/hw1_generator.c.o
.PHONY : src/hw1_generator.o

# target to build an object file
src/hw1_generator.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/src/hw1_generator.c.o
.PHONY : src/hw1_generator.c.o

src/hw1_generator.i: src/hw1_generator.c.i
.PHONY : src/hw1_generator.i

# target to preprocess a source file
src/hw1_generator.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/src/hw1_generator.c.i
.PHONY : src/hw1_generator.c.i

src/hw1_generator.s: src/hw1_generator.c.s
.PHONY : src/hw1_generator.s

# target to generate assembly for a file
src/hw1_generator.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_generator.dir/build.make CMakeFiles/hw1_generator.dir/src/hw1_generator.c.s
.PHONY : src/hw1_generator.c.s

src/hw1_solver.o: src/hw1_solver.c.o
.PHONY : src/hw1_solver.o

# target to build an object file
src/hw1_solver.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/src/hw1_solver.c.o
.PHONY : src/hw1_solver.c.o

src/hw1_solver.i: src/hw1_solver.c.i
.PHONY : src/hw1_solver.i

# target to preprocess a source file
src/hw1_solver.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/src/hw1_solver.c.i
.PHONY : src/hw1_solver.c.i

src/hw1_solver.s: src/hw1_solver.c.s
.PHONY : src/hw1_solver.s

# target to generate assembly for a file
src/hw1_solver.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw1_solver.dir/build.make CMakeFiles/hw1_solver.dir/src/hw1_solver.c.s
.PHONY : src/hw1_solver.c.s

tests/src/asan_board12x7.o: tests/src/asan_board12x7.c.o
.PHONY : tests/src/asan_board12x7.o

# target to build an object file
tests/src/asan_board12x7.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/tests/src/asan_board12x7.c.o
.PHONY : tests/src/asan_board12x7.c.o

tests/src/asan_board12x7.i: tests/src/asan_board12x7.c.i
.PHONY : tests/src/asan_board12x7.i

# target to preprocess a source file
tests/src/asan_board12x7.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/tests/src/asan_board12x7.c.i
.PHONY : tests/src/asan_board12x7.c.i

tests/src/asan_board12x7.s: tests/src/asan_board12x7.c.s
.PHONY : tests/src/asan_board12x7.s

# target to generate assembly for a file
tests/src/asan_board12x7.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board12x7.dir/build.make CMakeFiles/asan_board12x7.dir/tests/src/asan_board12x7.c.s
.PHONY : tests/src/asan_board12x7.c.s

tests/src/asan_board20x20.o: tests/src/asan_board20x20.c.o
.PHONY : tests/src/asan_board20x20.o

# target to build an object file
tests/src/asan_board20x20.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/tests/src/asan_board20x20.c.o
.PHONY : tests/src/asan_board20x20.c.o

tests/src/asan_board20x20.i: tests/src/asan_board20x20.c.i
.PHONY : tests/src/asan_board20x20.i

# target to preprocess a source file
tests/src/asan_board20x20.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/tests/src/asan_board20x20.c.i
.PHONY : tests/src/asan_board20x20.c.i

tests/src/asan_board20x20.s: tests/src/asan_board20x20.c.s
.PHONY : tests/src/asan_board20x20.s

# target to generate assembly for a file
tests/src/asan_board20x20.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board20x20.dir/build.make CMakeFiles/asan_board20x20.dir/tests/src/asan_board20x20.c.s
.PHONY : tests/src/asan_board20x20.c.s

tests/src/asan_board4x4.o: tests/src/asan_board4x4.c.o
.PHONY : tests/src/asan_board4x4.o

# target to build an object file
tests/src/asan_board4x4.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/tests/src/asan_board4x4.c.o
.PHONY : tests/src/asan_board4x4.c.o

tests/src/asan_board4x4.i: tests/src/asan_board4x4.c.i
.PHONY : tests/src/asan_board4x4.i

# target to preprocess a source file
tests/src/asan_board4x4.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/tests/src/asan_board4x4.c.i
.PHONY : tests/src/asan_board4x4.c.i

tests/src/asan_board4x4.s: tests/src/asan_board4x4.c.s
.PHONY : tests/src/asan_board4x4.s

# target to generate assembly for a file
tests/src/asan_board4x4.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board4x4.dir/build.make CMakeFiles/asan_board4x4.dir/tests/src/asan_board4x4.c.s
.PHONY : tests/src/asan_board4x4.c.s

tests/src/asan_board_gen13x8.o: tests/src/asan_board_gen13x8.c.o
.PHONY : tests/src/asan_board_gen13x8.o

# target to build an object file
tests/src/asan_board_gen13x8.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/tests/src/asan_board_gen13x8.c.o
.PHONY : tests/src/asan_board_gen13x8.c.o

tests/src/asan_board_gen13x8.i: tests/src/asan_board_gen13x8.c.i
.PHONY : tests/src/asan_board_gen13x8.i

# target to preprocess a source file
tests/src/asan_board_gen13x8.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/tests/src/asan_board_gen13x8.c.i
.PHONY : tests/src/asan_board_gen13x8.c.i

tests/src/asan_board_gen13x8.s: tests/src/asan_board_gen13x8.c.s
.PHONY : tests/src/asan_board_gen13x8.s

# target to generate assembly for a file
tests/src/asan_board_gen13x8.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen13x8.dir/build.make CMakeFiles/asan_board_gen13x8.dir/tests/src/asan_board_gen13x8.c.s
.PHONY : tests/src/asan_board_gen13x8.c.s

tests/src/asan_board_gen20x20.o: tests/src/asan_board_gen20x20.c.o
.PHONY : tests/src/asan_board_gen20x20.o

# target to build an object file
tests/src/asan_board_gen20x20.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/tests/src/asan_board_gen20x20.c.o
.PHONY : tests/src/asan_board_gen20x20.c.o

tests/src/asan_board_gen20x20.i: tests/src/asan_board_gen20x20.c.i
.PHONY : tests/src/asan_board_gen20x20.i

# target to preprocess a source file
tests/src/asan_board_gen20x20.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/tests/src/asan_board_gen20x20.c.i
.PHONY : tests/src/asan_board_gen20x20.c.i

tests/src/asan_board_gen20x20.s: tests/src/asan_board_gen20x20.c.s
.PHONY : tests/src/asan_board_gen20x20.s

# target to generate assembly for a file
tests/src/asan_board_gen20x20.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen20x20.dir/build.make CMakeFiles/asan_board_gen20x20.dir/tests/src/asan_board_gen20x20.c.s
.PHONY : tests/src/asan_board_gen20x20.c.s

tests/src/asan_board_gen5x5.o: tests/src/asan_board_gen5x5.c.o
.PHONY : tests/src/asan_board_gen5x5.o

# target to build an object file
tests/src/asan_board_gen5x5.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/tests/src/asan_board_gen5x5.c.o
.PHONY : tests/src/asan_board_gen5x5.c.o

tests/src/asan_board_gen5x5.i: tests/src/asan_board_gen5x5.c.i
.PHONY : tests/src/asan_board_gen5x5.i

# target to preprocess a source file
tests/src/asan_board_gen5x5.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/tests/src/asan_board_gen5x5.c.i
.PHONY : tests/src/asan_board_gen5x5.c.i

tests/src/asan_board_gen5x5.s: tests/src/asan_board_gen5x5.c.s
.PHONY : tests/src/asan_board_gen5x5.s

# target to generate assembly for a file
tests/src/asan_board_gen5x5.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/asan_board_gen5x5.dir/build.make CMakeFiles/asan_board_gen5x5.dir/tests/src/asan_board_gen5x5.c.s
.PHONY : tests/src/asan_board_gen5x5.c.s

tests/src/generator_unit_tests.o: tests/src/generator_unit_tests.cpp.o
.PHONY : tests/src/generator_unit_tests.o

# target to build an object file
tests/src/generator_unit_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/generator_unit_tests.cpp.o
.PHONY : tests/src/generator_unit_tests.cpp.o

tests/src/generator_unit_tests.i: tests/src/generator_unit_tests.cpp.i
.PHONY : tests/src/generator_unit_tests.i

# target to preprocess a source file
tests/src/generator_unit_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/generator_unit_tests.cpp.i
.PHONY : tests/src/generator_unit_tests.cpp.i

tests/src/generator_unit_tests.s: tests/src/generator_unit_tests.cpp.s
.PHONY : tests/src/generator_unit_tests.s

# target to generate assembly for a file
tests/src/generator_unit_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/generator_unit_tests.cpp.s
.PHONY : tests/src/generator_unit_tests.cpp.s

tests/src/generator_unit_tests_asan.o: tests/src/generator_unit_tests_asan.cpp.o
.PHONY : tests/src/generator_unit_tests_asan.o

# target to build an object file
tests/src/generator_unit_tests_asan.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/generator_unit_tests_asan.cpp.o
.PHONY : tests/src/generator_unit_tests_asan.cpp.o

tests/src/generator_unit_tests_asan.i: tests/src/generator_unit_tests_asan.cpp.i
.PHONY : tests/src/generator_unit_tests_asan.i

# target to preprocess a source file
tests/src/generator_unit_tests_asan.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/generator_unit_tests_asan.cpp.i
.PHONY : tests/src/generator_unit_tests_asan.cpp.i

tests/src/generator_unit_tests_asan.s: tests/src/generator_unit_tests_asan.cpp.s
.PHONY : tests/src/generator_unit_tests_asan.s

# target to generate assembly for a file
tests/src/generator_unit_tests_asan.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/generator_unit_tests_asan.cpp.s
.PHONY : tests/src/generator_unit_tests_asan.cpp.s

tests/src/solver_unit_tests.o: tests/src/solver_unit_tests.cpp.o
.PHONY : tests/src/solver_unit_tests.o

# target to build an object file
tests/src/solver_unit_tests.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/solver_unit_tests.cpp.o
.PHONY : tests/src/solver_unit_tests.cpp.o

tests/src/solver_unit_tests.i: tests/src/solver_unit_tests.cpp.i
.PHONY : tests/src/solver_unit_tests.i

# target to preprocess a source file
tests/src/solver_unit_tests.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/solver_unit_tests.cpp.i
.PHONY : tests/src/solver_unit_tests.cpp.i

tests/src/solver_unit_tests.s: tests/src/solver_unit_tests.cpp.s
.PHONY : tests/src/solver_unit_tests.s

# target to generate assembly for a file
tests/src/solver_unit_tests.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/solver_unit_tests.cpp.s
.PHONY : tests/src/solver_unit_tests.cpp.s

tests/src/solver_unit_tests_asan.o: tests/src/solver_unit_tests_asan.cpp.o
.PHONY : tests/src/solver_unit_tests_asan.o

# target to build an object file
tests/src/solver_unit_tests_asan.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/solver_unit_tests_asan.cpp.o
.PHONY : tests/src/solver_unit_tests_asan.cpp.o

tests/src/solver_unit_tests_asan.i: tests/src/solver_unit_tests_asan.cpp.i
.PHONY : tests/src/solver_unit_tests_asan.i

# target to preprocess a source file
tests/src/solver_unit_tests_asan.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/solver_unit_tests_asan.cpp.i
.PHONY : tests/src/solver_unit_tests_asan.cpp.i

tests/src/solver_unit_tests_asan.s: tests/src/solver_unit_tests_asan.cpp.s
.PHONY : tests/src/solver_unit_tests_asan.s

# target to generate assembly for a file
tests/src/solver_unit_tests_asan.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/solver_unit_tests_asan.cpp.s
.PHONY : tests/src/solver_unit_tests_asan.cpp.s

tests/src/tests_utils.o: tests/src/tests_utils.cpp.o
.PHONY : tests/src/tests_utils.o

# target to build an object file
tests/src/tests_utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/tests_utils.cpp.o
.PHONY : tests/src/tests_utils.cpp.o

tests/src/tests_utils.i: tests/src/tests_utils.cpp.i
.PHONY : tests/src/tests_utils.i

# target to preprocess a source file
tests/src/tests_utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/tests_utils.cpp.i
.PHONY : tests/src/tests_utils.cpp.i

tests/src/tests_utils.s: tests/src/tests_utils.cpp.s
.PHONY : tests/src/tests_utils.s

# target to generate assembly for a file
tests/src/tests_utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/run_all_tests.dir/build.make CMakeFiles/run_all_tests.dir/tests/src/tests_utils.cpp.s
.PHONY : tests/src/tests_utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... asan_board12x7"
	@echo "... asan_board20x20"
	@echo "... asan_board4x4"
	@echo "... asan_board_gen13x8"
	@echo "... asan_board_gen20x20"
	@echo "... asan_board_gen5x5"
	@echo "... hw1_game"
	@echo "... hw1_generator"
	@echo "... hw1_solver"
	@echo "... run_all_tests"
	@echo "... src/hw1.o"
	@echo "... src/hw1.i"
	@echo "... src/hw1.s"
	@echo "... src/hw1_game.o"
	@echo "... src/hw1_game.i"
	@echo "... src/hw1_game.s"
	@echo "... src/hw1_generator.o"
	@echo "... src/hw1_generator.i"
	@echo "... src/hw1_generator.s"
	@echo "... src/hw1_solver.o"
	@echo "... src/hw1_solver.i"
	@echo "... src/hw1_solver.s"
	@echo "... tests/src/asan_board12x7.o"
	@echo "... tests/src/asan_board12x7.i"
	@echo "... tests/src/asan_board12x7.s"
	@echo "... tests/src/asan_board20x20.o"
	@echo "... tests/src/asan_board20x20.i"
	@echo "... tests/src/asan_board20x20.s"
	@echo "... tests/src/asan_board4x4.o"
	@echo "... tests/src/asan_board4x4.i"
	@echo "... tests/src/asan_board4x4.s"
	@echo "... tests/src/asan_board_gen13x8.o"
	@echo "... tests/src/asan_board_gen13x8.i"
	@echo "... tests/src/asan_board_gen13x8.s"
	@echo "... tests/src/asan_board_gen20x20.o"
	@echo "... tests/src/asan_board_gen20x20.i"
	@echo "... tests/src/asan_board_gen20x20.s"
	@echo "... tests/src/asan_board_gen5x5.o"
	@echo "... tests/src/asan_board_gen5x5.i"
	@echo "... tests/src/asan_board_gen5x5.s"
	@echo "... tests/src/generator_unit_tests.o"
	@echo "... tests/src/generator_unit_tests.i"
	@echo "... tests/src/generator_unit_tests.s"
	@echo "... tests/src/generator_unit_tests_asan.o"
	@echo "... tests/src/generator_unit_tests_asan.i"
	@echo "... tests/src/generator_unit_tests_asan.s"
	@echo "... tests/src/solver_unit_tests.o"
	@echo "... tests/src/solver_unit_tests.i"
	@echo "... tests/src/solver_unit_tests.s"
	@echo "... tests/src/solver_unit_tests_asan.o"
	@echo "... tests/src/solver_unit_tests_asan.i"
	@echo "... tests/src/solver_unit_tests_asan.s"
	@echo "... tests/src/tests_utils.o"
	@echo "... tests/src/tests_utils.i"
	@echo "... tests/src/tests_utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
