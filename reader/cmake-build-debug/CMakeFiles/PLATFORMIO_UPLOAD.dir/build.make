# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader\cmake-build-debug

# Utility rule file for PLATFORMIO_UPLOAD.

# Include the progress variables for this target.
include CMakeFiles/PLATFORMIO_UPLOAD.dir/progress.make

CMakeFiles/PLATFORMIO_UPLOAD:
	cd /d C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader && C:\Python27\Scripts\platformio.exe -f -c clion run --target upload

PLATFORMIO_UPLOAD: CMakeFiles/PLATFORMIO_UPLOAD
PLATFORMIO_UPLOAD: CMakeFiles/PLATFORMIO_UPLOAD.dir/build.make

.PHONY : PLATFORMIO_UPLOAD

# Rule to build all files generated by this target.
CMakeFiles/PLATFORMIO_UPLOAD.dir/build: PLATFORMIO_UPLOAD

.PHONY : CMakeFiles/PLATFORMIO_UPLOAD.dir/build

CMakeFiles/PLATFORMIO_UPLOAD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PLATFORMIO_UPLOAD.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PLATFORMIO_UPLOAD.dir/clean

CMakeFiles/PLATFORMIO_UPLOAD.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader\cmake-build-debug C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader\cmake-build-debug C:\Users\Goncalo\Desktop\inventions_RFId_CheckIn\reader\cmake-build-debug\CMakeFiles\PLATFORMIO_UPLOAD.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PLATFORMIO_UPLOAD.dir/depend

