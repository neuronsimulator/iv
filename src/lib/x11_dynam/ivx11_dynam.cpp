extern "C" {

/* all X11 structures, declarations, etc. */
#define XUTIL_DEFINE_FUNCTIONS
#include <X11/Xlib.h>
#include <X11/Xutil.h>

/* just the pointer definitions corresponding to all extern X globals. */
#include <ivx11_define.h>

void ivx11_dyload() {
  /* assign the X globals to the pointers */
  #include <ivx11_assign.h>
}

} /* extern "C" */
