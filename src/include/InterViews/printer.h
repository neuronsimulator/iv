/*
 * Copyright (c) 1990, 1991 Stanford University
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
 * Printer - generate output for a printer
 */

#ifndef iv_printer_h
#define iv_printer_h

#include <InterViews/canvas.h>
#include <ivstream.h>

class PrinterRep;

class Printer : public Canvas {
public:
    Printer(std::ostream*);
	 virtual ~Printer();

	 virtual PixelCoord to_pixels(Coord, DimensionName) const;
	 virtual Coord to_coord(PixelCoord, DimensionName) const;
	 virtual Coord to_pixels_coord(Coord, DimensionName) const;

#if defined(_WIN32) || defined(MAC)
	 virtual void size(Coord width, Coord height);
	 virtual void psize(PixelCoord width, PixelCoord height);

	 virtual Coord width() const;
	 virtual Coord height() const;
	 virtual PixelCoord pwidth() const;
	 virtual PixelCoord pheight() const;

	 virtual void transformer(const Transformer&);
	 virtual const Transformer& transformer() const;

    virtual void damage(const Extension&);
	 virtual void damage(Coord left, Coord bottom, Coord right, Coord top);
	 virtual bool damaged(const Extension&) const;
    virtual bool damaged(
	Coord left, Coord bottom, Coord right, Coord top
	 ) const;
	 virtual void damage_area(Extension&);
	 virtual void damage_all();
	 virtual bool any_damage() const;
	 virtual void restrict_damage(const Extension&);
    virtual void restrict_damage(
		Coord left, Coord bottom, Coord right, Coord top
	 );

	 virtual void redraw(Coord left, Coord bottom, Coord right, Coord top);
    virtual void repair();

#endif

    virtual void resize(Coord left, Coord bottom, Coord right, Coord top);

    virtual void prolog(const char* creator = "InterViews");
    virtual void epilog();

    virtual void comment(const char*);
    virtual void page(const char*);

    virtual void push_transform();
    virtual void transform(const Transformer&);
    virtual void pop_transform();

#if defined(_WIN32) || MAC
    virtual void push_clipping(bool all = false);
#else
    virtual void push_clipping();
#endif
    virtual void clip();
    virtual void pop_clipping();

    virtual void new_path();
    virtual void move_to(Coord x, Coord y);
    virtual void line_to(Coord x, Coord y);
    virtual void curve_to(
        Coord x, Coord y, Coord x1, Coord y1, Coord x2, Coord y2
    );
    virtual void close_path();
    virtual void stroke(const Color*, const Brush*);
    virtual void fill(const Color*);

    virtual void character(
        const Font*, long c, Coord width, const Color*, Coord x, Coord y
    );
    virtual void stencil(const Bitmap*, const Color*, Coord x, Coord y);
    virtual void image(const Raster*, Coord x, Coord y);
protected:
    virtual void flush();
private:
    PrinterRep* rep_;
};

#endif
