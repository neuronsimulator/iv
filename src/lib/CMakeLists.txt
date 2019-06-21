
set(DISPATCH_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Dispatch/dispatcher.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Dispatch/iohandler.cpp)

set(IV26_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/adjuster2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/banner.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/border2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/box2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/button2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/compeditor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/control.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/deck2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/dialog2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/filebrowser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/filechooser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/frame.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/glue2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/interactor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/matcheditor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/menu2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/message.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/painter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/panner2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/perspective.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/rubband.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/rubcurve.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/rubgroup.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/rubline.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/rubrect.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/rubverts.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/scene.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/scrollbar2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/scroller2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/sensor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/shape.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/strbrowser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/strchooser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/streditor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/subject.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/textbuffer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/textdisplay.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/texteditor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/tform2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/tray.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/viewport.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/world.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/xbitmap2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/xevent2_6.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/xinter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/xpainter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-2_6/xpattern.cpp)


set(INTERVIEWS_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/InterViews/dialogs.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/action.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/adjust.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/aggr.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/align.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/alloctbl.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/arrcomp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/background.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/bevel.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/border.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/box.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/browser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/button.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/character.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/compositor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/comption.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/debug.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/deck.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/fbrowser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/fchooser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/field.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/geometry.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/glyph.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/group.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/handler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/hit.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/image.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/input.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/kit.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/label.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/layout.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/lrmarker.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/menu.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/mf_dialogs.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/mf_kit.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/mono_kit.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/monoglyph.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/observe.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/ol_dialogs.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/page.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/patch.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/place.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/polyglyph.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/printer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/psfont.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/regexp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/resource.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/rule.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/scrbox.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/shadow.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/simpcomp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/slider.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/smf_kit.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/stencil.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/stepper.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/style.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/superpose.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/target.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/telltale.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/texcomp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/iv3text.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/iv3textbuffer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/tformsetter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/tile.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/transformer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/winbmp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InterViews/xymarker.cpp)


if (NOT WIN32)
  list(APPEND INTERVIEWS_SOURCE_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/InterViews/ol_kit.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/InterViews/tiff.cpp)
endif()


set (IVX11_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/session.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xbitmap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xbrush.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xcanvas.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xcolor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xcursor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xdrag.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xevent.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xfont.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xraster.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xreqerr.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xselection.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-X11/xwindow.cpp)

set (OS_SOURCE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/OS/directory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/file.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/host.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/listimpl.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/math.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/memory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/string.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OS/ustring.cpp)

set(TIFF_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_aux.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_ccittrle.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_close.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_cmprs.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_compat.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_dir.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_dirinfo.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_dirread.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_dirwrite.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_dumpmode.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_error.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_fax3.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_fax4.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_flush.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_getimage.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_jpeg.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_lzw.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_machdep.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_next.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_open.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_packbits.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_print.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_read.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_strip.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_swab.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_thunder.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_tile.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_version.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_warning.c
	${CMAKE_CURRENT_SOURCE_DIR}/TIFF/tif_write.c)

set(IVWIN_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/bitmap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/brush.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/canvas.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/canvas16.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/color.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/cursor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/display.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/event.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/font.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/ivclean.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/mprinter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/mwapp.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/mwlib.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/raster.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/session.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Win/window.cpp)

set(IVMAC_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/bitmap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/brush.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/canvas.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/color.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/cursor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/display.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/event.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/carbevent.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/font.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/mprinter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/raster.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/session.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IV-Mac/window.cpp)


# =============================================================================
# IV  library
# =============================================================================

set(INTERVIEWS_LINUX_SOURCES 
  ${DISPATCH_SOURCE_FILES} 
  ${IV26_SOURCE_FILES}
  ${INTERVIEWS_SOURCE_FILES}
  ${TIFF_SOURCE_FILES}
  ${OS_SOURCE_FILES}
  ${IVX11_SOURCE_FILES})

set(INTERVIEWS_WIN_SOURCES 
  ${INTERVIEWS_SOURCE_FILES}
  ${TIFF_SOURCE_FILES}
  ${OS_SOURCE_FILES}
  ${IVWIN_SOURCE_FILES}
  )
  
if (WIN32)
  set(SOURCES ${INTERVIEWS_WIN_SOURCES})
else()
  set(SOURCES ${INTERVIEWS_LINUX_SOURCES})
endif()

if (${IV_BUILD_SHARED})
  add_library(interviews SHARED ${SOURCES})
else()
  add_library(interviews STATIC ${SOURCES})
endif()

set(KIT_DEFINES "-Dmotif_kit -Dsgi_motif_kit -Dopenlook_kit -Dbw_kit -Ddefault_kit=SMFKit")
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/InterViews/dialogs.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/InterViews/kit.cpp
  PROPERTIES COMPILE_FLAGS ${KIT_DEFINES})

target_include_directories(interviews PUBLIC ${X11_INCLUDE_DIR})
