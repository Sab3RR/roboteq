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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sab3r/ws/src/algo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sab3r/ws/src/algo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/motor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/motor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/motor.dir/flags.make

CMakeFiles/motor.dir/src/rosdef.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/src/rosdef.cpp.o: ../src/rosdef.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/motor.dir/src/rosdef.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/src/rosdef.cpp.o -c /home/sab3r/ws/src/algo/src/rosdef.cpp

CMakeFiles/motor.dir/src/rosdef.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/src/rosdef.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sab3r/ws/src/algo/src/rosdef.cpp > CMakeFiles/motor.dir/src/rosdef.cpp.i

CMakeFiles/motor.dir/src/rosdef.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/src/rosdef.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sab3r/ws/src/algo/src/rosdef.cpp -o CMakeFiles/motor.dir/src/rosdef.cpp.s

CMakeFiles/motor.dir/src/MotorController.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/src/MotorController.cpp.o: ../src/MotorController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/motor.dir/src/MotorController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/src/MotorController.cpp.o -c /home/sab3r/ws/src/algo/src/MotorController.cpp

CMakeFiles/motor.dir/src/MotorController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/src/MotorController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sab3r/ws/src/algo/src/MotorController.cpp > CMakeFiles/motor.dir/src/MotorController.cpp.i

CMakeFiles/motor.dir/src/MotorController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/src/MotorController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sab3r/ws/src/algo/src/MotorController.cpp -o CMakeFiles/motor.dir/src/MotorController.cpp.s

CMakeFiles/motor.dir/src/Encoders.cpp.o: CMakeFiles/motor.dir/flags.make
CMakeFiles/motor.dir/src/Encoders.cpp.o: ../src/Encoders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/motor.dir/src/Encoders.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/motor.dir/src/Encoders.cpp.o -c /home/sab3r/ws/src/algo/src/Encoders.cpp

CMakeFiles/motor.dir/src/Encoders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/motor.dir/src/Encoders.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sab3r/ws/src/algo/src/Encoders.cpp > CMakeFiles/motor.dir/src/Encoders.cpp.i

CMakeFiles/motor.dir/src/Encoders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/motor.dir/src/Encoders.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sab3r/ws/src/algo/src/Encoders.cpp -o CMakeFiles/motor.dir/src/Encoders.cpp.s

# Object files for target motor
motor_OBJECTS = \
"CMakeFiles/motor.dir/src/rosdef.cpp.o" \
"CMakeFiles/motor.dir/src/MotorController.cpp.o" \
"CMakeFiles/motor.dir/src/Encoders.cpp.o"

# External object files for target motor
motor_EXTERNAL_OBJECTS =

devel/lib/algo/motor: CMakeFiles/motor.dir/src/rosdef.cpp.o
devel/lib/algo/motor: CMakeFiles/motor.dir/src/MotorController.cpp.o
devel/lib/algo/motor: CMakeFiles/motor.dir/src/Encoders.cpp.o
devel/lib/algo/motor: CMakeFiles/motor.dir/build.make
devel/lib/algo/motor: /opt/ros/melodic/lib/libtf.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libtf2_ros.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libactionlib.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libmessage_filters.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libroscpp.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libxmlrpcpp.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libtf2.so
devel/lib/algo/motor: /opt/ros/melodic/lib/librosconsole.so
devel/lib/algo/motor: /opt/ros/melodic/lib/librosconsole_log4cxx.so
devel/lib/algo/motor: /opt/ros/melodic/lib/librosconsole_backend_interface.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_regex.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libroscpp_serialization.so
devel/lib/algo/motor: /opt/ros/melodic/lib/librostime.so
devel/lib/algo/motor: /opt/ros/melodic/lib/libcpp_common.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_system.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_thread.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libpthread.so
devel/lib/algo/motor: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
devel/lib/algo/motor: CMakeFiles/motor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable devel/lib/algo/motor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/motor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/motor.dir/build: devel/lib/algo/motor

.PHONY : CMakeFiles/motor.dir/build

CMakeFiles/motor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/motor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/motor.dir/clean

CMakeFiles/motor.dir/depend:
	cd /home/sab3r/ws/src/algo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sab3r/ws/src/algo /home/sab3r/ws/src/algo /home/sab3r/ws/src/algo/cmake-build-debug /home/sab3r/ws/src/algo/cmake-build-debug /home/sab3r/ws/src/algo/cmake-build-debug/CMakeFiles/motor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/motor.dir/depend

