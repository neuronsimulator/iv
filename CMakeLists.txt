cmake_minimum_required(VERSION 3.3.0 FATAL_ERROR)
project(iv C CXX)

# =============================================================================
# CMake common project settings
# =============================================================================
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

# =============================================================================
# Project build options
# =============================================================================
option(IV_BUILD_SHARED "Build libraries shared or static" OFF)

# =============================================================================
# CMake build settings
# =============================================================================
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

if(NOT ${IV_BUILD_SHARED})
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  set(IV_LIB_TYPE "STATIC")
else()
  set(IV_LIB_TYPE "SHARED")
endif()

# CYGWIN macros is used in the code
if(${CMAKE_SYSTEM_NAME} MATCHES "CYGWIN")
  set(CYGWIN 1)
endif()

# =============================================================================
# Find dependencies
# =============================================================================
find_package(X11)

if(NOT ${X11_FOUND})
  if(APPLE)
    message(FATAL_ERROR "Install XQuartz from https://www.xquartz.org/ to build iv")
  else()
    message(FATAL_ERROR "Install X11 to build iv (e.g. 'apt install libx11-dev libxcomposite-dev' on Ubuntu")
  endif()
endif()

# =============================================================================
# Include cmake modules
# =============================================================================
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(HelperFunctions)
include(PlatformHelper)
include(RpathHelper)
include(CheckIncludeFiles)
include(CheckFunctionExists)

# =============================================================================
# Check existance of various headers, functions and directories
# =============================================================================
check_include_files(fcntl.h HAVE_FCNTL_H)
check_include_files(malloc.h HAVE_MALLOC_H)
check_include_files(memory.h HAVE_MEMORY_H)
check_include_files(osfcn.h HAVE_OSFCN_H)
check_include_files(socket.h HAVE_SOCKET_H)
check_include_files(stdint.h HAVE_STDINT_H)
check_include_files(stdlib.h HAVE_STDLIB_H)
check_include_files(string.h HAVE_STRING_H)
check_include_files(strings.h HAVE_STRINGS_H)
check_include_files(stropts.h HAVE_STROPTS_H)
check_include_files(stream.h HAVE_STREAM_H)
check_include_files(sys/conf.h HAVE_SYS_CONF_H)
check_include_files(sys/file.h HAVE_SYS_FILE_H)
check_include_files(sys/ioctl.h HAVE_SYS_IOCTL_H)
check_include_files(sys/mman.h HAVE_SYS_MMAN_H)
check_include_files(sys/param.h HAVE_SYS_PARAM_H)
check_include_files(sys/stat.h HAVE_SYS_STAT_H)
check_include_files(sys/time.h HAVE_SYS_TIME_H)
check_include_files(unistd.h HAVE_UNISTD_H)

check_function_exists(getcwd HAVE_GETCWD)
check_function_exists(gettimeofday HAVE_GETTIMEOFDAY)
check_function_exists(mmap HAVE_MMAP)
check_function_exists(sigprocmask HAVE_POSIX_SIGNALS)
check_function_exists(socket HAVE_SOCKET)
check_function_exists(strcspn HAVE_STRCSPN)
check_function_exists(strerror HAVE_STRERROR)
check_function_exists(strtod HAVE_STRTOD)
check_function_exists(strtol HAVE_STRTOL)
check_function_exists(uname HAVE_UNAME)

iv_check_dir_exists(dirent.h HAVE_DIRENT_H)
iv_check_dir_exists(ndir.h HAVE_NDIR_H)
iv_check_dir_exists(sys/dir.h HAVE_SYS_DIR_H)
iv_check_dir_exists(sys/ndir.h HAVE_SYS_NDIR_H)

iv_check_type_exists(sys/types.h gid_t int gid_t)
iv_check_type_exists(sys/types.h off_t "long int" off_t)
iv_check_type_exists(sys/types.h pid_t int pid_t)
iv_check_type_exists(sys/types.h size_t "unsigned int" size_t)
iv_check_type_exists(sys/types.h uid_t int uid_t)

# =============================================================================
# Check if signals support
# =============================================================================
# NOTE: check_function_exists(sigsetmask HAVE_BSD_SIGNALS) made obsolete by sigprocmask(2).
# sigsetmask exists but the usage generates a variety of errors. See the old autoconf acinclude.m4
# AC_DEFUN([BASH_SIGNAL_CHECK] For now, use only if don't have posix signals.
if(NOT ${HAVE_POSIX_SIGNALS})
  set(HAVE_BSD_SIGNALS 1)
else()
  set(HAVE_BSD_SIGNALS 0)
endif()

# =============================================================================
# Set return type of signal in RETSIGTYPE
# =============================================================================
iv_check_signal_return_type(RETSIGTYPE)

# =============================================================================
# Generate config.h after all checks
# =============================================================================
add_definitions(-DHAVE_CONFIG_H)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

# =============================================================================
# Include source directories
# =============================================================================
include_directories(${PROJECT_SOURCE_DIR}/src/include)
add_subdirectory(src/bin)
add_subdirectory(src/lib)

# =============================================================================
# Install binaries and headers
# =============================================================================
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/include/ DESTINATION include)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/iv-config.cmake DESTINATION share/cmake/iv/)
install(EXPORT iv NAMESPACE iv_ DESTINATION share/cmake/iv)
