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

#ifndef dp_iohandler_h
#define dp_iohandler_h

#include <Dispatch/enter-scope.h>
#include <OS/types.h>

// Derived classes read input on a file number, write output on a file
// number, handle an exception raised on a file number, or handle a
// timer's expiration.

#if (defined(_WIN32) || MAC) && 0
typedef int pid_t;
#endif

class IOHandler {
protected:
    IOHandler();
public:
    virtual ~IOHandler();

    virtual int inputReady(int fd);
    virtual int outputReady(int fd);
    virtual int exceptionRaised(int fd);
    virtual void timerExpired(long sec, long usec);
    virtual void childStatus(pid_t pid, int status);
};

#endif
