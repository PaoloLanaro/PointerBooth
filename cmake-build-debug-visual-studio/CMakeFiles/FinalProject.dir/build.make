﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio

# Include any dependencies generated for this target.
include CMakeFiles\FinalProject.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\FinalProject.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\FinalProject.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\FinalProject.dir\flags.make

CMakeFiles\FinalProject.dir\driver.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\driver.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\driver.cpp
CMakeFiles\FinalProject.dir\driver.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FinalProject.dir/driver.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\driver.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\driver.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\driver.cpp
<<

CMakeFiles\FinalProject.dir\driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/driver.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\driver.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\driver.cpp
<<

CMakeFiles\FinalProject.dir\driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/driver.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\driver.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\driver.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\Filter.cpp
CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/Filter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\Filter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/Filter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\Filter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/Filter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\Filter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\Filter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GrayScaleFilter.cpp
CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/GrayScaleFilter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GrayScaleFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/GrayScaleFilter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GrayScaleFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/GrayScaleFilter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GrayScaleFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GaussianBlurFilter.cpp
CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/GaussianBlurFilter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GaussianBlurFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/GaussianBlurFilter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GaussianBlurFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/GaussianBlurFilter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\GaussianBlurFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\SimpleBlurFilter.cpp
CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/SimpleBlurFilter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\SimpleBlurFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/SimpleBlurFilter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\SimpleBlurFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/SimpleBlurFilter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\SimpleBlurFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\OtsuThresholdingFilter.cpp
CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/OtsuThresholdingFilter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\OtsuThresholdingFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/OtsuThresholdingFilter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\OtsuThresholdingFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/OtsuThresholdingFilter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\OtsuThresholdingFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\ContourFilter.cpp
CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/ContourFilter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\ContourFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/ContourFilter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\ContourFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/ContourFilter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\ContourFilter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj: CMakeFiles\FinalProject.dir\flags.make
CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj: C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\MatAdapter.cpp
CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj: CMakeFiles\FinalProject.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/FinalProject.dir/lib/src/MatAdapter.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj.d --working-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj /FdCMakeFiles\FinalProject.dir\ /FS -c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\MatAdapter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FinalProject.dir/lib/src/MatAdapter.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe > CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\MatAdapter.cpp
<<

CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FinalProject.dir/lib/src/MatAdapter.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.s /c C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\lib\src\MatAdapter.cpp
<<

# Object files for target FinalProject
FinalProject_OBJECTS = \
"CMakeFiles\FinalProject.dir\driver.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj" \
"CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj"

# External object files for target FinalProject
FinalProject_EXTERNAL_OBJECTS =

FinalProject.exe: CMakeFiles\FinalProject.dir\driver.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\Filter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\GrayScaleFilter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\GaussianBlurFilter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\SimpleBlurFilter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\OtsuThresholdingFilter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\ContourFilter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\lib\src\MatAdapter.cpp.obj
FinalProject.exe: CMakeFiles\FinalProject.dir\build.make
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxmsw32ud_core.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxbase32ud.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxpngd.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxtiffd.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxjpegd.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxzlibd.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxregexud.lib
FinalProject.exe: C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxexpatd.lib
FinalProject.exe: C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib
FinalProject.exe: C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib
FinalProject.exe: C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib
FinalProject.exe: C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib
FinalProject.exe: CMakeFiles\FinalProject.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable FinalProject.exe"
	"C:\Program Files\JetBrains\CLion 2023.2.1\bin\cmake\win\x64\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\FinalProject.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x64\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x64\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\FinalProject.dir\objects1.rsp @<<
 /out:FinalProject.exe /implib:FinalProject.lib /pdb:C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\FinalProject.pdb /version:0.0 /machine:x64 /debug /INCREMENTAL /subsystem:console  C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxmsw32ud_core.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxbase32ud.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxpngd.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxtiffd.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxjpegd.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxzlibd.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxregexud.lib C:\wxWidgets-3.2.4\lib\vc14x_x64_dll\wxexpatd.lib winmm.lib comctl32.lib uuid.lib oleacc.lib uxtheme.lib rpcrt4.lib shlwapi.lib version.lib wsock32.lib C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib C:\tools\opencv\build\x64\vc16\lib\opencv_world481d.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\FinalProject.dir\build: FinalProject.exe
.PHONY : CMakeFiles\FinalProject.dir\build

CMakeFiles\FinalProject.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FinalProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles\FinalProject.dir\clean

CMakeFiles\FinalProject.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520 C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520 C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio C:\Users\dbusn\OneDrive\Documents\GitHub\FinalProjectCS3520\cmake-build-debug-visual-studio\CMakeFiles\FinalProject.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\FinalProject.dir\depend

