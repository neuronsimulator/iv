cmake_minimum_required(VERSION 3.3.0 FATAL_ERROR)
project(iv C CXX)

# =============================================================================
# CMake common project settings
# =============================================================================
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)


option(IV_BUILD_SHARED "Build libraries shared or static" OFF)


# =============================================================================
# Compile static libraries with hidden visibility
# =============================================================================
if(NOT ${IV_BUILD_SHARED})
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
endif()

# =============================================================================
# Find required packages
# =============================================================================
message(STATUS "CHECKING FOR X11")
find_package(X11)

if(NOT ${X11_FOUND})
  if (APPLE)
    message(FATAL_ERROR "You must install XQuartz from https://www.xquartz.org/ to build iv")
  endif()
endif()

# =============================================================================
# Include cmake modules
# =============================================================================
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(RpathHelper)


include_directories(${PROJECT_SOURCE_DIR}/src/include)

# =============================================================================
# Project version from git and project directories
# =============================================================================
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

add_definitions(-DHAVE_CONFIG_H)

include(CheckIncludeFiles)
include(CheckFunctionExists)

macro(have_dir HEADER VARIABLE)
  set(CONFTEST_DIR_TPL "
  #include <sys/types.h>
  #include <@dir_hdr@>

  int main () {
    if ((DIR *) 0)
      return 0\;
    return 0\;
  }
  ")
  check_include_files(${HEADER} HAVE_HEADER)
  if (${HAVE_HEADER})
    string(REPLACE "@dir_hdr@" ${HEADER} CONFTEST_DIR "${CONFTEST_DIR_TPL}")
    file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/conftest.c ${CONFTEST_DIR})
    try_compile(RESULT_VAR ${CMAKE_CURRENT_SOURCE_DIR} 
      ${CMAKE_CURRENT_SOURCE_DIR}/conftest.c)
    set(${VARIABLE} ${RESULT_VAR})
    message(STATUS "${VARIABLE}: ${RESULT_VAR}")
    file(REMOVE "conftest.c")
  endif()
endmacro()

macro(have_type HEADER TYPE DEFAULT_TYPE VARIABLE)
  set(CONFTEST_TYPE_TPL "
  #include <@hdr@>
  int main () {
    if (sizeof (@type@))
      return 0\;
    return 0\;
  }
  ")
  string(REPLACE "@hdr@" ${HEADER} CONFTEST_TYPE "${CONFTEST_TYPE_TPL}")
  string(REPLACE "@type@" ${TYPE} CONFTEST_TYPE "${CONFTEST_TYPE}")
  file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/conftest.c ${CONFTEST_TYPE})
  try_compile(RESULT_VAR ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/conftest.c)
  if(NOT ${RESULT_VAR})
    set(${VARIABLE} ${DEFAULT_TYPE})
  endif()
  message(STATUS "${VARIABLE}: ${RESULT_VAR}")
  #file(REMOVE "conftest.c")
endmacro()


have_dir(dirent.h HAVE_DIRENT_H)
have_dir(ndir.h HAVE_NDIR_H)
have_dir(sys/dir.h HAVE_SYS_DIR_H)
have_dir(sys/ndir.h HAVE_SYS_NDIR_H)

check_include_files(fcntl.h HAVE_FCNTL_H)
check_function_exists(getcwd HAVE_GETCWD)
check_function_exists(gettimeofday HAVE_GETTIMEOFDAY)
check_include_files(malloc.h HAVE_MALLOC_H)
check_include_files(memory.h HAVE_MEMORY_H)
check_function_exists(mmap HAVE_MMAP)
check_include_files(osfcn.h HAVE_OSFCN_H)
check_function_exists(sigprocmask HAVE_POSIX_SIGNALS)
check_include_files(socket.h HAVE_SOCKET_H)
check_function_exists(socket HAVE_SOCKET)
check_include_files(stdint.h HAVE_STDINT_H)
check_include_files(stdlib.h HAVE_STDLIB_H)
check_function_exists(strcspn HAVE_STRCSPN)
check_include_files(stream.h HAVE_STREAM_H)
check_function_exists(strerror HAVE_STRERROR)
check_include_files(string.h HAVE_STRING_H)
check_include_files(strings.h HAVE_STRINGS_H)
check_include_files(stropts.h HAVE_STROPTS_H)
check_function_exists(strtod HAVE_STRTOD)
check_function_exists(strtol HAVE_STRTOL)
check_include_files(sys/conf.h HAVE_SYS_CONF_H)
check_include_files(sys/file.h HAVE_SYS_FILE_H)
check_include_files(sys/ioctl.h HAVE_SYS_IOCTL_H)
check_include_files(sys/mman.h HAVE_SYS_MMAN_H)
check_include_files(sys/param.h HAVE_SYS_PARAM_H)
check_include_files(sys/stat.h HAVE_SYS_STAT_H)
check_include_files(sys/time.h HAVE_SYS_TIME_H)
check_function_exists(uname HAVE_UNAME)
check_include_files(unistd.h HAVE_UNISTD_H)

#check_function_exists(sigsetmask HAVE_BSD_SIGNALS)
#made obsolete by sigprocmask(2). sigsetmask exists but the usage generates
#a variety of errors such as '... sv has incomplete type and cannot be defined'
#on linux.
#if needed in the future, see the old autoconf acinclude.m4 AC_DEFUN([BASH_SIGNAL_CHECK]
#For now, use only if don't have posix signals
if (NOT ${HAVE_POSIX_SIGNALS})
  set (HAVE_BSD_SIGNALS 1)
else()
  set(HAVE_BSD_SIGNALS 0)
endif()

set(CONFTEST_RETSIGTYPE "
/* end confdefs.h.  */
#include <sys/types.h>
#include <signal.h>

int main () {
  return *(signal (0, 0)) (0) == 1;
}
")
file(WRITE ${CMAKE_CURRENT_SOURCE_DIR}/conftest.c ${CONFTEST_RETSIGTYPE})
try_compile(RESULT_VAR ${CMAKE_CURRENT_SOURCE_DIR} 
  ${CMAKE_CURRENT_SOURCE_DIR}/conftest.c)
if(${RESULT_VAR})
  set(RETSIGTYPE int)
else()
  set(RETSIGTYPE void)
endif()

file(REMOVE "conftest.c")
have_type(sys/types.h gid_t int gid_t)
have_type(sys/types.h off_t "long int" off_t)
have_type(sys/types.h pid_t int pid_t)
have_type(sys/types.h size_t "unsigned int" size_t)
have_type(sys/types.h uid_t int uid_t)


if(${CMAKE_SYSTEM_NAME} MATCHES "CYGWIN")
  set(CYGWIN 1)
endif()

# generate file with version number from git and nrnunits.lib file path
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
   ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/include/
  DESTINATION include)

add_subdirectory(src/bin/)
add_subdirectory(src/lib)


install(EXPORT iv NAMESPACE iv_ DESTINATION share/cmake/iv)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/iv-config.cmake
  DESTINATION share/cmake/iv/
)
