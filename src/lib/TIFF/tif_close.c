#ifdef HAVE_CONFIG_H
#include <../../config.h>
#endif
#ifndef lint
static char rcsid[] = "/local/src/master/iv/src/lib/TIFF/tif_close.c,v 1.2 1997/03/26 15:07:03 hines Exp";
#endif

/*
 * Copyright (c) 1988, 1989, 1990, 1991, 1992 Sam Leffler
 * Copyright (c) 1991, 1992 Silicon Graphics, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and 
 * its documentation for any purpose is hereby granted without fee, provided
 * that (i) the above copyright notices and this permission notice appear in
 * all copies of the software and related documentation, and (ii) the names of
 * Sam Leffler and Silicon Graphics may not be used in any advertising or
 * publicity relating to the software without the specific, prior written
 * permission of Sam Leffler and Silicon Graphics.
 * 
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY 
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.  
 * 
 * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR
 * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF 
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE 
 * OF THIS SOFTWARE.
 */

/*
 * TIFF Library.
 */
#include <unistd.h>
#include "tiffioP.h"

#if USE_PROTOTYPES
extern	int TIFFFreeDirectory(TIFF*);
#else
extern	int TIFFFreeDirectory();
#endif

void
TIFFClose(
	TIFF *tif
)
{
	if (tif->tif_mode != O_RDONLY)
		/*
		 * Flush buffered data and directory (if dirty).
		 */
		TIFFFlush(tif);
	if (tif->tif_cleanup)
		(*tif->tif_cleanup)(tif);
	TIFFFreeDirectory(tif);
	if (tif->tif_rawdata && (tif->tif_flags&TIFF_MYBUFFER))
		free(tif->tif_rawdata);
#ifdef MMAP_SUPPORT
	if (isMapped(tif))
		TIFFUnmapFileContents(tif->tif_base, tif->tif_size);
#endif
	(void) close(tif->tif_fd);
	free((char *)tif);
}
