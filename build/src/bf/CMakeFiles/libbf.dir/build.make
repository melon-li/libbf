# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /root/libbf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/libbf/build

# Include any dependencies generated for this target.
include src/bf/CMakeFiles/libbf.dir/depend.make

# Include the progress variables for this target.
include src/bf/CMakeFiles/libbf.dir/progress.make

# Include the compile flags for this target's objects.
include src/bf/CMakeFiles/libbf.dir/flags.make

src/bf/CMakeFiles/libbf.dir/bitvector.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/bitvector.cc.o: ../src/bf/bitvector.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/bitvector.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/bitvector.cc.o -c /root/libbf/src/bf/bitvector.cc

src/bf/CMakeFiles/libbf.dir/bitvector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/bitvector.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/bitvector.cc > CMakeFiles/libbf.dir/bitvector.cc.i

src/bf/CMakeFiles/libbf.dir/bitvector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/bitvector.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/bitvector.cc -o CMakeFiles/libbf.dir/bitvector.cc.s

src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.requires

src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.provides: src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.provides

src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/bitvector.cc.o

src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o: ../src/bf/counter_vector.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/counter_vector.cc.o -c /root/libbf/src/bf/counter_vector.cc

src/bf/CMakeFiles/libbf.dir/counter_vector.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/counter_vector.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/counter_vector.cc > CMakeFiles/libbf.dir/counter_vector.cc.i

src/bf/CMakeFiles/libbf.dir/counter_vector.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/counter_vector.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/counter_vector.cc -o CMakeFiles/libbf.dir/counter_vector.cc.s

src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.requires

src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.provides: src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.provides

src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o

src/bf/CMakeFiles/libbf.dir/hash.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/hash.cc.o: ../src/bf/hash.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/hash.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/hash.cc.o -c /root/libbf/src/bf/hash.cc

src/bf/CMakeFiles/libbf.dir/hash.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/hash.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/hash.cc > CMakeFiles/libbf.dir/hash.cc.i

src/bf/CMakeFiles/libbf.dir/hash.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/hash.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/hash.cc -o CMakeFiles/libbf.dir/hash.cc.s

src/bf/CMakeFiles/libbf.dir/hash.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/hash.cc.o.requires

src/bf/CMakeFiles/libbf.dir/hash.cc.o.provides: src/bf/CMakeFiles/libbf.dir/hash.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/hash.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/hash.cc.o.provides

src/bf/CMakeFiles/libbf.dir/hash.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/hash.cc.o

src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o: ../src/bf/bloom_filter/a2.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/bloom_filter/a2.cc.o -c /root/libbf/src/bf/bloom_filter/a2.cc

src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/bloom_filter/a2.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/bloom_filter/a2.cc > CMakeFiles/libbf.dir/bloom_filter/a2.cc.i

src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/bloom_filter/a2.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/bloom_filter/a2.cc -o CMakeFiles/libbf.dir/bloom_filter/a2.cc.s

src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.requires

src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.provides: src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.provides

src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o

src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o: ../src/bf/bloom_filter/basic.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/bloom_filter/basic.cc.o -c /root/libbf/src/bf/bloom_filter/basic.cc

src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/bloom_filter/basic.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/bloom_filter/basic.cc > CMakeFiles/libbf.dir/bloom_filter/basic.cc.i

src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/bloom_filter/basic.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/bloom_filter/basic.cc -o CMakeFiles/libbf.dir/bloom_filter/basic.cc.s

src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.requires

src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.provides: src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.provides

src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o

src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o: ../src/bf/bloom_filter/bitwise.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o -c /root/libbf/src/bf/bloom_filter/bitwise.cc

src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/bloom_filter/bitwise.cc > CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.i

src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/bloom_filter/bitwise.cc -o CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.s

src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.requires

src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.provides: src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.provides

src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o

src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o: ../src/bf/bloom_filter/counting.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/bloom_filter/counting.cc.o -c /root/libbf/src/bf/bloom_filter/counting.cc

src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/bloom_filter/counting.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/bloom_filter/counting.cc > CMakeFiles/libbf.dir/bloom_filter/counting.cc.i

src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/bloom_filter/counting.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/bloom_filter/counting.cc -o CMakeFiles/libbf.dir/bloom_filter/counting.cc.s

src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.requires

src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.provides: src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.provides

src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o

src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o: src/bf/CMakeFiles/libbf.dir/flags.make
src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o: ../src/bf/bloom_filter/stable.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /root/libbf/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o"
	cd /root/libbf/build/src/bf && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libbf.dir/bloom_filter/stable.cc.o -c /root/libbf/src/bf/bloom_filter/stable.cc

src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libbf.dir/bloom_filter/stable.cc.i"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/libbf/src/bf/bloom_filter/stable.cc > CMakeFiles/libbf.dir/bloom_filter/stable.cc.i

src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libbf.dir/bloom_filter/stable.cc.s"
	cd /root/libbf/build/src/bf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/libbf/src/bf/bloom_filter/stable.cc -o CMakeFiles/libbf.dir/bloom_filter/stable.cc.s

src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.requires:
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.requires

src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.provides: src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.requires
	$(MAKE) -f src/bf/CMakeFiles/libbf.dir/build.make src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.provides.build
.PHONY : src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.provides

src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.provides.build: src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o

# Object files for target libbf
libbf_OBJECTS = \
"CMakeFiles/libbf.dir/bitvector.cc.o" \
"CMakeFiles/libbf.dir/counter_vector.cc.o" \
"CMakeFiles/libbf.dir/hash.cc.o" \
"CMakeFiles/libbf.dir/bloom_filter/a2.cc.o" \
"CMakeFiles/libbf.dir/bloom_filter/basic.cc.o" \
"CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o" \
"CMakeFiles/libbf.dir/bloom_filter/counting.cc.o" \
"CMakeFiles/libbf.dir/bloom_filter/stable.cc.o"

# External object files for target libbf
libbf_EXTERNAL_OBJECTS =

src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/bitvector.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/hash.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/build.make
src/bf/libbf.so: src/bf/CMakeFiles/libbf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libbf.so"
	cd /root/libbf/build/src/bf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libbf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/bf/CMakeFiles/libbf.dir/build: src/bf/libbf.so
.PHONY : src/bf/CMakeFiles/libbf.dir/build

src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/bitvector.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/counter_vector.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/hash.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/bloom_filter/a2.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/bloom_filter/basic.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/bloom_filter/bitwise.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/bloom_filter/counting.cc.o.requires
src/bf/CMakeFiles/libbf.dir/requires: src/bf/CMakeFiles/libbf.dir/bloom_filter/stable.cc.o.requires
.PHONY : src/bf/CMakeFiles/libbf.dir/requires

src/bf/CMakeFiles/libbf.dir/clean:
	cd /root/libbf/build/src/bf && $(CMAKE_COMMAND) -P CMakeFiles/libbf.dir/cmake_clean.cmake
.PHONY : src/bf/CMakeFiles/libbf.dir/clean

src/bf/CMakeFiles/libbf.dir/depend:
	cd /root/libbf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/libbf /root/libbf/src/bf /root/libbf/build /root/libbf/build/src/bf /root/libbf/build/src/bf/CMakeFiles/libbf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/bf/CMakeFiles/libbf.dir/depend

