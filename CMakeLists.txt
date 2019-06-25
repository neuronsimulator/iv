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


set(IV_BUILD_SHARED OFF CACHE BOOL "Build libraries shared or static" FORCE)


# =============================================================================
# Compile static libraries with hidden visibility
# =============================================================================
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

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
check_include_files(math.h HAVE_MATH_H)

# generate file with version number from git and nrnunits.lib file path
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
#   ${CMAKE_CURRENT_SOURCE_DIR}/config.hh)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/include/
  DESTINATION include)

add_subdirectory(src/bin/)
add_subdirectory(src/lib)
#add_subdirectory(src/include)
