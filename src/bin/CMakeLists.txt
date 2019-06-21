# =============================================================================
# idemo
# =============================================================================
set(IDEMO_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/idemo/main.cpp)
add_executable(idemo ${IDEMO_SOURCE_FILES})
target_link_libraries(idemo interviews ${X11_LIBRARIES})
install(TARGETS idemo DESTINATION bin)

# =============================================================================
# iclass
# =============================================================================
set(ICLASS_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/classbuffer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/classeditor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/classinfo.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/dialogs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/direct.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/globals.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/iclass.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iclass/main.cpp)

if(NOT BUILD_UNDER_WINDOWS)
  add_executable(iclass ${ICLASS_SOURCE_FILES})
  target_include_directories(iclass BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/src/include/IV-2_6)
  set_source_files_properties(${ICLASS_SOURCE_FILES} PROPERTIES COMPILE_FLAGS "-Div2_6_compatible")
  target_link_libraries(iclass unidraw interviews ${X11_LIBRARIES})
endif()

# =============================================================================
# idraw
# =============================================================================
set(IDRAW_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idarrow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idarrowhead.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idarrows.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idcatalog.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idcmds.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idcomp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idcreator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/iddialogs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/ided.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idkybd.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/idvars.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/idraw/main.cpp)

if(NOT BUILD_UNDER_WINDOWS)
  add_executable(idraw ${IDRAW_SOURCE_FILES})
  target_include_directories(idraw BEFORE PUBLIC ${PROJECT_SOURCE_DIR}/src/include/IV-2_6)
  set_source_files_properties(${IDRAW_SOURCE_FILES} PROPERTIES COMPILE_FLAGS "-Div2_6_compatible")
  target_link_libraries(idraw unidraw interviews ${X11_LIBRARIES})
endif()

# =============================================================================
# Install various targets
# =============================================================================
if(NOT BUILD_UNDER_WINDOWS)
  install(TARGETS iclass DESTINATION bin)
  install(TARGETS idraw DESTINATION bin)
endif()
