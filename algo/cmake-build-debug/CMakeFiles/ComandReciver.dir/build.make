# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sab3r/ws/src/algo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sab3r/ws/src/algo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ComandReciver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ComandReciver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ComandReciver.dir/flags.make

CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.o: CMakeFiles/ComandReciver.dir/flags.make
CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.o: ../src/ComandReceiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.o -c /home/sab3r/ws/src/algo/src/ComandReceiver.cpp

CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sab3r/ws/src/algo/src/ComandReceiver.cpp > CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.i

CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sab3r/ws/src/algo/src/ComandReceiver.cpp -o CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.s

# Object files for target ComandReciver
ComandReciver_OBJECTS = \
"CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.o"

# External object files for target ComandReciver
ComandReciver_EXTERNAL_OBJECTS =

devel/lib/algo/ComandReciver: CMakeFiles/ComandReciver.dir/src/ComandReceiver.cpp.o
devel/lib/algo/ComandReciver: CMakeFiles/ComandReciver.dir/build.make
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libtf.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libtf2_ros.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libactionlib.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libmessage_filters.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libroscpp.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libxmlrpcpp.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libtf2.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/librosconsole.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/librosconsole_log4cxx.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/librosconsole_backend_interface.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libroscpp_serialization.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/librostime.so
devel/lib/algo/ComandReciver: /opt/ros/melodic/lib/libcpp_common.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/algo/ComandReciver: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
devel/lib/algo/ComandReciver: CMakeFiles/ComandReciver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable devel/lib/algo/ComandReciver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ComandReciver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ComandReciver.dir/build: devel/lib/algo/ComandReciver

.PHONY : CMakeFiles/ComandReciver.dir/build

CMakeFiles/ComandReciver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ComandReciver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ComandReciver.dir/clean

CMakeFiles/ComandReciver.dir/depend:
	cd /home/sab3r/ws/src/algo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sab3r/ws/src/algo /home/sab3r/ws/src/algo /home/sab3r/ws/src/algo/cmake-build-debug /home/sab3r/ws/src/algo/cmake-build-debug /home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles/ComandReciver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ComandReciver.dir/depend

