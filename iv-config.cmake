# iv-config.cmake - package configuration file

get_filename_component(CONFIG_PATH "${CMAKE_CURRENT_LIST_FILE}" PATH)

find_path(iv_INCLUDE "ivversion.h" HINTS "${CONFIG_PATH}/../../../include")
find_path(iv_LIB NAMES libinterviews.a libinterviews.so libinterviews.dylib HINTS "${CONFIG_PATH}/../../../lib")

include(${CONFIG_PATH}/iv.cmake)
