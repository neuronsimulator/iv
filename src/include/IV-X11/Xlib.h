/*
 * Copyright (c) 1987, 1988, 1989, 1990, 1991 Stanford University
 * Copyright (c) 1991 Silicon Graphics, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and 
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Stanford and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Stanford and Silicon Graphics.
 * 
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  
 *
 * IN NO EVENT SHALL STANFORD OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF 
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE 
 * OF THIS SOFTWARE.
 */

/*
 * C++ interface to standard Xlib.h.
 */

#ifndef InterViews_Xlib_h
#define InterViews_Xlib_h

extern "C" {

#ifdef AIXV3
struct _XDisplay;
struct _XFreeFuncs;
struct _XSQEvent;
struct _XExten;
struct _XKeytrans;
struct _XDisplayAtoms;
struct _XContextDB;
struct _XIMFilter;
struct _XrmHashBucketRec;
#endif

#ifdef __DECCXX
struct _XDisplay;
struct _XPrivate;
struct _XrmHashBucketRec;
#endif

#include <IV-X11/Xdefs.h>
#if defined(IVX11_DYNAM)
#include <IV-X11/ivx11_declare.h>
#include <IV-X11/ivx11_redef.h>
#else
#include <X11/Xlib.h>
#endif
#include <IV-X11/Xundefs.h>

}

#endif
