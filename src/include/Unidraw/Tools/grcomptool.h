/*
 * Copyright (c) 1990, 1991 Stanford University
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Stanford not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  Stanford makes no representations about
 * the suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * STANFORD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
 * IN NO EVENT SHALL STANFORD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Graphic component tool declarations.
 */

#ifndef unidraw_tools_grcomptool_h
#define unidraw_tools_grcomptool_h

#include <Unidraw/Tools/tool.h>

class Command;
class GraphicComp;
class GraphicView;

class GraphicCompTool : public Tool {
public:
    GraphicCompTool();
    GraphicCompTool(ControlInfo*, GraphicComp* prototype);
    virtual ~GraphicCompTool();

    virtual Manipulator* CreateManipulator(Viewer*, Event&, Transformer* =nil);
    virtual Command* InterpretManipulator(Manipulator*);

    GraphicComp* GetPrototype();

    virtual Tool* Copy();
    virtual void Read(std::istream&);
    virtual void Write(std::ostream&);
    virtual ClassId GetClassId();
    virtual bool IsA(ClassId);
private:
    void Init(GraphicComp*);
private:
    GraphicComp* _prototype;
    GraphicView* _protoview;
};

inline GraphicComp* GraphicCompTool::GetPrototype () { return _prototype; }

#endif
